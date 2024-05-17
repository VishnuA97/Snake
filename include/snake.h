#ifndef SNAKE_H
#define SNAKE_H

#include "SDL2/SDL.h"

class snake{
    public:
        
        void snake_head(SDL_Renderer *renderer);
        void snake_segment(SDL_Renderer *renderer, int x, int y);
        void movement();
        void grow();
};

#endif