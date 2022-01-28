#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;
    SDL_Renderer* renderer;//Déclaration du renderer

if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
{
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    return EXIT_FAILURE;
}

// Création de la fenêtre :
fenetre = SDL_CreateWindow("Carré" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1000 , 1000 , SDL_WINDOW_RESIZABLE);
if(fenetre == NULL) // Gestion des erreurs
{
    printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
    return EXIT_FAILURE;
}

renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

if(renderer == NULL)//gestion des erreurs
{
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
}

    SDL_SetRenderDrawColor(renderer,255,0,0,0);
    
SDL_Rect rect = {0,0,100,100};
SDL_RenderDrawRect(renderer, &rect);
SDL_RenderFillRect(renderer, &rect);

SDL_RenderPresent(renderer);
SDL_Delay(3000);//pause de 3 secondes
// Destruction du renderer et de la fenêtre :
SDL_DestroyRenderer(renderer); 
SDL_DestroyWindow(fenetre);
SDL_Quit(); // On quitte la SDL
}