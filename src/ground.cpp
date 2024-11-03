#include "ground.hpp"
#include <iostream>

Ground::Ground(SDL_Renderer *_display):
p_displayer(_display)
,_destination{302,250,100,100}
{
    
    g_texture = IMG_LoadTexture(p_displayer,"gfx/background/ground_grass-2-removebg-preview.png");
    
    // g_texture = SDL_CreateTextureFromSurface(renderer, surface);
    // SDL_SetTextureBlendMode(g_texture,SDL_BLENDMODE_MOD);
  
    // _destination.x=*x;
    // _destination.y=*y;

}

void Ground::draw(int x,int y){
    _destination={x,y,100,100};
    
    SDL_RenderCopy(p_displayer,g_texture,NULL,&_destination);
}

void Ground::groundcleanup(){
    SDL_DestroyTexture(g_texture);
}