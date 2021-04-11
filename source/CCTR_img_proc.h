#ifndef CCTR_IMG_PROC
#define CCTR_IMG_PROC
#include "CCTR_Camera.h"

typedef struct Bord {
int cas;
int gauche, droite;
} Bord;


int Ligne_Filtre_Gaussien(unsigned char img[128], unsigned char buffer[128]);
int Ligne_Bord_Detecte(Bord *bord, unsigned char img[128]);
int Bord_Milieu(Bord bord);
int Bord_Vitesse(int *perdu, Bord bord_old, Bord bord);

#endif

