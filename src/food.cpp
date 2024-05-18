#include "food.h"


void render_food(SDL_Renderer *renderer, int x, int y){
    SDL_Rect food = {x, y, 10, 10};
	SDL_RenderFillRect ( renderer, &food );

}