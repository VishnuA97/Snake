#include "SDL2/SDL.h"
#include "snake.h"
#include "food.h"
#include <iostream>
#include <cstdlib>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();



SDL_Window* Window = nullptr;
SDL_Renderer* renderer = nullptr;

bool init(){

    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cerr << "SDL could not initialize! SDL_Error: \n" << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
        Window = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( Window == nullptr )
		{
			std::cerr << "Window could not be created! SDL_Error: \n" << SDL_GetError() << std::endl;
			success = false;
		}
		else {
			renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED);
			if ( renderer == nullptr ){
				std::cerr << "Renderer could not be created! SDL_Error: \n" << SDL_GetError() << std::endl;
			}
			else{
				SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255);
				SDL_RenderClear( renderer );
				
			}
		}

	}
    return success;
}

void close(){

	SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( Window );
	Window = nullptr;
	renderer = nullptr;
	
	SDL_Quit();

}





int main(int argc, char *argv[]){

	SDL_Event e;
	bool running = true;

    if( !init() )
	{
		std::cout << "Failed to initialize!\n" << std::endl ;
	}

	else{
	
        while( running ){

			while ( SDL_PollEvent(&e ) ) {

				if( e.type == SDL_QUIT ){running = false;}
				
			}

			SDL_SetRenderDrawColor ( renderer, 0, 0, 0, 255);
			SDL_RenderClear ( renderer );

			SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );

			SDL_Rect border = {15, 15, 400, 445};
			SDL_RenderDrawRect ( renderer, &border );

			snake s;
			s.snake_head(renderer);
			render_food( renderer, 30, 380 );
			SDL_RenderPresent ( renderer );
		}
    }
	
    close();
    
    return 0;
}
