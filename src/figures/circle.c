/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Naya Makdessi (22001285)
*/

#include"circle.h"

void detruire_circle(void * circle){
  circle_t * c = circle;
  free(c);
}

void drawcircle(SDL_Renderer * rendu, int x0, int y0, int radius){
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y){
        SDL_RenderDrawPoint(rendu, x0 + x, y0 + y);
        SDL_RenderDrawPoint(rendu, x0 + y, y0 + x);
        SDL_RenderDrawPoint(rendu, x0 - y, y0 + x);
        SDL_RenderDrawPoint(rendu, x0 - x, y0 + y);
        SDL_RenderDrawPoint(rendu, x0 - x, y0 - y);
        SDL_RenderDrawPoint(rendu, x0 - y, y0 - x);
        SDL_RenderDrawPoint(rendu, x0 + y, y0 - x);
        SDL_RenderDrawPoint(rendu, x0 + x, y0 - y);

        if (err <= 0){
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0){
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}


void afficher_circle(SDL_Renderer * rendu, void * circle){
  circle_t * c = circle;
  SDL_SetRenderDrawColor(rendu, c->couleur.rouge,
			 c->couleur.vert, c->couleur.bleu, 255);

  drawcircle(rendu, c->x, c->y, c->radius);
}

void sauvegarder_circle(char * chemin, void * circle){
	FILE *f;
  if ((f = fopen(chemin,"a")) != NULL){
				circle_t * c = circle;
				fwrite("c", sizeof(char),1,f);
				fwrite(&(c->x), sizeof(unsigned int), 1,f);
				fwrite(&(c->y), sizeof(unsigned int), 1,f);
				fwrite(&(c->radius), sizeof(unsigned int), 1,f);

				fwrite(&(c->couleur.rouge), sizeof(unsigned int), 1,f);
				fwrite(&(c->couleur.vert), sizeof(unsigned int), 1,f);
				fwrite(&(c->couleur.bleu), sizeof(unsigned int), 1,f);
		}
	fclose(f);
}

circle_t * creer_circle(unsigned int x, unsigned int y, unsigned int radius, couleur_t color){
  circle_t * c = malloc(sizeof(circle_t));
  c->detruire = detruire_circle;
  c->afficher = afficher_circle;
	c->sauvegarder = sauvegarder_circle;
  c->x = x;
  c->y = y;
  c->radius = radius;
  c->couleur = color;
  return c;
}
