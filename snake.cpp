#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "snake.h"

SDL_Window* window;
SDL_Renderer* renderer;//Déclaration du renderer
int posX = 500;
int posY = 500;

int  init( void );
void update( void );

int main(int argc, char *argv[])
{
	int i;
	const Uint8* keystates = SDL_GetKeyboardState( 0 );

	int initCode = init();
	if ( initCode )
		return initCode;
	bool closeRequest = false;
	SDL_Event e;

	Uint32 frameStart, frameTime, frameDelay = 20;
	while ( !closeRequest )
	{
		frameStart = SDL_GetTicks();

		// Poll window events.
		while ( SDL_PollEvent(&e) != 0 )
		{
			if ( e.type == SDL_QUIT ) {
				closeRequest = true;
			}
			else if ( e.type == SDL_KEYDOWN ) {
				switch ( e.key.keysym.sym ) {
				case SDLK_ESCAPE:
					closeRequest = true;
					break;
				}
			}
		}
update();
SDL_SetRenderDrawColor(renderer,255,255,255,255); //Couleur blanche
SDL_Rect rectangle = {posX,posY,25,25};
SDL_RenderFillRect(renderer, &rectangle);
SDL_Delay(5);
SDL_RenderPresent(renderer);
SDL_Delay(5);
SDL_SetRenderDrawColor(renderer,0,0,0,255);
SDL_RenderClear(renderer);

	}
   






SDL_Delay(3000);//pause de 3 secondes

// Destruction du renderer et de la fenêtre :
SDL_DestroyRenderer(renderer); 
SDL_DestroyWindow(window);
	
}


int init( void )
{
	// Initialize SDL.
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL init failed.\n" );
		return 1;
	}

	// Create the SDL window.
	window = SDL_CreateWindow(
		"Snake.",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1000, 1000,
		SDL_WINDOW_SHOWN );

	if ( !window )
	{
		printf( "SDL window creation failed.\n" );
		return 2;
	}

	// Create renderer for window.
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	/*int centerY = (SCREEN_HEIGHT - PLAYER_HEIGHT) / 2;
	player1.posY = centerY;
	player2.posY = centerY;
	player1.score = 0;
	player2.score = 0;

	ball_init( &ball, 3, 3 );*/

	return 0;
}

void update( void )
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );

	// Player input.
	if ( keystates[SDL_SCANCODE_UP] ) {	
	posY--;
	}
	if ( keystates[SDL_SCANCODE_DOWN] ) {
	posY++;
	}
		if ( keystates[SDL_SCANCODE_LEFT] ) {
	posX--;	
	}
		if ( keystates[SDL_SCANCODE_RIGHT] ) {
	posX++;	
	}
}
