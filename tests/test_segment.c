/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/segment.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s",ROUGE);

  segment_t * s = creer_segment(10,10,15,15,creer_couleur(125,0,210));

  assert(s -> detruire !=NULL);
  assert(s -> afficher !=NULL);

  s -> detruire(s);

  printf("%stest_segment a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
