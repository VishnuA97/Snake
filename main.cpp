#include "SDL2/SDL.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();

SDL_Window* Window = NULL;

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
		if( Window == NULL )
		{
			std::cerr << "Window could not be created! SDL_Error: \n" << SDL_GetError() << std::endl;
			success = false;
		}

	}
    return success;
}

void close(){

    SDL_DestroyWindow( Window );
	Window = NULL;

	SDL_Quit();

}


int main(int argc, char *argv[]){

    if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
    else{
        SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    }
    close();
    
    return 0;
}
