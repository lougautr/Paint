/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Amelie Phok (21706471), Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __SEGMENT_H__
#define __SEGMENT_H__
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct segment_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
	void (*sauvegarder)(char *, void *);
	unsigned int x1;
  unsigned int y1;
  unsigned int x2;
  unsigned int y2;
  couleur_t couleur;
}segment_t;

/**
   Cette fonction détruit une figure de type segment_t.
   @param segment qui est un pointeur sur une figure de type segment_t.
**/
void detruire_segment(void * segment);

/**
   Cette fonction affiche une figure de type segment_t sur une interface graphique.
   @param rendu qui est un élément de type SDL pour visualiser le segment sur une interface graphique, et segment qui est un pointeur sur une
   figure de type segment_t.
**/
void afficher_segment(SDL_Renderer * rendu, void * segment);

/**
   Cette fonction sauvegarde une figure de type segment_t dans un fichier.
   @param chemin qui est le chemin qui conduit jusqu'au fichier où la figure va être sauvegardée, et segment qui est un pointeur sur une figure de
   type segment_t.
**/
void sauvegarder_segment(char * chemin, void * segment);

/**
   Cette fonction initialise une figure de type semgent_t.
   Un segùent possède une coordonnée en x1 et en y1, et une coordonnée en x2 et y2, une couleur et trois pointeurs de fonctions qui permettent de
   l'afficher, de le détruire, et de le sauvegarder.
   @param x1 est la coordonnée en x1.
   @param y1 est la coordonnée en y1.
   @param x2 est la coordonnée en x2.
   @param y2 est la coordonnée en y2.
   @param couleur est la couleur du point.
   @requires x1 < Taille de la fenêtre de dessin.
   @requires y1 < Taille de la fenêtre de dessin.
   @requires x2 < Taille de la fenêtre de dessin.
   @requires y2 < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat -> detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat -> afficher pointe vers une fonction d'affichage.
   @ensures resultat -> sauvegarder pointe vers une fonction d'de sauvegarde.
   @ensures resultat -> x = x, resultat -> y = y, resultat -> couleur = c
*/
segment_t * creer_segment(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, couleur_t c);

#endif
