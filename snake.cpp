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
#include "text.hpp"

SDL_Window* window;
SDL_Renderer* renderer;//Déclaration du renderer


int score = 0; 
int verif = 0;
int  init( void );
bool check_collision( SDL_Rect &A, SDL_Rect &B );
void render(void);
int makefruitrand(void);
Fruit fruit(0,0);
vector<Pos> pos;
vector<Text> text;
Head head(SCREEN_WIDTH/2, SCREEN_HEIGHT/2,score );
    
int snake[5][50] = {
                    {0,1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1},
                    {1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1},
                    {0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,1,0,1},
                    {0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0},
                    {1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1}}; 

int row; 
int column;


int main()
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );
	int initCode = init();
	bool closeRequest = false;
	SDL_Event e;
	pos.push_back(Pos(500,500,score));
	
	Uint32 frameStart, frameTime, frameDelay = 5;

	if ( initCode )
		return initCode;

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
	
row = sizeof(snake)/sizeof(snake[0]);
column = sizeof(snake[0])/row;

	for (int i = 0; i < row; i++)
	{
		text.push_back(Text(snake[i]));
	}
	


for (int j = 0; j < row; j++)
{
	   for (int k = 0; k < sizeof(text[j].row); k++) {
	   
    if(text[j].row[k] == 1){
        SDL_SetRenderDrawColor(renderer,50,200,50,0);
        SDL_Rect rect = {SCREEN_WIDTH/10+(k*20),SCREEN_HEIGHT/10+(j*20),20,20};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}




head.update(pos[0]);
head.moving(pos[0]);

render();
makefruitrand();




for (int i = (SNAKE*2); i < score; i++)
{
	if(check_collision(pos[0].rect, pos[i].rect))
	{
	//printf("collusion with snake\n");
	}
}
	frameTime = SDL_GetTicks() - frameStart;
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
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

pos[0].makerect(pos[0].posX, pos[0].posY, 0);
SDL_RenderFillRect(renderer, &pos[0].rect);

for (int i = 1; i < score; i++)
{
	pos.push_back(Pos(pos[i].posX,pos[i].posY,i));
}


for (int j = score; j!= 0; j--)
{	
	pos[j].posX = pos[j-1].posX;
	pos[j].posY = pos[j-1].posY;
}

for (int k = 1; k < score; k++)
{
	pos[k].makerect(pos[k].posX, pos[k].posY, k);
	SDL_RenderFillRect(renderer, &pos[k].rect);
}


SDL_SetRenderDrawColor(renderer,0,255,0,255); //Couleur blanche
SDL_RenderFillRect(renderer, &fruit.fruit);
//SDL_Delay(1);
SDL_RenderPresent(renderer);
//SDL_Delay(5);
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
int makefruitrand(void)
{
	
if ((fruit.fruitX == 0 && fruit.fruitY == 0) )
{
	printf("new fruit\n");
srand (time(NULL));
fruit.fruitX = rand() % (SCREEN_WIDTH-SNAKE) + SNAKE;
fruit.fruitY = rand() % (SCREEN_HEIGHT-SNAKE) + SNAKE;

}	
	
if (check_collision(pos[0].rect, fruit.fruit))
{

	score+= 25;
	verif++;

}
for (int j = 0; j < score; j++)
{
	
	if (check_collision(pos[j].rect,fruit.fruit) == 1) {
		//printf("fruit dans snake\n");
		//printf("%d/%d : %d/%d\n",pos[j].posX,pos[j].posY,fruit.fruitX,fruit.fruitY);
		//cordnotgood = 1;
		
		fruit.fruitX = rand() % (SCREEN_WIDTH-SNAKE) + SNAKE;
		fruit.fruitY = rand() % (SCREEN_HEIGHT-SNAKE) + SNAKE;
		return 0;
	}

}

return 0;
}