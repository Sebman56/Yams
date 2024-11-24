

#include <stdio.h>

#include <stdlib.h>

#include <time.h>


// *** Déclaration des variables


int n, A, B, C, D, E, NPlayer, NoJoueur, NbreD;

int Etat[][5];
char NomJoueur[10];

int TableauScore[5];

/*

int egaliteA;

int egaliteB;

int egaliteC;

int egaliteD;

int egaliteE;


int CompteurGrandeSuite;

int CompteurPetiteSuite;


int Somme;

*/

int NPlayer;


// *** Déclaration des prototype des fonctions

int Random();

int Tirage();

int NombreDeJoueur();

int RemplissageTableauEtat(); ///

int Tour();

/*

int CalculMoins8Plus25 ();

int PetiteSuite ();

int GrandeSuite ();

int Egalite();

int ConclusionEgalite();

*/


/* ****************************************** Developpement des fonctions */

/************************************************************************* */

int RemplissageTableauEtat()

{

int Etat[NPlayer][5]; // construction du tableau Etat

for (NoJoueur = 1; NoJoueur < NPlayer; NoJoueur++) //

{

Tour();

}

printf(" \n Joueur %i: %i, %i, %i, %i, %i", NoJoueur, Etat[NoJoueur][0], Etat[NoJoueur][1], Etat[NoJoueur][2], Etat[NoJoueur][3], Etat[NoJoueur][4]);

}


/************************************************************************* */

int Tour()

{

int Etat[NPlayer][5];

for (NbreD = 0; NbreD < 5; NbreD++) // Lancé de 5 dés

{

Random();

//printf("\n Avant %i ", Etat[NoJoueur][NbreD]);

Etat[NoJoueur][NbreD] = n;

//printf("\t Après %i ", Etat[NoJoueur][NbreD]);

//printf("\t n=%i ", n);

// printf (" \n Joueur %i: %i, %i, %i, %i, %i", NoJoueur, Etat[NoJoueur][NbreD],Etat[NoJoueur][NbreD],Etat[NoJoueur][NbreD],Etat[NoJoueur][NbreD],Etat[NoJoueur][NbreD]);

}

printf("\n");

// printf ("\n\t Tirage Joueur %i: %i",NPlayer, n);

printf(" \n Joueur %i: %i, %i, %i, %i, %i", NoJoueur, Etat[NoJoueur][0], Etat[NoJoueur][1], Etat[NoJoueur][2], Etat[NoJoueur][3], Etat[NoJoueur][4]);

}


/************************************************************************ */

int Random()

{

n = rand() % 6 + 1;

return n;

}


/************************************************************************ */

int NombreDeJoueur()

{

printf("\n\t Entrez le nombre de joueur (Max 6): ");

scanf("%i", &NPlayer);


if (NPlayer < 2 || NPlayer > 6)

{

printf("\n\t Nombre de joueur erroné, au revoir.");

return 0;

exit(0);

}

int Etat[NPlayer][5]; // construction du tableau Etat

}


/* ********************** Remplissage total et automatique du tableau Etat

int Etat[NPlayer][5]; // construction du tableau Etat

int i, j;

for (i=0; i<NPlayer; i++)

{

printf ("\n");

for (j=0; j<5; j++)

{

Random();

Etat[i][j] = n;

//Etat[0][j] = i;

printf ("\n\t Tirage Joueur %i: %i",i, n);

}

}

printf ("\n");

printf("\n================================");

// printf ("\n\t Tirage Joueur %i: %i\n",i-1, n-4);

printf ("\n\n");

*/


/* *************************************** Affichage Etat

for (i=0 ; i<NPlayer ; i++)

{

for (j= 0; j<5 ; j++)

{

printf (" \n Joueur %i: %i, %i, %i, %i, %i", i+1, Etat[i][j], Etat[i][j], Etat[i][j], Etat[i][j], Etat[j][j]);

}

printf ("\n");

} // printf (" Joueur %i: %i, %i, %i, %i, " Etat [i][])

*/


int main()

{

printf("\n\n\t Jeu de Yams:\n");

// SaisieDes();

// Tirage();

/* Egalite();

GrandeSuite();

PetiteSuite();

CalculMoins8Plus25 ();

ConclusionEgalite();

*/

NombreDeJoueur();

RemplissageTableauEtat();

// Tour ();

// RemplissageTableauEtat(); ///

// AffichageTableau(); ///

/*

printf("\n\n");

printf ("\n\tLes valeurs des 05 Dés sont: %i, %i, %i, %i, %i\n", A, B, C, D, E);

printf ("\n");

*/

return 0;

exit(0);

}


/* ************************************************** Fonction Tirage par 03 manières ****/

/* ****************************************************************************************/

/* *** Fonction Tirage par saisie de l'utilisateur */

/*

int Tirage()

{

printf ("\n");


printf("Entrez la valeur du Dé numéro A: ");

scanf ("%i",&A);

printf("Entrez la valeur du Dé numéro B: ");

scanf ("%i",&B);

printf("Entrez la valeur du Dé numéro C: ");

scanf ("%i",&C);

printf("Entrez la valeur du Dé numéro D: ");

scanf ("%i",&D);

printf("Entrez la valeur du Dé numéro E: ");

scanf ("%i",&E);


printf ("\n\tLes valeurs des 05 Dés sont: %i, %i, %i, %i, %i\n", A,

B, C, D, E);

return 0;

}

*/


/* *** Fonction Tirage avec avec le randomize */

/* ****/

int Tirage()

{

srand(time(NULL));

printf("\n");

Random();

A = n;

printf("Dé numéro A - %i\n", A);


Random();

B = n;

printf("Dé numéro B - %i\n", B);


Random();

C = n;

printf("Dé numéro C - %i\n", C);


Random();

D = n;

printf("Dé numéro D - %i\n", D);


Random();

E = n;

printf("Dé numéro E - %i\n", E);


// TableauScore[5] = { A , B , C , D , E}; //1 , 2 , 3 , 56, 76 };


printf("\n");

return 0;

}


/* *** Fonction Tirage avec des variables fixes */

/*

int Tirage()

{

printf ("\n");


A = 1;

printf("Dé numéro A - %i\n",A);


B = 1;

printf("Dé numéro B - %i\n",B);


C = 2;

printf("Dé numéro C - %i\n",C);


D = 3;

printf("Dé numéro D - %i\n",D);


E = 4;

printf("Dé numéro E - %i\n",E);


printf ("\n");

return 0;

}

*/
