/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Naya Makdessi (22001285)
*/

#include"triangle.h"

void detruire_triangle(void * triangle){
  triangle_t * t = triangle;
  free(t);
}

void afficher_triangle(SDL_Renderer * rendu, void * triangle){
  triangle_t * t = triangle;
  SDL_SetRenderDrawColor(rendu, t->couleur.rouge,
			 t->couleur.vert, t->couleur.bleu, 255);
  SDL_RenderDrawLine(rendu, t->x0, t->y0, t->x1, t->y1);
  SDL_RenderDrawLine(rendu, t->x1, t->y1, t->x2, t->y2);
  SDL_RenderDrawLine(rendu, t->x2, t->y2, t->x0, t->y0);
}

void sauvegarder_triangle(char * chemin, void * triangle){
	FILE *f;
  if ((f = fopen(chemin,"a")) != NULL){
		triangle_t * t = triangle;
		fwrite("t", sizeof(char),1,f);
		fwrite(&(t->x0), sizeof(unsigned int), 1,f);
		fwrite(&(t->y0), sizeof(unsigned int), 1,f);
		fwrite(&(t->x1), sizeof(unsigned int), 1,f);
		fwrite(&(t->y1), sizeof(unsigned int), 1,f);
		fwrite(&(t->x2), sizeof(unsigned int), 1,f);
		fwrite(&(t->y2), sizeof(unsigned int), 1,f);

		fwrite(&(t->couleur.rouge), sizeof(unsigned int), 1,f);
		fwrite(&(t->couleur.vert), sizeof(unsigned int), 1,f);
		fwrite(&(t->couleur.bleu), sizeof(unsigned int), 1,f);
	}
	fclose(f);
}

triangle_t * creer_triangle(unsigned int x0, unsigned int y0,unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2, couleur_t c){
  triangle_t * t = malloc(sizeof(triangle_t));
  t->detruire = detruire_triangle;
  t->afficher = afficher_triangle;
	t->sauvegarder = sauvegarder_triangle;
  t->x0 = x0;
  t->y0 = y0;
  t->x1 = x1;
  t->y1 = y1;
  t->x2 = x2;
  t->y2 = y2;
  t->couleur = c;
  return t;
}
