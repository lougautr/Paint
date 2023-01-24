/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct triangle_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
	void (*sauvegarder)(char *, void *);
	unsigned int x0;
  unsigned int y0;
  unsigned int x1;
  unsigned int y1;
  unsigned int x2;
  unsigned int y2;
  couleur_t couleur;
}triangle_t;

/**
   Cette fonction détruit une figure de type triangle_t.
   @param triangle qui est un pointeur sur une figure de type triangle_t.
**/
void detruire_triangle(void * triangle);

/**
   Cette fonction affiche une figure de type triangle_t sur une interface graphique.
   @param rendu qui est un élément de type SDL pour visualiser le triangle sur une interface graphique, et triangle qui est un pointeur sur une
   figure de type triangle_t.
**/
void afficher_triangle(SDL_Renderer * rendu, void * triangle);

/**
   Cette fonction sauvegarde une figure de type triangle_t dans un fichier.
   @param chemin qui est le chemin qui conduit jusqu'au fichier où la figure va être sauvegardée, et triangle qui est un pointeur sur une figure de
   type triangle_t.
**/
void sauvegarder_triangle(char * chemin, void * triangle);

/**
   Cette fonction initialise une figure de type triangle_t.
   Un triangle possède trois coordonnéees en (x0,y0), (x1,y1) et (x2,y2),une couleur et, trois pointeurs de fonctions qui permettent de
   l'afficher, de le détruire, et de le sauvegarder.
   @param x0 est la coordonnée du premier point en x0.
   @param y0 est la coordonnée du premier point en y0.
   @param x1 est la coordonnée du deuxième point en x1.
   @param y1 est la coordonnée du deuxième point en y1.
   @param x2 est la coordonnée du troisième point en x2.
   @param y2 est la coordonnée du troisième point en y2.
   @param couleur est la couleur du point.
   @requires x0 < Taille de la fenêtre de dessin.
   @requires y0 < Taille de la fenêtre de dessin.
   @requires x1 < Taille de la fenêtre de dessin.
   @requires y1 < Taille de la fenêtre de dessin.
   @requires x2 < Taille de la fenêtre de dessin.
   @requires y2 < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat -> detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat -> afficher pointe vers une fonction d'affichage.
   @ensures resultat -> sauvegarder pointe vers une fonction d'de sauvegarde.
   @ensures resultat -> x0 = x0, resultat -> y0 = y0, resultat -> x1 = x1, resultat -> y1 = y1, resultat -> x2 = x2, resultat -> y2 = y2,
   resultat -> couleur = c
**/
triangle_t * creer_triangle(unsigned int x0, unsigned int y0,unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2, couleur_t c);

#endif
