#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Ground{
    public:
    Ground(SDL_Renderer *_display);
    void draw(int x,int y);
    void groundcleanup();

    private:
    const int *x;
    const int *y;
    SDL_Texture *g_texture;
    SDL_Renderer *p_displayer;
    SDL_Rect _destination;
    
};