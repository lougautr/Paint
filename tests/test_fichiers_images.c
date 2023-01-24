/*
   Projet L2 Structures Algébriques 2022
   Auteur(e): Lou-Anne Gautherie (22001251)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/fichiers_images.h"
#include"../src/liste_figure.h"
#include"../src/figures/triangle.h"

#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  triangle_t * fig1 = creer_triangle(5, 5, 10, 5, 7, 8, creer_couleur(125,0,210));
  triangle_t * fig2 = creer_triangle(7, 7, 12, 7, 9, 10, creer_couleur(255,0,0));

  liste_figure_t * liste_test = creer_liste();

  liste_inserer_debut(liste_test, fig1);
  liste_inserer_fin(liste_test, fig2);

  sauvegarder_liste_figures("test.txt", liste_test);
  charger_liste_figures("test.txt", copyListe);

  printf("%stest_fichiers_images a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
