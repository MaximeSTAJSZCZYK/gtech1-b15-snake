#ifndef POS_POS_H
#define POS_POS_H

#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 1000

class Pos
{
    private :

    public :
    int posY;
    int posX;

    Pos( int posY, int posX, int score)
    {       
            if (score == 0)
            {
            this->posX = SCREEN_WIDTH/2;
            this->posY = SCREEN_HEIGHT/2;
            }
            
    }
};


#endif 
