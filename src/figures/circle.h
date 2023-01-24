/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct circle_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
	void (*sauvegarder)(char *, void *);
  unsigned int x;
  unsigned int y;
  unsigned int radius;
  couleur_t couleur;
}circle_t;

/**
   Cette fonction détruit une figure de type circle_t.
   @param circle qui est un pointeur sur une figure de type circle_t.
**/
void detruire_circle(void * circle);

/**
   Cette fonction dessine une figure de type circle_t.
   @param rendu qui est un élément de type SDL pour visualiser le cercle sur une interface graphique, des coordoonées (x0,y0) qui sont le centre du
   cercle et radius qui est le rayon du cercle.
**/
void drawcircle(SDL_Renderer * rendu, int x0, int y0, int radius);

/**
   Cette fonction affiche une figure de type circle_t sur une interface graphique.
   @param rendu qui est un élément de type SDL pour visualiser le cercle sur une interface graphique, et circle qui est un pointeur sur une figure de
   type circle_t.
**/
void afficher_circle(SDL_Renderer * rendu, void * circle);

/**
   Cette fonction sauvegarde une figure de type circle_t dans un fichier.
   @param chemin qui est le chemin qui conduit jusqu'au fichier où la figure va être sauvegardée, et circle qui un pointeur sur est une figure de
   type circle_t.
**/
void sauvegarder_circle(char * chemin, void * circle);

/**
   Cette fonction initialise une figure de type circle_t.
   @param un centre des coordoonées (x,y), radius qui est un rayon et color qui est une couleur, et trois pointeurs de fonctions qui permettent de
   l'afficher, de le détruire, et de le sauvegarder.
   @param x est la coordonnée du centre en x.
   @param y est la coordonnée du centre en y.
   @param radius qui est le rayon.
   @param couleur est la couleur du point.
   @requires x < Taille de la fenêtre de dessin.
   @requires y < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat -> detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat -> afficher pointe vers une fonction d'affichage.
   @ensures resultat -> sauvegarder pointe vers une fonction d'de sauvegarde.
   @ensures resultat -> x = x, resultat -> y = y, resultat -> couleur = c
**/
circle_t * creer_circle(unsigned int x, unsigned int y, unsigned int radius, couleur_t color);

#endif
