/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Naya Makdessi (22001285)
*/

#include"segment.h"

void detruire_segment(void * segment){
  segment_t * s = segment;
  free(s);
}

void afficher_segment(SDL_Renderer * rendu, void * segment){
  segment_t * s = segment;
  SDL_SetRenderDrawColor(rendu, s->couleur.rouge,
			 s->couleur.vert, s->couleur.bleu, 255);
  SDL_RenderDrawLine(rendu,s->x1,s->y1,s->x2,s->y2);
}

void sauvegarder_segment(char * chemin, void * segment){
	FILE *f;
  if ((f = fopen(chemin,"a")) != NULL){
		segment_t * s = segment;
		fwrite("s", sizeof(char),1,f);
		fwrite(&(s->x1), sizeof(unsigned int), 1,f);
		fwrite(&(s->y1), sizeof(unsigned int), 1,f);
		fwrite(&(s->x2), sizeof(unsigned int), 1,f);
		fwrite(&(s->y2), sizeof(unsigned int), 1,f);

		fwrite(&(s->couleur.rouge), sizeof(unsigned int), 1,f);
		fwrite(&(s->couleur.vert), sizeof(unsigned int), 1,f);
		fwrite(&(s->couleur.bleu), sizeof(unsigned int), 1,f);
	}
	fclose(f);
}

segment_t * creer_segment(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, couleur_t c){
  segment_t * s = malloc(sizeof(segment_t));
  s->detruire = detruire_segment;
  s->afficher = afficher_segment;
	s->sauvegarder = sauvegarder_segment;
  s->x1 = x1;
  s->y1 = y1;
  s->x2 = x2;
  s->y2 = y2;
  s->couleur = c;
  return s;
}
