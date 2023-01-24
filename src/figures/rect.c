/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Naya Makdessi (22001285)
*/

#include"rect.h"

void detruire_rect(void * rect){
  rect_t * r = rect;
  free(r);
}

void afficher_rect(SDL_Renderer * rendu, void * rect){
  rect_t * r = rect;
  SDL_SetRenderDrawColor(rendu, r->couleur.rouge,
			 r->couleur.vert, r->couleur.bleu, 255);
  //convertit la structure rect_t en SDL_Rect pour pouvoir afficher
  SDL_Rect * rectangle = malloc(sizeof(SDL_Rect));
  rectangle->x = r->x;
  rectangle->y = r->y;
  rectangle->w = r->w;
  rectangle->h = r->h;
  SDL_RenderDrawRect(rendu,rectangle);
}

void sauvegarder_rect(char * chemin, void * rect){
	FILE *f;
  if ((f = fopen(chemin,"a")) != NULL){
		rect_t * r = rect;
		fwrite("r", sizeof(char),1,f);
		fwrite(&(r->x), sizeof(unsigned int), 1,f);
		fwrite(&(r->y), sizeof(unsigned int), 1,f);
		fwrite(&(r->w), sizeof(unsigned int), 1,f);
		fwrite(&(r->h), sizeof(unsigned int), 1,f);

		fwrite(&(r->couleur.rouge), sizeof(unsigned int), 1,f);
		fwrite(&(r->couleur.vert), sizeof(unsigned int), 1,f);
		fwrite(&(r->couleur.bleu), sizeof(unsigned int), 1,f);
	}
	fclose(f);
}

rect_t * creer_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, couleur_t c){
  rect_t * r = malloc(sizeof(rect_t));
  r->detruire = detruire_rect;
  r->afficher = afficher_rect;
	r->sauvegarder = sauvegarder_rect;
  r->x = x;
  r->y = y;
  r->w = w;
  r->h = h;
  r->couleur = c;
  return r;
}
