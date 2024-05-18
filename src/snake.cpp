#include "snake.h"

void snake :: snake_head(SDL_Renderer *renderer){
    
    SDL_Rect head = {30, 420, 10, 10};
	SDL_RenderFillRect ( renderer, &head );
}

void snake :: snake_segment(SDL_Renderer *renderer, int x, int y){
    SDL_Rect seg = {x, y, 10, 10};
	SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );
	SDL_RenderFillRect ( renderer, &seg );
}

void snake :: movement(){

}

void snake :: grow(){
    
}