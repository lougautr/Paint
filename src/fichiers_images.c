/**
Projet L2 Structures Algébriques 2022
Auteur(e)(s): Naya Makdessi (22001285)
**/

#include"liste_figure.h"
#include"figures/point.h"
#include"figures/segment.h"
#include"figures/rect.h"
#include"figures/circle.h"
#include"figures/triangle.h"
#include"fichiers_images.h"

void sauvegarder_liste_figures(char * chemin, liste_figure_t * l){
	FILE *f;
	f = fopen(chemin,"w");
	fclose(f);
	for(maillon_figure_t * tmp = l->premier; tmp != NULL; tmp = tmp->suivant){
		tmp->figure->sauvegarder(chemin,tmp->figure);
	}
}

void sauvegarder_image(char * chemin, liste_figure_t * l){
}

int charger_liste_figures(char * chemin, liste_figure_t * l){
	FILE *f;
	f = fopen(chemin, "r");
	char buffer[2];
	while(fread(buffer, sizeof(char), 1, f) == 1){
		if (strcmp(buffer,"c") == 0){
			unsigned int x;
			fread(&x, sizeof(unsigned int), 1, f);
		  unsigned int y;
			fread(&y, sizeof(unsigned int), 1, f);
		  unsigned int radius;
			fread(&radius, sizeof(unsigned int), 1, f);

			unsigned int r;
			fread(&r, sizeof(unsigned int), 1, f);
		  unsigned int v;
			fread(&v, sizeof(unsigned int), 1, f);
		  unsigned int b;
			fread(&b, sizeof(unsigned int), 1, f);

			liste_inserer_fin(l, creer_circle(x,y,radius, creer_couleur(r,v,b)));


		}else if (strcmp(buffer,"p") == 0){
			unsigned int x;
			fread(&x, sizeof(unsigned int), 1, f);
		  unsigned int y;
			fread(&y, sizeof(unsigned int), 1, f);

			unsigned int r;
			fread(&r, sizeof(unsigned int), 1, f);
		  unsigned int v;
			fread(&v, sizeof(unsigned int), 1, f);
		  unsigned int b;
			fread(&b, sizeof(unsigned int), 1, f);

			liste_inserer_fin(l, creer_point(x,y, creer_couleur(r,v,b)));


		}else if (strcmp(buffer,"s") == 0){
			unsigned int x1;
			fread(&x1, sizeof(unsigned int), 1, f);
		  unsigned int y1;
			fread(&y1, sizeof(unsigned int), 1, f);
			unsigned int x2;
			fread(&x2, sizeof(unsigned int), 1, f);
		  unsigned int y2;
			fread(&y2, sizeof(unsigned int), 1, f);


			unsigned int r;
			fread(&r, sizeof(unsigned int), 1, f);
		  unsigned int v;
			fread(&v, sizeof(unsigned int), 1, f);
		  unsigned int b;
			fread(&b, sizeof(unsigned int), 1, f);

			liste_inserer_fin(l, creer_segment(x1,y1,x2,y2, creer_couleur(r,v,b)));

		}else if (strcmp(buffer,"r") == 0){
			unsigned int x;
			fread(&x, sizeof(unsigned int), 1, f);
		  unsigned int y;
			fread(&y, sizeof(unsigned int), 1, f);
			unsigned int w;
			fread(&w, sizeof(unsigned int), 1, f);
		  unsigned int h;
			fread(&h, sizeof(unsigned int), 1, f);



			unsigned int r;
			fread(&r, sizeof(unsigned int), 1, f);
		  unsigned int v;
			fread(&v, sizeof(unsigned int), 1, f);
		  unsigned int b;
			fread(&b, sizeof(unsigned int), 1, f);

			liste_inserer_fin(l, creer_rect(x,y,w,h, creer_couleur(r,v,b)));

		}else{
			unsigned int x0;
			fread(&x0, sizeof(unsigned int), 1, f);
		  unsigned int y0;
			fread(&y0, sizeof(unsigned int), 1, f);
			unsigned int x1;
			fread(&x1, sizeof(unsigned int), 1, f);
		  unsigned int y1;
			fread(&y1, sizeof(unsigned int), 1, f);
			unsigned int x2;
			fread(&x2, sizeof(unsigned int), 1, f);
		  unsigned int y2;
			fread(&y2, sizeof(unsigned int), 1, f);


			unsigned int r;
			fread(&r, sizeof(unsigned int), 1, f);
		  unsigned int v;
			fread(&v, sizeof(unsigned int), 1, f);
		  unsigned int b;
			fread(&b, sizeof(unsigned int), 1, f);

			liste_inserer_fin(l, creer_triangle(x0,y0,x1,y1,x2,y2, creer_couleur(r,v,b)));

		}
	}
	fclose(f);
  return -1;
}
