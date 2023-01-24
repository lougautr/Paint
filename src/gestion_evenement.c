/*
   Projet L2 Structures Algébriques 2022
   Auteur(e)(s): Antonin Montagne (21901206)
*/

#include"gestion_evenement.h"

couleur_t couleur;
char chemin[100];

//Cette fonction gére tout les raccourcis
void gestion_evenements(int * close, liste_figure_t * l){
  SDL_Event event;
  // Events management
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_KEYUP:
      switch (event.key.keysym.sym){
      case SDLK_q:
      	printf("Au revoir\n");
      	*close = 1;
      	break;
      case SDLK_p:
        raccourciPoint(l, couleur);
        break;
      case SDLK_z:
        raccourciCouleur(&couleur);
        break;
      case SDLK_s:
        raccourciSegment(l, couleur);
        break;
      case SDLK_r:
        raccourciRectangle(l, couleur);
        break;
      case SDLK_t:
        raccourciTriangle(l, couleur);
        break;
      case SDLK_c:
        raccourciCercle(l, couleur);
        break;
      case SDLK_a:
        sauvegardeListe(l);
        break;
      case SDLK_e:
        printf("Veuillez saisir le nom du fichier avec l'extension .txt : \n");
        scanf("%s",chemin);
        chargerListe(l,chemin);
        break;
      }
      break;
    case SDL_QUIT:
      printf("Au revoir\n");
      *close = 1;
      break;
    case SDL_MOUSEBUTTONDOWN:
      printf("Vous avez cliqué sur la souris :\n");
      printf("\tfenêtre : %d\n",event.button.windowID);
      printf("\tbouton : %d\n",event.button.button);
      printf("\tposition : %d;%d\n",event.button.x,event.button.y);
      afficheRaccourci();
      break;
    }
  }
}

void raccourciPoint(liste_figure_t* l, couleur_t couleur){
  SDL_Event event;
  while(SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      //On récupère les coordonnées du clic et on crée notre point
      liste_inserer_fin(l, creer_point(event.button.x,event.button.y,couleur));
      break;
    }
  }
}

//Cette fonction permet d'enregistrer la valeur saisit par l'utilisateur pour la couleur
unsigned int saisieCouleur(char couleur[], unsigned int rvb){
  printf("Veuillez saisir un niveau de %s entre 0 et 255 : ",couleur);
  scanf("%u",&rvb);
  while((rvb>255)||(rvb<0)){
    printf("Attention le niveau de rouge doit être entre 0 et 255 : ");
    scanf("%u",&rvb);
  }
  return rvb;
}

void raccourciCouleur(couleur_t* couleur){
  //Pour les 3 variables r, b, v on récupère les valeurs saisit par l'utilisateur
  unsigned int r = 0;
  r = saisieCouleur("rouge",r);
  unsigned int v = 0;
  v = saisieCouleur("vert",v);
  unsigned int b = 0;
  b = saisieCouleur("bleu",b);
  *couleur = creer_couleur(r,v,b);
  //On réaffiche les raccourcis pour toujours les avoir dans le terminal
  afficheRaccourci();
}

void raccourciSegment(liste_figure_t* l, couleur_t couleur){
  SDL_Event event;
  int posDepartX = 0;
  int posDepartY = 0;
  //On récupère les coordonnées du premier clic
  recupCoordSouris(&posDepartX, &posDepartY);
  while(SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      //On crée le segment entre le premier clic et le deuxième
      liste_inserer_fin(l, creer_segment(posDepartX, posDepartY, event.button.x, event.button.y, couleur));
      break;
    }
  }
}

void raccourciRectangle(liste_figure_t* l, couleur_t couleur){
  SDL_Event event;
  int largeur;
  int hauteur;
  printf("Veuillez saisir la largeur du rectangle : ");
  scanf("%d",&largeur);
  printf("Veuillez saisir la hauteur du rectangle : ");
  scanf("%d",&hauteur);
  while (SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      //On crée un rectangle qui part de l'endroit où l'on vient de cliquer
      liste_inserer_fin(l, creer_rect(event.button.x, event.button.y, largeur, hauteur, couleur));
      break;
    }
  }
  //On réaffiche les raccourcis pour toujours les avoir dans le terminal
  afficheRaccourci();
}

void raccourciTriangle(liste_figure_t* l, couleur_t couleur){
  SDL_Event event;
  int x0 = 0;
  int y0 = 0;
  int x1 = 0;
  int y1 = 0;
  //On récupère les coordonnées du premier clic
  recupCoordSouris(&x0, &y0);
  //On récupère les coordonnées du second clic
  recupCoordSouris(&x1, &y1);
  while(SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      //On crée un triangle qui trace des segments entre les 3 clics
      liste_inserer_fin(l, creer_triangle(x0, y0, x1, y1, event.button.x, event.button.y, couleur));
      break;
    }
  }
}

void raccourciCercle(liste_figure_t* l, couleur_t couleur){
  SDL_Event event;
  int rayon;
  printf("Veuillez saisir la taille du rayon du cercle : ");
  scanf("%d",&rayon);
  while(SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      //On crée un cercle qui a pour centre les coordonnées du clic et qui a pour rayon la valeur saisit par l'utilisateur
      liste_inserer_fin(l, creer_circle(event.button.x, event.button.y, rayon, couleur));
      break;
    }
  }
  //On réaffiche les raccourcis pour toujours les avoir dans le terminal
  afficheRaccourci();
}

//Cette fonction sert à récupérer les coordonnées du clic
//Cette fonction a pour but d'éviter la redondance de code
void recupCoordSouris(int* x, int* y){
  SDL_Event event;
  while(SDL_WaitEvent(&event)){
    if(event.type == SDL_MOUSEBUTTONDOWN){
      *x = event.button.x;
      *y = event.button.y;
      break;
    }
  }
}

void sauvegardeListe(liste_figure_t * l){
  char chemin[50];
  printf("Veuillez saisir le nom de votre fichier avec l'extension .txt : ");
  scanf("%s", chemin);
  sauvegarder_liste_figures(chemin,l);
  //On réaffiche les raccourcis pour toujours les avoir dans le terminal
  afficheRaccourci();
}

void chargerListe(liste_figure_t * l, char chemin[]){
  while(!liste_est_vide(l))
    detruire_maillon(liste_extraire_debut(l));
  charger_liste_figures(chemin,l);
  //On réaffiche les raccourcis pour toujours les avoir dans le terminal
  afficheRaccourci();
}

//Cette fonction sert à afficher les raccourcis
void afficheRaccourci(){
  char* tabRaccourci[9] = {"q","a","e","z","p","s","r","t","c"};
  char* tabTexte[9] = {"ferme le programme","sauvegarde la liste des figures",
  "charge une liste de figure","initialise la couleur","crée un point",
  "crée un segment","crée un rectangle","crée un triangle","crée un cercle"};
  for(int i = 0; i < 9; i++){
    printf("Le raccourci %s %s\n", tabRaccourci[i], tabTexte[i]);
  }
}
