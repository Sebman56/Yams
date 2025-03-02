/**********************************************************************************
 * *** Jeux de Yams ***************************************************************
 * *** Lancement de 05 Dés afin de faire des combinaisons imposées à tour de rôle.
 *********************************************************************************
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#include <time.h>

int i;
int n;
int A;
int B;
int C;
int D;
int E;
int N;
int NoJoueur;
int NbreD;
int Etat[5];

char ReponseVide[10];
char ReponseA [10];
char ReponseB [10];
char ReponseC [10];
char ReponseD [10];
char ReponseE [10];

int NPlayer;

int egaliteA;
int egaliteB;
int egaliteC;
int egaliteD;
int egaliteE;

int Compteur;
int CompteurPetiteSuite;
int CompteurGrandeSuite;
int Somme;

// struct Feuille[16][8];
int ChoixLigneFeuille;
char NomLigne;
// int LigneFeuille;

struct LigneFeuille 
    { 
    char Nomligne[14];
    const int ScoreLigne;
    int ScoreJoueur1;
    int ScoreJoueur2;
    int ScoreJoueur3;
    int ScoreJoueur4;
    int ScoreJoueur5;
    int ScoreJoueur6; 
    };

    /* Tableau de structure LigneFeuille. */
    
struct LigneFeuille Feuille[16] =
    {
    {"As            " ,  1,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Deux          " ,  2,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Trois         " ,  3,  7 , 7 , 7 , 7 , 3 , 3 }, 
    {"Quatre        " ,  4,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Cinq          " ,  5,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Six           " ,  6,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Bonus         " , 63,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Premier Total " ,  0,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Brelan        " ,  0,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Carre         " ,  0,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Full          " , 25,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Yams          " , 50,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Petite suite  " , 30,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Grande suite  " , 40,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Chance        " ,  0,  0 , 0 , 0 , 0 , 0 , 0 }, 
    {"Deuxieme Total" ,  0,  0 , 0 , 0 , 0 , 0 , 0 }
    };


int tailleFeuilleScore = sizeof(Feuille);
int ChoixLigneFeuille;
int Score;
int LigneRemplie;

/************************************************************************ */
/* ****************************************** D claration des fonctions */
/************************************************************************* */
int NombreDeJoueur(void);
int Tirage(void);
int SaisieDes(void);
int Random (void);

int Egalite(void);
int GrandeSuite (void);
int PetiteSuite (void);
int ConclusionEgalite (void);
int CalculMoins8Plus25 (void);

int Tour1();
int Tour2et3();
int LectureDes ();

int RemplissageFeuille ();


int LectureFeuilleScore();



/************************************************************************ */
/* ****************************************** Developpement des fonctions */
/************************************************************************ */


int main()
{
    struct LigneFeuille LiveScore [16];
    memcpy(LiveScore, Feuille, tailleFeuilleScore);
    
    
    NombreDeJoueur();
    printf ("\n Nombre de joueur: %d ", NPlayer);
    
    int t;
    for (t=0; t < 13 ; t++)
    {
        Tirage ();
        Tour1();
        printf ("\n\tLes valeurs, premier lancé des 05 D s sont: %i, %i, %i, %i, %i\n",Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        printf(" \n Tableau Etat : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
            LectureDes ();
        printf ("\n\tLes valeurs, premier lancé des 05 D s sont: %i, %i, %i, %i, %i\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        printf(" \n Tableau Etat : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);

        Tour2et3();
            LectureDes ();
        printf(" \n Tableau Etat : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        Tour2et3 ();
        printf ("\n\tLes valeurs, deuxieme lancé des 05 D s sont: %i, %i, %i, %i, %i\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        printf(" \n Tableau Etat : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        Tour2et3 ();
            LectureDes ();
        printf ("\n\tLes valeurs, troisieme lancé des 05 D s sont: %i, %i, %i, %i, %i\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        printf(" \n Tableau Etat : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        printf(" \n\n\n");
    
        LigneRemplie = 0;
        while (LigneRemplie=1)
        {    
            printf("\n\tTour n°: %i", t);
            printf("\n\b Acces au tableau de score.\n\n");
            for (int i = 0; i < 16; i++)
            {
                printf (" Ligne  %i --> %s,\b %d, \b  %d,%d,%d,%d,%d,%d.\n",
                i+1,
                LiveScore[i].Nomligne,
                LiveScore[i].ScoreLigne,
                LiveScore[i].ScoreJoueur1,
                LiveScore[i].ScoreJoueur2,
                LiveScore[i].ScoreJoueur3,
                LiveScore[i].ScoreJoueur4,
                LiveScore[i].ScoreJoueur5,
                LiveScore[i].ScoreJoueur6
                );
            }

            printf("\n\tIl faut saisir une ligne de la feuille de score : ");
            scanf("%i",&ChoixLigneFeuille);

            printf ("\n\tQuel score écrivons-nous dans la %i ème ligne : ", ChoixLigneFeuille);
            scanf ("%i", &Score);

            if (LiveScore[ChoixLigneFeuille-1].ScoreJoueur1 != 0) 
            {
                printf("\n\bCette ligne est déjà remplie %i.\n",LiveScore[ChoixLigneFeuille-1].ScoreJoueur1 );
                LigneRemplie = 0;
                continue;
            }
            else 
            {
            LiveScore[ChoixLigneFeuille-1].ScoreJoueur1 = Score;
            LigneRemplie = 1;
            printf("La ligne %i a été remplie.", LiveScore[ChoixLigneFeuille-1].ScoreJoueur1);
            break;
            }
        }
    }

    return 0;
    exit(0);
}


/************************************************************************ */
/* ******************* Developpement des fonctions de gestion des joueurs */
/************************************************************************ */
int NombreDeJoueur()
{
 printf("\n\t Entrez le nombre de joueur (Max 6): ");
 scanf("%i", &NPlayer);
 //fgets(NPlayer, sizeof(NPlayer), stdin); // Lire la réponse

 if (NPlayer < 1 || NPlayer > 6)
 {
 printf("\n\t Nombre de joueur erron , au revoir.");
 return NPlayer;
 exit(0);
 }
// int Feuille[NPlayer][imperatif]; // construction du tableau de la feuille de route
}



int Tour1()
{
// int Etat[NPlayer][5];
 for (NbreD = 1; NbreD < 6; NbreD++) // Lanc de 5 d s
 {
 Random();
 Etat[NbreD] = n;
 }
 A = Etat[1];
 B = Etat[2];
 C = Etat[3];
 D = Etat[4];
 E = Etat[5];
 printf("\n");
 // printf ("\n\t Tirage Joueur %i: %i",NPlayer, n);
 printf(" \n Tour Joueur : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
 // Lecture ();
 return Etat [1,2,3,4,5];
}

int Tour2et3()
{
 printf(" \n Tour entrée : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
 fgets(ReponseVide, sizeof(ReponseVide), stdin); // Lire la réponse et ne pas prendre le retour chariot précédent
 
 //Interrogation sur le dé "A" 
 while (1) 
 { // Boucle infinie jusqu'à obtenir une réponse valide
 printf ("\n Voulez_vous relancer le Dé \"A\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[1]);
 fgets(ReponseA, sizeof(ReponseA), stdin); // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 if (((ReponseA [0]== 'o') || (ReponseA [0]== 'O')) && (ReponseA [1] == '\n'))
 {
 printf("Vous avez répondu oui.\n");
 Random();
 Etat[1] = n ;
 break; // Sortir de la boucle
 } 
 else if (ReponseA[0] == '\n')
 {
 printf("Vous avez répondu vous gardiez le résultat de A = %i.\n", Etat [1]);
 break; // Sortir de la boucle
 } 
 else {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
 }
 }


 //Interrogation sur le dé "B"
 while (1) 
 { // Boucle infinie jusqu'à obtenir une réponse valide
 printf ("\n Voulez_vous relancer le D \"B\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[2]);
 fgets(ReponseB, sizeof(ReponseB), stdin); // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 if (((ReponseB [0]== 'o') || (ReponseB [0]== 'O')) && (ReponseB [1] == '\n'))
 {
 printf("Vous avez répondu oui.\n");
 Random();
 Etat[2] = n ;
 break; // Sortir de la boucle
 } 
 else if (ReponseB[0] == '\n')
 {
 printf("Vous avez répondu vous gardiez le résultat de B = %i.\n", Etat [2]);
 break; // Sortir de la boucle
 } 
 else {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
 }
 }

 
 //Interrogation sur le dé "C"
 while (1) 
 { // Boucle infinie jusqu'à obtenir une réponse valide
 printf ("\n Voulez_vous relancer le D \"C\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[3]);
 fgets(ReponseC, sizeof(ReponseC), stdin); // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 if (((ReponseC [0]== 'o') || (ReponseC [0]== 'O')) && (ReponseC [1] == '\n'))
 {
 printf("Vous avez répondu oui.\n");
 Random();
 Etat[3] = n ;
 break; // Sortir de la boucle
 } 
 else if (ReponseC[0] == '\n') 
 {
 printf("Vous avez répondu vous gardiez le résultat de C = %i.\n", Etat [3]);
 break; // Sortir de la boucle
 } 
 else {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
 }
 }



 //Interrogation sur le dé "D"
 while (1) 
 { // Boucle infinie jusqu'à obtenir une réponse valide
 printf ("\n Voulez_vous relancer le D \"D\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[4]);
 fgets(ReponseD, sizeof(ReponseD), stdin); // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 if (((ReponseD [0]== 'o') || (ReponseD [0]== 'O')) && (ReponseD [1] == '\n')) 
 {
 printf("Vous avez répondu oui.\n");
 Random();
 Etat[4] = n ;
 break; // Sortir de la boucle
 } 
 else if (ReponseD[0] == '\n') 
 {
 printf("Vous avez répondu vous gardiez le résultat de D = %i.\n", Etat [4]);
 break; // Sortir de la boucle
 } 
 else {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
 }
 }

 //Interrogation sur le dé "E"
 while (1) 
 { // Boucle infinie jusqu'à obtenir une réponse valide
 printf ("\n Voulez_vous relancer le D \"E\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[5]);
 fgets(ReponseE, sizeof(ReponseE), stdin); // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 if (((ReponseE [0]== 'o') || (ReponseE [0]== 'O')) && (ReponseE [1] == '\n')) 
 {
 printf("Vous avez répondu oui.\n");
 Random();
 Etat[5] = n ;
 break; // Sortir de la boucle
 } 
 else if (ReponseE[0] == '\n') 
 {
 printf("Vous avez répondu vous gardiez le résultat de E = %i.\n", Etat [5]);
 break; // Sortir de la boucle
 } 
 else {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
 }
 }
 
 printf(" \n Tour2&3 sortie Joueur : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
 return Etat [1,2,3,4,5];
}


int LectureFeuilleScore ()
{
    /* Affichage du tableau*/
    printf ("\n\b\b\b Lancement de la lecture de la Feuille de score.\n");
    for (int i = 0; i < 16; i++) 
        {
            printf (" %s,\b %d, \b  %d,%d,%d,%d,%d,%d.\n", 
            Feuille[i].Nomligne,
            Feuille[i].ScoreLigne,
            Feuille[i].ScoreJoueur1,
            Feuille[i].ScoreJoueur2,
            Feuille[i].ScoreJoueur3, 
            Feuille[i].ScoreJoueur4,
            Feuille[i].ScoreJoueur5,
            Feuille[i].ScoreJoueur6                
            );
        }
}

/************************************************************************ */
/* ********************* Developpement de remplissage de la feuille score */
/************************************************************************ */

/* 

Plan:

Tant que Feuille non rempli
-> Selection joueur
    -> Tirage
    -> Stockage dans Etat[]
    -> Verification Etat []
    -> Tirage 2 et 3 ou pas.
    -> Proposition Feuille
    -> Remplissage de feuille
    ->     

*/
/*

int RemplissageFeuille ()
{
    int ChoixLigneFeuille;
    struct LigneFeuille 
        { 
        char Nomligne;
        const ScoreLilgne;
        int ScoreJoueur1;
        int ScoreJoueur2;
        int ScoreJoueur3;
        int ScoreJoueur4;
        int ScoreJoueur5;
        int ScoreJoueur6; 
        };
 
   LigneFeuille Feuille[16][8] =
        {
        {{'As'},{ 1},{ 0},{0},{0},{0},{0},{0}},{
        {'Deux'},{2},{ 0},{0},{0},{0},{0},{0}},{
        {'Trois'},{3},{ 0},{0},{0},{0},{0},{0}},{
        {'Quatre'},{4},{ 0},{0},{0},{0},{0},{0}},{
        {'Cinq'},{5},{ 0},{0},{0},{0},{0},{0}},{
        {'Six'},{6},{ 0},{0},{0},{0},{0},{0}},{
        {'Bonus'},{63},{ 0},{0},{0},{0},{0},{0}},{
        {'Premier Total'},{ 0},{0},{0},{0},{0},{0}},{
        {'Brelan'},{0},{ 0},{0},{0},{0},{0},{0}},{
        {'Carre'},{0},{ 0},{0},{0},{0},{0},{0}},{
        {'Full'},{25},{ 0},{0},{0},{0},{0},{0}},{
        {'Yams'},{50},{ 0},{0},{0},{0},{0},{0}},{
        {'Petite suite'},{30},{ 0},{0},{0},{0},{0},{0}},{
        {'Grande suite'},{40},{ 0},{0},{0},{0},{0},{0}},{
        {'Chance'},{0},{ 0},{0},{0},{0},{0},{0}},{
        {'Deuxieme Total'},{0},{ 0},{0},{0},{0},{0},{0}}
        };

    /* Affichage du tableau
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("Valeur: %d, Caractère: %c\n", tableau[i][j].valeur, tableau[i][j].caractere);
        }
        printf("\n");
    */
    
/*
 printf(" \n Tirage finale : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
 printf(" \n Comment remplissez vous la feuille de score ?");

 while (1) 
    { // Boucle infinie jusqu'à obtenir une réponse valide
    for (i =0 ; i <=16; i++)
        {
        printf ("\n Score de la ligne %i : %i", i, Feuille[NoJoueur][i]);
        };
    printf ("\n Tapez la ligne que vous voulez validez: %i", ChoixLigneFeuille);
    scanf("%i",&LigneFeuille);
//    fgets(LigneScore, sizeof(LigneScore), stdin);

    if ((ChoixLigneFeuille <1) || (ChoixLigneFeuille >16))
        {
        printf("Numéro de ligne invalide. Veuillez entrez un numéro entre 1 et 14.\n");
        continue;
        }
    else 
        {
        printf ("\n Vous allez saisirun score pour la ligne %i.", Feuille[NoJoueur][ChoixLigneFeuille]);
        printf ("");

        break;
        }
    }
    printf ("\n\b\b\b Fin de la saisie de feuille.\n\n");
}


 // Lire la réponse
 // Supprimer le saut de ligne à la fin de la chaîne
 // ReponseA[strcspn(ReponseA, "\n")] = 0;
 // Vérification de la réponse
 /*   if (((ReponseE [0]== 'o') || (ReponseE [0]== 'O')) && (ReponseE [1] == '\n')) 
    {
        printf("Vous avez répondu oui.\n");
        Random();
        Etat[5] = n ;
        break; // Sortir de la boucle
    } 
    else if (ReponseE[0] == '\n') 
    {
        printf("Vous avez répondu vous gardiez le résultat de E = %i.\n", Etat [5]);
        break; // Sortir de la boucle
    } 
    else 
    {
        printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
    }
 }*/










/************************************************************************ */
/* ********** Developpement des fonctions de Lecture v rification des d s */
/************************************************************************ */

int LectureDes ()
{
 CalculMoins8Plus25();
 PetiteSuite();
 GrandeSuite();
 Egalite();
 ConclusionEgalite();
 return 0;
}

int CalculMoins8Plus25 ()
{
 Somme = A+ B + C + D + E;
 printf ("\n\t Calcul du moins 8 et plus 25.\n");
 if ((Somme) < 8)
 {printf ("\t\t *** Moins 8 d tect .\n");}

 if ((Somme) > 25)
 {printf ("\t\t *** Plus 25 d tect .\n");}

 if ((Somme >= 8) && (Somme <= 25))
 {printf ("\t\t *** Pas de moins 8 ou de plus 25 d tect . --- %i --\n",Somme);}
}

int PetiteSuite ()
{
 printf ("\n\t Calcul de Petite suite.\n"); 
 if
 (
 ((A == 1) || (B== 1) || (C== 1) || (D== 1) || (E== 1))
 && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
 && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
 && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
 )
 {
 printf("\t\t *** Suite 1234 detect e.\n");
 //printf("\t rappel valeur: %i, %i, %i, %i, %i",A,B,C,D,E);
 CompteurPetiteSuite++;
 }

 if
 (
 ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
 && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
 && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
 && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
 )
 {printf("\t\t *** Suite 2345 detect e.\n");
 CompteurPetiteSuite++;}

 if
 (
 ((A == 6) || (B == 6) || (C == 6) || (D == 6) || (E == 6))
 && ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
 && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
 && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
 )
 {printf("\t\t *** Suite 3456 detect e.\n");
 CompteurPetiteSuite++;}

 if (CompteurPetiteSuite == 0)
 {printf ("\t\t *** Pas de Petite suite d tect e !!! \n");}
 //printf ("\n");
}


int GrandeSuite ()
{
 printf ("\n\t Calcul de Grande suite.\n");

 /* Verification de la somme de 4 des 5 D s *//*1234 = 10*/

 if
 (
 ((A == 1) || (B== 1) || (C== 1) || (D== 1) || (E== 1))
 && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
 && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
 && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
 && ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
 )
 {
 printf("\t\t *** Grande Suite 12345 detect e.\n");
 //printf("\t rappel valeur: %i, %i, %i, %i, %i",A,B,C,D,E);
 CompteurGrandeSuite++;
 }

 if
 (
 ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
 && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
 && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
 && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
 && ((A == 6) || (B == 6) || (C == 6) || (D == 6) || (E == 6))
 )
 {printf("\t\t *** Grande Suite 23456 detect e.\n");
 CompteurGrandeSuite++;}

 if (CompteurGrandeSuite == 0)
 {printf ("\t\t *** Pas de Grande suite d tect e !!! \n");}
 //printf ("\n");
}


int Egalite()
{
 printf ("\n\t D tection de D s identiques.");
 egaliteA = 0;
 if (A == B) {egaliteA = egaliteA +1;}
 if (A == C) {egaliteA = egaliteA +1;}
 if (A == D) {egaliteA = egaliteA +1;}
 if (A == E) {egaliteA = egaliteA +1;}
 if (egaliteA == 1) { printf ("\n\t\t Il y a une paire avec le D A");}
 if (egaliteA == 2) { printf ("\n\t\t Il y a un brelan avec le D A");}
 if (egaliteA == 3) { printf ("\n\t\t Il y a un carr avec le D A");}

 egaliteB = 0;
 if (B == A) {egaliteB = egaliteB +1;}
 if (B == C) {egaliteB = egaliteB +1;}
 if (B == D) {egaliteB = egaliteB +1;}
 if (B == E) {egaliteB = egaliteB +1;}
 if (egaliteB == 1) { printf ("\n\t\t Il y a une paire avec le D B");}
 if (egaliteB == 2) { printf ("\n\t\t Il y a un brelan avec le D B");}
 if (egaliteB == 3) { printf ("\n\t\t Il y a un carr avec le D B");}

 egaliteC = 0;
 if (C == A) {egaliteC = egaliteC +1;}
 if (C == B) {egaliteC = egaliteC +1;}
 if (C == D) {egaliteC = egaliteC +1;}
 if (C == E) {egaliteC = egaliteC +1;}
 if (egaliteC == 1) { printf ("\n\t\t Il y a une paire avec le D C");}
 if (egaliteC == 2) { printf ("\n\t\t Il y a un brelan avec le D C");}
 if (egaliteC == 3) { printf ("\n\t\t Il y a un carr avec le D C");}

 egaliteD = 0;
 if (D == A) {egaliteD = egaliteD +1;}
 if (D == B) {egaliteD = egaliteD +1;}
 if (D == C) {egaliteD = egaliteD +1;}
 if (D == E) {egaliteD = egaliteD +1;}
 if (egaliteD == 1) { printf ("\n\t\t Il y a une paire avec le D D");}
 if (egaliteD == 2) { printf ("\n\t\t Il y a un brelan avec le D D");}
 if (egaliteD == 3) { printf ("\n\t\t Il y a un carr avec le D D");}

 egaliteE = 0;
 if (E == A) {egaliteE = egaliteE +1;}
 if (E == B) {egaliteE = egaliteE +1;}
 if (E == C) {egaliteE = egaliteE +1;}
 if (D == E) {egaliteE = egaliteE +1;}
 if (egaliteE == 1) { printf ("\n\t\t Il y a une paire avec le D E");}
 if (egaliteE == 2) { printf ("\n\t\t Il y a un brelan avec le D E");}
 if (egaliteE == 3) { printf ("\n\t\t Il y a un carr avec le D E");}

 /* *** Detection du Yams */
 if ((A == B) && (B == C) && (C == D) && (D ==E))
 { printf ("\n\t\t !!! Yams d tect . !!!");}
 printf ("\n");
}

int ConclusionEgalite()
{
 // printf ("\n");
 printf ("\n\t Nombre de D (s) identique(s) A: %i", egaliteA);
 printf ("\n\t Nombre de D (s) identique(s) B: %i", egaliteB);
 printf ("\n\t Nombre de D (s) identique(s) C: %i", egaliteC);
 printf ("\n\t Nombre de D (s) identique(s) D: %i", egaliteD);
 printf ("\n\t Nombre de D (s) identique(s) E: %i\n", egaliteE);
 printf ("\n");
}

/************************************************************************ */
int Random()
{
 n = rand() % 6 + 1;
 return n;
}




/************************************************************************* */
/* ****************************************** Developpement de la fonction Tirage ()*/
/************************************************************************* */

/*
int Tirage() // *** Fonction Tirage par saisie de l'utilisateur
{
 printf ("\n");

 printf("Entrez la valeur du D num ro A: ");
 scanf ("%i",&A);
 printf("Entrez la valeur du D num ro B: ");
 scanf ("%i",&B);
 printf("Entrez la valeur du D num ro C: ");
 scanf ("%i",&C);
 printf("Entrez la valeur du D num ro D: ");
 scanf ("%i",&D);
 printf("Entrez la valeur du D num ro E: ");
 scanf ("%i",&E);

 printf ("\n\tLes valeurs des 05 D s sont: %i, %i, %i, %i, %i\n", A,
B, C, D, E);
 return 0;
}
*/

int Tirage() // *** Fonction Tirage avec Random
{
 srand(time(NULL));
 printf("\n");
 Random();
 A = n;
 printf("D num ro A - %i\n", A);

 Random();
 B = n;
 printf("D num ro B - %i\n", B);

 Random();
 C = n;
 printf("D num ro C - %i\n", C);

 Random();
 D = n;
 printf("D num ro D - %i\n", D);

 Random();
 E = n;
 printf("D num ro E - %i\n", E);

 // TableauScore[5] = { A , B , C , D , E}; //1 , 2 , 3 , 56, 76 };

 printf("\n");
 return 0;
}

/*
int Tirage() // *** Fonction Tirage avec des variables fixe
{
 printf ("\n");

 A = 1;
 printf("D num ro A - %i\n",A);

 B = 1;
 printf("D num ro B - %i\n",B);

 C = 2;
 printf("D num ro C - %i\n",C);

 D = 3;
 printf("D num ro D - %i\n",D);

 E = 4;
 printf("D num ro E - %i\n",E);

 printf ("\n");
 return 0;
}
*/
