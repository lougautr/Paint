/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Antonin Montagne (21901206), Naya Makdessi (22001285)
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include"src/liste_figure.h"
#include"src/figures/point.h"
#include"src/figures/segment.h"
#include"src/figures/rect.h"
#include"src/figures/circle.h"
#include"src/figures/triangle.h"
#include"src/gestion_evenement.h"
#include"src/fichiers_images.h"

int inialisation_SDL(SDL_Window ** fenetre, int largeur, int hauteur, SDL_Renderer ** renderer);
void fermeture_SDL(SDL_Window * fenetre, SDL_Renderer * renderer);
void gestion_evenements(int * close, liste_figure_t * l);
void rendu_fenetre(SDL_Renderer * renderer, liste_figure_t * l);
void afficheRaccourci();


int main(int argc, char *argv[]){
  SDL_Window * fenetre;
  SDL_Renderer * rendu;
  int close = inialisation_SDL(&fenetre, 1000, 1000, &rendu);

  if( close < 0 )
    return EXIT_FAILURE;

  liste_figure_t * l = creer_liste();

  afficheRaccourci();

  while (!close) {
    gestion_evenements(&close, l);
    rendu_fenetre(rendu, l);
  }

  fermeture_SDL(fenetre, rendu);
  return EXIT_SUCCESS;
}

void rendu_fenetre(SDL_Renderer * rendu, liste_figure_t * l){
  SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
  SDL_RenderClear(rendu);

  for(maillon_figure_t * tmp = l->premier; tmp != NULL; tmp = tmp->suivant){
    tmp->figure->afficher(rendu, tmp->figure);
  }

  SDL_RenderPresent(rendu);
}

int inialisation_SDL(SDL_Window ** fenetre, int largeur, int hauteur, SDL_Renderer ** rendu){
  // Quitte le programme en cas d'erreur
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return -1;
  }
  /*
  SDL_CreateWindow a comme paramètre dans l'ordre (le titre, x, y , width, height, flags)
  en remplaçant x et y par SDL_WINDOWPOS_CENTERED place la fenetre au centre de l'axe x, y
  */
  *fenetre = SDL_CreateWindow("PROJET L2 Structures Algébriques",
			      SDL_WINDOWPOS_CENTERED,
			      SDL_WINDOWPOS_CENTERED,
			      largeur, hauteur, 0);
  // SDL_CreateRenderer permet de dessiner sur la fenetre crée elle prend en paramètre (fenetre, index (-1 par défault, flags))
  *rendu = SDL_CreateRenderer(*fenetre, -1, 0);
  return 0;
}

void fermeture_SDL(SDL_Window * fenetre, SDL_Renderer * rendu){
  //détruit le rendu
  SDL_DestroyRenderer(rendu);
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
}
