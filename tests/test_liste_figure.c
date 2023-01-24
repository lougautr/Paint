/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/liste_figure.h"
#include"../src/figures/triangle.h"

#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  triangle_t * fig1 = creer_triangle(5, 5, 10, 5, 7, 8, creer_couleur(125,0,210));
  triangle_t * fig2 = creer_triangle(7, 7, 12, 7, 9, 10, creer_couleur(255,0,0));

  maillon_figure_t * m1 = creer_maillon(fig1);
  maillon_figure_t * m2 = creer_maillon(fig2);
  m1 -> suivant = m2;

  assert(m1 -> suivant == m2);

  detruire_maillon(m2);
  m1 -> suivant = NULL;

  assert(m1 -> suivant ==  NULL);

  liste_figure_t * liste_test = creer_liste();

  assert(liste_est_vide(liste_test) == 1);

  liste_inserer_debut(liste_test, fig1);

  assert(liste_test -> premier != NULL);

  liste_inserer_fin(liste_test, fig2);

  assert(liste_test -> taille != 0);
  assert(liste_taille(liste_test) == 2);

  liste_extraire_debut(liste_test);

  assert(liste_test -> premier == liste_test -> dernier);
  assert(liste_taille(liste_test) == 1);

  liste_test -> premier = NULL;
  liste_test -> dernier = NULL;
  liste_test -> taille = 0;
  detruire_liste(liste_test);

  printf("%stest_liste_figure a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
