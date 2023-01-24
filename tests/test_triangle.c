/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/triangle.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s",ROUGE);

  triangle_t * t = creer_triangle(5, 5, 10, 5, 7, 8, creer_couleur(125,0,210));

  assert(t -> detruire !=NULL);
  assert(t -> afficher !=NULL);

  t -> detruire(t);

  printf("%stest_triangle a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
