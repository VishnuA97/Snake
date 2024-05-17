#include "snake.h"

void snake :: snake_head(SDL_Renderer *renderer){
    
    SDL_Rect head = {30, 420, 20, 8};
	SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );
	SDL_RenderFillRect ( renderer, &head );
}

void snake :: snake_segment(SDL_Renderer *renderer, int x, int y){
    SDL_Rect head = {x, y, 20, 8};
	SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );
	SDL_RenderFillRect ( renderer, &head );
}

void snake :: movement(){

}

void snake :: grow(){
    
}