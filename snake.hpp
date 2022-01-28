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
	SDL_Rect rect[];
	

Head(int posX, int posY, int score)
{
	
    this->rect[score] = {posX,posY, SNAKE, SNAKE};
   
}
void makerect(int posX, int posY, int score)
{
	SDL_Rect *array = new SDL_Rect[score];
    this->rect[score] = {posX,posY, SNAKE,SNAKE};
}
void update()
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );
    lastmove = move;
	// Player input.
	if ( keystates[SDL_SCANCODE_UP] ) {	
	move = 'U';	
	}
	if ( keystates[SDL_SCANCODE_DOWN] ) {
	move = 'D';
	}
		if ( keystates[SDL_SCANCODE_LEFT] ) {
	move = 'L';
	}
		if ( keystates[SDL_SCANCODE_RIGHT] ) {
	move = 'R';
	}
}
void moving (Pos &pos)
{

switch (move){
	case 'U': 
           while (!pos.posY%SNAKE)
    {
        if (lastmove =='L')
        pos.posX--;
        else if (lastmove == 'R')
        pos.posX++;
    }
	pos.posY--;
	if (pos.posY <= 0)
	{
		pos.posY=0;
	}
	break;
	case 'D': 
        while (!pos.posY%SNAKE)
    {
        if (lastmove =='L')
        pos.posX--;
        else if (lastmove == 'R')
        pos.posX++;
    }
	pos.posY++;
	if (pos.posY >= (SCREEN_HEIGHT-SNAKE))
	{
		pos.posY=(SCREEN_HEIGHT-SNAKE);
	}
	break;
	case 'L': 
        while (!pos.posY%SNAKE)
    {
        if (lastmove =='U')
        pos.posY--;
        else if (lastmove == 'D')
        pos.posY++;
    }
	pos.posX--;
		if (pos.posX <= 0)
	{
		pos.posX=0;
	}
	break;
	case 'R': 
    while (!pos.posY%SNAKE)
    {
        if (lastmove =='U')
        pos.posY--;
        else if (lastmove == 'D')
        pos.posY++;
    }
    
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