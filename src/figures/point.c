/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Naya Makdessi (22001285)
*/

#include"point.h"

void detruire_point(void * point){
  point_t * p = point;
  free(p);
}

void afficher_point(SDL_Renderer * rendu, void * point){
  point_t * p = point;
  SDL_SetRenderDrawColor(rendu, p->couleur.rouge,
			 p->couleur.vert, p->couleur.bleu, 255);
  SDL_RenderDrawPoint(rendu, p->x, p->y);
}

void sauvegarder_point(char * chemin, void * point){
	FILE *f;
  if ((f = fopen(chemin,"a")) != NULL){
		point_t * p = point;
		fwrite("p", sizeof(char),1,f);
		fwrite(&(p->x), sizeof(unsigned int), 1,f);
		fwrite(&(p->y), sizeof(unsigned int), 1,f);

		fwrite(&(p->couleur.rouge), sizeof(unsigned int), 1,f);
		fwrite(&(p->couleur.vert), sizeof(unsigned int), 1,f);
		fwrite(&(p->couleur.bleu), sizeof(unsigned int), 1,f);
	}
	fclose(f);
}

point_t * creer_point(unsigned int x, unsigned int y, couleur_t c){
  point_t * p = malloc(sizeof(point_t));
  p->detruire = detruire_point;
  p->afficher = afficher_point;
	p->sauvegarder = sauvegarder_point;
  p->x = x;
  p->y = y;
  p->couleur = c;
  return p;
}
