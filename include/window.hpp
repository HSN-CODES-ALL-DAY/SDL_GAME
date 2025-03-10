// window.hpp
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "stick_figure.hpp"
#include "ground.hpp"
const int WIDTH = 800;
const int HEIGHT = 600;
static const char *TITLE = "SDL_GAME";
const float GRAVITY = 5;

class window {
public:
    window();
    ~window();
    void loop();
    void update(double delta_time);
    void draw();
    void background();
    

private:
    Ground grass;
    SDL_Window *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event m_window_event;
    SDL_Texture *skytexture;
    SDL_Renderer *renderimg;
    StickFigure Figure;
    
};