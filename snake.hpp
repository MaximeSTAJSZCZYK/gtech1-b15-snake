#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SDL2/SDL.h>
#include <vector>
#include "pos.hpp"
using namespace std;


#define SNAKE  25

class Head
{
    private :

    public:
    char move;
    char lastmove;

Head(int posX, int posY, int score)
{  
}

void update(Pos &pos)
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );
    lastmove = move;
	// Player input.

		if ( keystates[SDL_SCANCODE_UP]  && pos.posX%SNAKE == 0) {	
			if (lastmove == 'D'){}	
			else {
				move = 'U';
			} 	
		}
		if ( keystates[SDL_SCANCODE_DOWN] && pos.posX%SNAKE == 0) {
			if (lastmove == 'U'){}	
			else {
				move = 'D';
			} 
		}
		if ( keystates[SDL_SCANCODE_LEFT] && pos.posY%SNAKE == 0) {
				if (lastmove == 'R'){}	
			else {
				move = 'L';
			} 
		}
		if ( keystates[SDL_SCANCODE_RIGHT] && pos.posY%SNAKE == 0) {
				if (lastmove == 'L'){}	
			else {
				move = 'R';
			} 
		}
	
}
void moving (Pos &pos)
{

switch (move){
	case 'U': 
	pos.posY--;
	if (pos.posY <= 0)
	{
		pos.posY=0;
	}
	break;
	case 'D': 
	pos.posY++;
	if (pos.posY >= (SCREEN_HEIGHT-SNAKE))
	{
		pos.posY=(SCREEN_HEIGHT-SNAKE);
	}
	break;
	case 'L': 
	pos.posX--;
		if (pos.posX <= 0)
	{
		pos.posX=0;
	}
	break;
	case 'R':  
	pos.posX++;
		if (pos.posX >= (SCREEN_WIDTH-SNAKE))
	{
		pos.posX=(SCREEN_WIDTH-SNAKE);
	}
	break;
}

}


};


#endif // SNAKE_SNAKE_H