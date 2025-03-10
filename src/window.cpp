// window.cpp
#include "window.hpp"
#include <iostream>


window::window()
    : m_window(nullptr)
    , m_window_surface(nullptr)
    , renderimg(nullptr)
    ,Figure(nullptr)
    ,grass(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cerr << "SDL FAILED TO LOAD \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "IMG_Init Has failed \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window = SDL_CreateWindow(TITLE,
     SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
       WIDTH, HEIGHT,
        SDL_WINDOW_OPENGL);

    if (!m_window) {
        std::cerr << "Failed to create window\n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    renderimg = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderimg) {
        std::cerr << "Failed to CreateRender \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
    }

    Figure=(renderimg);
    grass={renderimg};
}

void window::background(){
    skytexture = IMG_LoadTexture(renderimg,"gfx/background/sky2.png");
    SDL_RenderCopy(renderimg,skytexture,NULL,NULL);
}

window::~window() {
    Figure.cleanup();
    grass.groundcleanup();
    SDL_DestroyTexture(skytexture); 
    SDL_DestroyRenderer(renderimg);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
}



void window::loop() {
    bool keep_window_open = true;
    while (keep_window_open) {
        while (SDL_PollEvent(&m_window_event) > 0) {
            Figure.handle_events(m_window_event);
            switch (m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }
        update(1.0 / 60.0);
        draw();
    }
}

void window::update(double delta_time) {
    Figure.update(delta_time);
}

void window::draw() { 
    SDL_RenderClear(renderimg);
    
    background();
    for (int i = -25; i <= 825; i+=100){
    grass.draw(i,HEIGHT - grass.grassheight);
    }
    Figure.draw();
    


    SDL_RenderPresent(renderimg);
    SDL_DestroyTexture(skytexture);
    // Figure.cleanup();
}