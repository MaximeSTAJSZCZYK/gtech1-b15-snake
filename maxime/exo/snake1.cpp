#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <list>

#define HeightTextTitle SCREEN_HEIGHT/100*2
#define HeightText SCREEN_HEIGHT/100*1

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;
    SDL_Renderer* renderer;

    int row;
    int column;
    int SCREEN_HEIGHT = 600;
    int SCREEN_WIDTH = 600;

    //int menu[];

    int start[5][50] = {
                    {0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,1},
                    {1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0},
                    {0,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,0},
                    {0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0},
                    {1,1,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0}};
                  

    int snake[5][50] = {
                    {0,1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1},
                    {1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1},
                    {0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,1,0,1},
                    {0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0},
                    {1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1}}; 

    int option[5][50] = {
                    {0,1,1,0,0,0,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,0,0,1},
                    {1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1},
                    {1,0,0,1,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1},
                    {1,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
                    {0,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1}}; 

    int leave[5][50] = {
                    {1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,0},
                    {1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0},
                    {1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0},
                    {1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0},
                    {1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,0,0}}; 

    int gameover[5][50] = {
                    {0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0},
                    {1,0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0},
                    {1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0},
                    {1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0},
                    {0,1,1,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1}}; 

    int numbers[5][60] = {
                    {1,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0},
                    {1,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0},
                    {1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0},
                    {1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0},
                    {1,1,1,0,0,1,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0}}; 

    int arrow[5][10] = {
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,0},
                    {1,1,1,1,1,1},
                    {0,0,0,0,1,0},
                    {0,0,0,1,0,0}}; 



if(SDL_VideoInit(NULL) < 0)
{
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    return EXIT_FAILURE;
}


fenetre = SDL_CreateWindow("Carré" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_HEIGHT , SCREEN_WIDTH , SDL_WINDOW_RESIZABLE);
if(fenetre == NULL)
{
    printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
    return EXIT_FAILURE;
}

renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

if(renderer == NULL)
{
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
}


row = sizeof(snake)/sizeof(snake[0]);
column = sizeof(snake[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(snake[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,50,200,50,0);
        SDL_Rect rect = {SCREEN_WIDTH/100*30+(k*HeightTextTitle),SCREEN_HEIGHT/100*10+(i*HeightTextTitle),HeightTextTitle,HeightTextTitle};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

row = sizeof(start)/sizeof(start[0]);
column = sizeof(start[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(start[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rect = {SCREEN_WIDTH/100*40+(k*HeightText),SCREEN_HEIGHT/100*30+(i*HeightText),HeightText,HeightText};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

row = sizeof(option)/sizeof(option[0]);
column = sizeof(option[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(option[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rect = {SCREEN_WIDTH/100*40+(k*10),SCREEN_HEIGHT/100*45+(i*10),10,10};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

row = sizeof(leave)/sizeof(leave[0]);
column = sizeof(leave[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(leave[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rect = {SCREEN_WIDTH/100*40+(k*10),SCREEN_HEIGHT/100*60+(i*10),10,10};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

/*
row = sizeof(arrow)/sizeof(arrow[0]);
column = sizeof(arrow[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(arrow[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rect = {200+(k*10),400+(i*10),10,10};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}
*/

/*
row = sizeof(gameover)/sizeof(gameover[0]);
column = sizeof(gameover[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(gameover[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,130,0,0,0);
        SDL_Rect rect = {100+(k*20),300+(i*20),20,20};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}

row = sizeof(numbers)/sizeof(numbers[0]);
column = sizeof(numbers[0])/row;
for (int i = 0; i < row; i++)
{
   for (int k = 0; k < column; k++) {
    if(numbers[i][k] == 1){
        SDL_SetRenderDrawColor(renderer,130,0,0,0);
        SDL_Rect rect = {100+(k*20),300+(i*20),20,20};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}
*/

SDL_Delay(1000); 
SDL_RenderPresent(renderer);
SDL_Delay(5000); 
int esc = 0;
	
	const Uint8* keystates = SDL_GetKeyboardState( 0 );

if(esc = 0 && keystates [SDL_SCANCODE_ESCAPE]){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}


}