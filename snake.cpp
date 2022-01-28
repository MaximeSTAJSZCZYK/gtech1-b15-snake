#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;	

#include "snake.hpp"
#include "fruit.hpp"
#include "pos.hpp"

SDL_Window* window;
SDL_Renderer* renderer;//Déclaration du renderer


int score = 0; 
int  init( void );
bool check_collision( SDL_Rect &A, SDL_Rect &B );
void render(void);
Fruit fruit(0,0);
vector<Pos> pos;
Head head(SCREEN_WIDTH/2, SCREEN_HEIGHT/2,score );


int main()
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );
	int initCode = init();
	if ( initCode )
		return initCode;
	bool closeRequest = false;
	SDL_Event e;
	pos.push_back(Pos(500,500));
	Uint32 frameStart, frameTime, frameDelay = 60;
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
	



	
if (check_collision(head.rect[0], fruit.fruit))
{
	fruit.fruitX=0;
	fruit.fruitY=0;
	score++;

}
if (fruit.fruitX == 0 && fruit.fruitY == 0)
{
srand (time(NULL));
fruit.fruitX = rand() % SCREEN_WIDTH + 1;
fruit.fruitY = rand() % SCREEN_HEIGHT + 1;
}	
head.update();
head.moving(pos[0]);

render();
for (int i = 1; i < score; i++)
{
	pos.push_back(Pos(pos[0].posX,pos[0].posY));
}
for (int j = score; j!= 0; j--)
{
	pos[j].posX = pos[j-1].posX;
	pos[j].posY = pos[j-1].posY;
}
}
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
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN );

	if ( !window )
	{
		printf( "SDL window creation failed.\n" );
		return 2;
	}

	// Create renderer for window.
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	return 0;
}



void render ()
{
SDL_SetRenderDrawColor(renderer,255,255,255,255); //Couleur blanche
fruit.makerectfruit();

head.makerect(pos[0].posX, pos[0].posY, 0);
SDL_RenderFillRect(renderer, &head.rect[0]);

for (int i = 0; i < score; i++)
{
	head.makerect(pos[score].posX, pos[score].posY, score);
	SDL_RenderFillRect(renderer, &head.rect[score]);
}


SDL_SetRenderDrawColor(renderer,0,255,0,255); //Couleur blanche
SDL_RenderFillRect(renderer, &fruit.fruit);
SDL_Delay(5);
SDL_RenderPresent(renderer);
SDL_Delay(5);
SDL_SetRenderDrawColor(renderer,0,0,0,255);
SDL_RenderClear(renderer);
}

bool check_collision( SDL_Rect &A, SDL_Rect &B )
{
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    //Calcul les cotes du rectangle A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
 
    //Calcul les cotes du rectangle B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
	    //Tests de collision
    if( bottomA <= topB )
    {
        return false;
    }
 
    if( topA >= bottomB )
    {
        return false;
    }
 
    if( rightA <= leftB )
    {
        return false;
    }
 
    if( leftA >= rightB )
    {
        return false;
    }
 
    //Si conditions collision detectee
    return true;
}