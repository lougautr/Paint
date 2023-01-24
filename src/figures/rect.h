/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __RECT_H__
#define __RECT_H__
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct rect_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
	void (*sauvegarder)(char *, void *);
  unsigned int x;
  unsigned int y;
  unsigned int w;
  unsigned int h;
  couleur_t couleur;
}rect_t;

/**
   Cette fonction détruit une figure de type rect_t.
   @param rect qui est un pointeur sur une figure de type rect_t.
**/
void detruire_rect(void * rect);

/**
   Cette fonction affiche une figure de type rect_t sur une interface graphique.
   @param rendu qui est un élément de type SDL pour visualiser le cercle sur une interface graphique, et rect qui est un pointeur sur une figure de
   type rect_t.
**/
void afficher_rect(SDL_Renderer * rendu, void * rect);

/**
   Cette fonction sauvegarde une figure de type rect_t dans un fichier.
   @param chemin qui est le chemin qui conduit jusqu'au fichier où la figure va être sauvegardée, et rect qui est un pointeur sur une figure de
   type rect_t.
**/
void sauvegarder_rect(char * chemin, void * rect);

/**
   Cette fonction initialise une figure de type rect_t.
   Un rect possède une coordonnée en x et y, une largeur w et une hauteur h, une couleur et trois pointeurs de fonctions qui permettent de
   l'afficher, de le détruire, et de le sauvegarder.
   @param x1 est la coordonnée en x1.
   @param y1 est la coordonnée en y1.
   @param w est la largeur.
   @param h est la hauteur.
   @param couleur est la couleur du point.
   @requires x1 < Taille de la fenêtre de dessin.
   @requires y1 < Taille de la fenêtre de dessin.
   @requires w < Taille de la fenêtre de dessin.
   @requires h < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat -> detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat -> afficher pointe vers une fonction d'affichage.
   @ensures resultat -> sauvegarder pointe vers une fonction d'de sauvegarde.
   @ensures resultat -> x = x, resultat -> y = y, resultat -> couleur = c
*/
rect_t * creer_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, couleur_t c);

#endif
