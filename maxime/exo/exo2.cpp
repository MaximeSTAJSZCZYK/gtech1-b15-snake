#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WINDOW_W 800
#define WINDOW_H 800
#define PRECISION 0.001
#define PI 3.14159265

int main(int argc, char *argv[])
{
    SDL_Window* fenetre;
    SDL_Renderer* renderer;//Déclaration du renderer

    SDL_Point octogone[9];//Déclaration du tableau contenant les cases blanches
    //SDL_Point ligne_depart,ligne_arrivee;//Déclaration du point de départ et du point d'arrivée d'une ligne


    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

// Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_W , WINDOW_H , 0);
    if(fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

//Création du renderer :
    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
    if(renderer == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

//On met le fond en blanc
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

//Couleur de dessin :  noir
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

//On dessine le cercle
    for(double i = 0.0; i < 360; i+= PRECISION)
        SDL_RenderDrawPoint(renderer,WINDOW_W /2 - cos(i)*WINDOW_W / 2,WINDOW_H / 2 - sin(i)* WINDOW_H / 2);

//Maintenant, notre octogone
    for(int i = 0; i != 9; i++)
    {
        octogone[i].x = WINDOW_W /2 - cos(i*45*PI/180)*WINDOW_W / 2; //On détermine la position 
        octogone[i].y = WINDOW_H /2 - sin(i*45*PI/180)*WINDOW_H / 2; //de chaque point de l'octogone
    }
    octogone[8] = octogone[0];//Le dernier point rejoint le premier, pour clore le polygone

//On trace le chemin formé par les points
    if( SDL_RenderDrawLines(renderer, octogone, 9)<0)
    {
        printf("Erreur dans le tracé de l'octogone : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

//Toujours penser au rendu, sinon on n'obtient rien du tout
    SDL_RenderPresent(renderer);

    SDL_Delay(20000);//pause de 20 secondes, pour admirer notre œuvre autant que l'on veut

// Destruction du renderer et de la fenêtre :
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit(); // On quitte la SDL
}