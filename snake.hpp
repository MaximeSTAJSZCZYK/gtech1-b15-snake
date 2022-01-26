#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 1000


class Head
{
    private :
    

    public:
    SDL_Rect rect;
    int posX;
    int posY;
    char move;

Head(int posX, int posY)
{
    this->posX = SCREEN_WIDTH/2;
    this->posY = SCREEN_HEIGHT/2;
    this->rect = {posX,posY,25,25};
   
}
void makerect()
{
    this->rect = {posX,posY,25,25};
}
void update()
{
	const Uint8* keystates = SDL_GetKeyboardState( 0 );

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
	posY--;
	if (posY <= 0)
	{
		posY=0;
	}
	break;
	case 'D': 
	posY++;
	if (posY >= (SCREEN_HEIGHT-25))
	{
		posY=(SCREEN_HEIGHT-25);
	}
	break;
	case 'L': 
	posX--;
		if (posX <= 0)
	{
		posX=0;
	}
	break;
	case 'R': 
	posX++;
		if (posX >= (SCREEN_WIDTH-25))
	{
		posX=(SCREEN_WIDTH-25);
	}
	break;
}
}
};


#endif // SNAKE_SNAKE_H