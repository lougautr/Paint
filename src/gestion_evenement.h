/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Antonin Montagne (21901206)
*/

#ifndef __GESTION_EVENEMENTS_H__
#define __GESTION_EVENEMENTS_H__

#include <string.h>
#include"couleur.h"
#include"liste_figure.h"
#include"fichiers_images.h"
#include"figures/point.h"
#include"figures/segment.h"
#include"figures/rect.h"
#include"figures/triangle.h"
#include"figures/circle.h"
#include <SDL2/SDL.h>

void gestion_evenements(int * close, liste_figure_t * l);
void raccourciPoint(liste_figure_t*, couleur_t couleur);
unsigned int saisieCouleur(char couleur[], unsigned int rvb);
void raccourciCouleur(couleur_t* couleur);
void raccourciSegment(liste_figure_t*, couleur_t couleur);
void raccourciRectangle(liste_figure_t* l, couleur_t couleur);
void raccourciTriangle(liste_figure_t* l, couleur_t couleur);
void raccourciCercle(liste_figure_t*l , couleur_t couleur);
void recupCoordSouris(int* x, int* y);
void sauvegardeListe(liste_figure_t * l);
void chargerListe(liste_figure_t * l, char chemin[]);
void afficheRaccourci();

#endif
