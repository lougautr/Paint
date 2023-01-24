/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Lou-Anne Gautherie (22001251), Naya Makdessi (22001285)
*/

#ifndef __FICHIERS_IMAGES_H__
#define __FICHIERS_IMAGES_H__

/*
   Cette fonction sert à sauvegarder une liste de figures dans un fichier
   @param chemin est le chemin qui conduit au fichier où l'on veut enregistrer la liste, et l est une liste de figures
*/

void sauvegarder_liste_figures(char * chemin, liste_figure_t * l);

/*
   Cette fonction sert à charger une liste de figures se trouvant dans un fichier
   @param chemin est le chemin qui conduit au fichier que l'on veut charger, et l est une liste de figures
*/

int charger_liste_figures(char * chemin, liste_figure_t * l);

#endif
