/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __POINT_H__
#define __POINT_H__
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct point_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
	void (*sauvegarder)(char *, void *);
  unsigned int x;
  unsigned int y;
  couleur_t couleur;
}point_t;

/**
   Cette fonction détruit une figure de type point_t.
   @param point qui est un pointeur sur une figure de type point_t.
**/
void detruire_point(void * point);

/**
   Cette fonction affiche une figure de type point_t sur une interface graphique.
   @param rendu qui est un élément de type SDL pour visualiser le point sur une interface graphique, et point qui est un pointeur sur une figure de
   type point_t.
**/
void afficher_point(SDL_Renderer * rendu, void * point);

/**
   Cette fonction sauvegarde une figure de type point_t dans un fichier.
   @param chemin qui est le chemin qui conduit jusqu'au fichier où la figure va être sauvegardée, et point qui est un pointeur sur une figure de
   type point_t.
**/
void sauvegarder_point(char * chemin, void * point);

/**
   Cette fonction initialise une figure de type point_t.
   Un point possède une coordonnée en x et en y, une couleur et
   deux pointeurs de fonctions qui permettent de l'afficher et de le détruire.
   @param x est la coordonnée en x.
   @param y est la coordonnée en y.
   @param couleur est la couleur du point.
   @requires x < Taille de la fenêtre de dessin.
   @requires y < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat->afficher pointe vers une fonction d'affichage.
   @ensures resultat->x = x, resultat->y = y, resultat->couleur = c
*/
point_t * creer_point(unsigned int x, unsigned int y, couleur_t c);

#endif
