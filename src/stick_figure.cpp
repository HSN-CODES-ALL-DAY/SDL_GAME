#include "stick_figure.hpp"
#include <iostream>
#include "window.hpp"
#include <png.h>




StickFigure::StickFigure(SDL_Renderer *__renderstick):figure(__renderstick)
{

    m_image = IMG_LoadTexture(figure,"gfx/characters/Stick_figure-removebg-preview.png");


    m_position.x = 0;
    m_position.y = 0;   
    m_position.w = 100;
    m_position.h = 200;
    
    m_x = 200.0;
    m_y = 200.0;
    angle = 0;
}


void StickFigure::update(double delta_time)
{
switch(m_direction)

    {        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            break;
        case Direction::UP:
            m_y = m_y - (20 * delta_time);
            // angle +=  0.45;
            break;
        case Direction::DOWN:
            m_y = m_y + (20 * delta_time);
            break;
        case Direction::LEFT:
            m_x = m_x - (20 * delta_time);
            break;
        case Direction::RIGHT:
            m_x = m_x + (20 * delta_time);
            break;
    }

    m_position.x = (int)m_x;
    m_position.y = (int)m_y;
    if(m_y<(HEIGHT - 100 - 150))
    m_y +=GRAVITY*delta_time;
    // std::cout << "\rPosition X: " << m_position.x <<' ';
    // std::cout << "Position Y: " << m_position.y <<' ' ;
    // std::cout.flush();
}

void StickFigure::cleanup(){
    SDL_DestroyTexture(m_image); 
}

SDL_RendererFlip StickFigure::fliper(){
    
    if(m_direction==Direction::LEFT){
        dir = 0;
        return SDL_FLIP_HORIZONTAL;  
    }  
    if(m_direction==Direction::RIGHT){
    dir = 1;
    return SDL_FLIP_NONE;
    }
    if(dir==1){
        return SDL_FLIP_NONE;
    }
    if(dir==0){
        return SDL_FLIP_HORIZONTAL;
    }
    return SDL_FLIP_NONE;
}

void StickFigure::draw()
{
    // SDL_RenderCopy(figure,m_image,NULL,&m_position);
    
    // m_image = IMG_LoadTexture(figure,"gfx/characters/Stick_figure.png");
    
    SDL_RenderCopyEx(figure, m_image, NULL, &m_position, angle, NULL, fliper());

}

void StickFigure::handle_events(SDL_Event const &event){
     if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) 
{
        Uint8 const *keys = SDL_GetKeyboardState(nullptr);

        if(keys[SDL_SCANCODE_W] == 1)
            m_direction = Direction::UP;
        else if(keys[SDL_SCANCODE_S] == 1)
            m_direction = Direction::DOWN;
        else if(keys[SDL_SCANCODE_A] == 1)
            m_direction = Direction::LEFT;
        else if(keys[SDL_SCANCODE_D] == 1)
            m_direction = Direction::RIGHT;
        else 
            m_direction = Direction::NONE;
}
        if (angle >= 360.0) angle -= 360.0;
        
}