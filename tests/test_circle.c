/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../src/figures/circle.h"


#define ROUGE  "\x1B[31m"
#define VERT "\x1B[32m"
#define DEFAUT  "\x1B[0m"

int main(){
  printf("%s",ROUGE);

  circle_t * c = creer_circle(25, 25, 25, creer_couleur(125, 0, 210));

  assert( c->detruire !=NULL );
  assert( c->afficher !=NULL );

  c->detruire(c);

  printf("%stest_circle a passé les tests avec succès\n", VERT);
  printf("%s",DEFAUT);
  return EXIT_SUCCESS;
}
