#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
    //int menu[];
    int start[][25] = {
                    {0,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0},
                    {0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0},
                    {0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0},
                    {0,1,1,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0}};


if(SDL_VideoInit(NULL) < 0)
{
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    return EXIT_FAILURE;
}


fenetre = SDL_CreateWindow("Carré" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1000 , 1000 , SDL_WINDOW_RESIZABLE);
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

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
for (int i = 0; i < 5; i++)
{
   for (int k = 0; k < sizeof(start); k++) {
    if(start[i][k] == 1){
        SDL_Rect rect = {150+(k*10),300+(i*10),10,10};
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}
}


SDL_Delay(3000); 
SDL_RenderPresent(renderer);
SDL_Delay(300); 
SDL_DestroyRenderer(renderer);

SDL_DestroyWindow(fenetre);
SDL_Quit();
}
