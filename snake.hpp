#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 1000
#define SNAKE  25

class Head
{
    private :
    

    public:
    SDL_Rect rect;
    int posX;
    int posY;
    char move;
    char lastmove;

Head(int posX, int posY)
{
    this->posX = SCREEN_WIDTH/2;
    this->posY = SCREEN_HEIGHT/2;
    this->rect = {posX,posY, SNAKE, SNAKE};
   
}
void makerect()
{
    this->rect = {posX,posY, SNAKE,SNAKE};
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
void moving ()
{

switch (move){
	case 'U': 
           while (!posY%SNAKE)
    {
        if (lastmove =='L')
        posX--;
        else if (lastmove == 'R')
        posX++;
    }
	posY--;
	if (posY <= 0)
	{
		posY=0;
	}
	break;
	case 'D': 
        while (!posY%SNAKE)
    {
        if (lastmove =='L')
        posX--;
        else if (lastmove == 'R')
        posX++;
    }
	posY++;
	if (posY >= (SCREEN_HEIGHT-SNAKE))
	{
		posY=(SCREEN_HEIGHT-SNAKE);
	}
	break;
	case 'L': 
        while (!posY%SNAKE)
    {
        if (lastmove =='U')
        posY--;
        else if (lastmove == 'D')
        posY++;
    }
	posX--;
		if (posX <= 0)
	{
		posX=0;
	}
	break;
	case 'R': 
    while (!posY%SNAKE)
    {
        if (lastmove =='U')
        posY--;
        else if (lastmove == 'D')
        posY++;
    }
    
	posX++;
		if (posX >= (SCREEN_WIDTH-SNAKE))
	{
		posX=(SCREEN_WIDTH-SNAKE);
	}
	break;
}
}
};


#endif // SNAKE_SNAKE_H