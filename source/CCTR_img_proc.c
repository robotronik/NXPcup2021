#include "CCTR_img_proc.h"

int Ligne_Filtre_Gaussien(unsigned char img[128], unsigned char buffer[128])
{
	for(int i=1; i<127; i++)
		img[i]=(0.125*buffer[i-1]+0.75*buffer[i]+0.125*buffer[i+1]);
	img[0]=(0.75*buffer[0]+0.25*buffer[1]);
	img[127]=(0.75*buffer[127]+0.25*buffer[126]);
	return 0;
}

/*
Calcule la position des bords gauche et droite et identifie les configuration suivantes

0 = > 2 bords
1 => bord gauche
2 => bord droite
3 =>  pas de bord
 */

#define DIFF_RELATIF_SEUIL 0.1
#define IMG_BORD_SEUIL 0.8

int Ligne_Bord_Detecte(Bord *bord, unsigned char img[128])
{
	int img_max=0, img_min=1024;										//Q : Pourquoi 1024? 
	int diff[128];
	int diff_min=1024, diff_max=-1024;
	int i_min=0, i_max=127;
	int i_diff_min=0, i_diff_max=127;
	int moy_pix=0;
	/* Calcul les gradients minimum et maximum => ce sont les bords de la piste */
	for(int i=1;i<127;i++)
	{
		if (img[i] > img_max) { img_max= img[i]; i_max=i;}
		if (img[i] < img_min) { img_min= img[i]; i_min=i;}

		diff[i]=img[i+1]-img[i-1];
		if (diff[i]>diff_max) { diff_max=diff[i]; i_diff_max=i;}
		if (diff[i]<diff_min) { diff_min=diff[i]; i_diff_min=i;}

		moy_pix += img[i];
	}

	moy_pix = moy_pix/255;
	diff[0]=img[1]-img[0];
	diff[127]=img[127]-img[126];
	/*
PRINTF("diff ");
		for(int i=0;i<128;i++)
			PRINTF("%d ", diff[i]);
		PRINTF("\r\n");
	 */
	/* La piste étant symétrique on s'attend à des gradients assez proches */
	/* Sinon, on a perdu un bord */
	/* Le gradient du bord gauche est positif */
	/* Le gradient du bord droit est négatif */
	/* Vérifie que l'ordre est respecté */
	int diff_delta= diff[i_diff_min]+diff[i_diff_max];  /* L'écart entre les gradients un positif & un nul => idéal = 0 */
	float diff_delta_relatif_min=  diff_delta/(diff[i_max]+1.0);
	float diff_delta_relatif_max=  diff_delta/(diff[i_max]+1.0);
	//printf("%d %d\n", i_min, i_max);
	//printf("%d %d %d %d %f %f\n", i_diff_max, i_diff_min, diff[i_diff_max],  diff[i_diff_min], diff_delta_relatif_min,diff_delta_relatif_max);
	
	/*Les deux bords sont observés*/
	if (
			(i_diff_max < i_diff_min) &&
			(diff[i_diff_max]>0) && (diff[i_diff_min]<0)// &&
			//(fabs(diff_delta_relatif_min)<DIFF_RELATIF_SEUIL) && (fabs(diff_delta_relatif_max)<DIFF_RELATIF_SEUIL)
	)
	{
		bord->gauche= i_diff_max;
		bord->droite= i_diff_min;
		bord->cas = 0;
		return 0;
	}
	/* Il y a un bord ou aucun */
	/* Verifie les niveaux des bord gauche et droite */
	if (img[0] < IMG_BORD_SEUIL*img[127]) /* gauche est plus petit que droite => le bord gauche existe, pas le droite */
	{
		bord->gauche= i_diff_max;
		bord->droite= 127;
		bord->cas= 1;
		return 1;
	}

	if (img[127] < IMG_BORD_SEUIL*img[0]) /* droite est plus petit que gauche => le bord droite existe, pas le gauche */
	{
		bord->gauche= 0;
		bord->droite= i_diff_min;
		bord->cas= 2;
		return 2;
	}
	/* Si les valeurs de pixels sont élevées, on est a priori sur la piste */
	/*MODIFIE*/
	if (moy_pix > (255>>1))
	{
		bord->gauche= 0;
	    bord->droite= 127;
		bord->cas= 3;
		return 3; 
	}
	
	/*Si les valeurs de pixels sont moyennes/basses, on est en hors-piste*/

	return 4;
}

/*
Calcule la position moyenne des bords
 */
int Bord_Milieu(Bord bord)
{
	return (bord.gauche + bord.droite)/2;
}

/*
Calcule la vitesse du bord selon les configurations
 */

int Bord_Vitesse(int *perdu, Bord bord_old, Bord bord)
{

	int v;
	*perdu=0;
	if ((bord.cas == 0) && (bord_old.cas ==0))
	{
		v= ((bord.gauche + bord.droite) - (bord_old.gauche + bord_old.droite))/2;
		return v;
	}
	/* cas 0 0 déjà traité */
	if (((bord.cas == 0) || (bord.cas == 1)) && ((bord_old.cas ==0)||(bord_old.cas ==1)))
	{
		v= ((bord.gauche) - (bord_old.gauche));
		return v;
	}
	/* cas 0 0 déjà traité */
	if (((bord.cas == 0) || (bord.cas == 2)) && ((bord_old.cas ==0) || (bord_old.cas ==2)))
	{
		v= ((bord.droite) - (bord_old.droite));
		return v;
	}
	*perdu= 1;
	/* Dans tous les autres cas dès qu'on a perdu tous les bords, retourne 0 */
	return 0;
}

#if 0
#include <stdio.h>
void main(void)
{
	unsigned char buffer[]={
			12, 12, 12, 12, 8,  //4
			2, 2,
			100,

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128, //16

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,//16

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,//16

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,//16

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,//16


			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,//16

			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 128,
			128, 128, 128, 100,//16

			128, 128, 128, 128,
			128, 128, 128, 128,

			//80,
			// 8, 8,
			//10, 15, 15, 15, 15  //4
	};
	unsigned char img[128];
	Ligne_Filtre_Gaussien(img, buffer);
	for(int i=0; i<128; i++) printf("%d ", img[i]);
	printf("\n");
	Bord bord;
	Ligne_Bord_Detecte(&bord, img);
	printf("bord %d %d %d\n", bord.cas, bord.gauche, bord.droite);
}
#endif

