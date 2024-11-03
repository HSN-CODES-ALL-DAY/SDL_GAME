#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class StickFigure
{
public:
    StickFigure(SDL_Renderer *__renderstick);
    ~StickFigure() = default;

    void update(double delta_time);
    void draw();
    void handle_events(SDL_Event const &event);
    void cleanup();
    enum class Direction{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
private:
    SDL_Renderer *figure;
    Direction    m_direction;
    SDL_Texture *m_image;
    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
    double angle;
    SDL_RendererFlip fliper();
    bool dir;
};