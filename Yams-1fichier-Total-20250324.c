#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int NPlayer;
int LignePartie;
int ScoreLigne;

int nbLignes = 16;

/*************************************************************************** */
/*************************************************************************** */
/***** Lancement des Dés  */

extern int Tirage(void);
extern int SaisieDes(void);
extern int Random(void);



/*************************************************************************** */
/*************************************************************************** */
/***** Contrôle et vérification des Dés  */
int egaliteA;
int egaliteB;
int egaliteC;
int egaliteD;
int egaliteE;

int Compteur;
int CompteurPetiteSuite;
int CompteurGrandeSuite;
int Somme;


int LectureDes ();
int CalculMoins8Plus25();
int PetiteSuite();
int GrandeSuite();
int Egalite();
int ConclusionEgalite();

/*************************************************************************** */
/*************************************************************************** */
/***** Interrogation  des Dés  */
int i;
int n;
int A;
int B;
int C;
int D;
int E;
// int NPlayer;
int NoJoueur;
int NbreD;
int Etat [5];

char ReponseVide[10];
char ReponseA [10];
char ReponseB [10];
char ReponseC [10];
char ReponseD [10];
char ReponseE [10];


int LectureDes ();
int Tour1();
int Tour2et3();


/**************************************************************************** */
/**************************************************************************** */
struct LigneTableauScore {
    char Nomligne[14];
    const int ScoreLigne;
};

struct LigneTableauScore TableauScore[16] = {
    {"As            ", 1},
    {"Deux          ", 2},
    {"Trois         ", 3},
    {"Quatre        ", 4},
    {"Cinq          ", 5},
    {"Six           ", 6},
    {"Bonus         ", 63},
    {"Premier Total ", 0},
    {"Brelan        ", 0},
    {"Carre         ", 0},
    {"Full          ", 25},
    {"Yams          ", 50},
    {"Petite suite  ", 30},
    {"Grande suite  ", 40},
    {"Chance        ", 0},
    {"Deuxieme Total", 0}
};

void AffichageScoreEtPartie(int nbLignes, int NPlayer, char **Joueur, int ScorePartie[][NPlayer]);

int main() {
    printf("\nQuel est le nombre de joueur ? ");
    scanf("%d", &NPlayer);

    char **Joueur = (char **)malloc(NPlayer * sizeof(char *));

    for (int i = 0; i < NPlayer; i++) {
        Joueur[i] = (char *)malloc(20 * sizeof(char));
        printf("\nNom du joueur %d : ", i + 1);
        scanf("%s", Joueur[i]);
    }

    printf("\n\bBonjour ");
    for (int i = 0; i < NPlayer; i++) {
        printf(" %s, ", Joueur[i]);
    }
    printf(" Merci de venir jouer.\n");

    int ScorePartie[16][NPlayer];

    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < NPlayer; j++) {
            ScorePartie[i][j] = 0;
        }
    }

    for (int Tour = 0; Tour < 2 * NPlayer; Tour++) 
    {
        printf("\n\b****** Tour: %i\n", Tour);

        
        Tirage ();

        Tour1();
        printf ("\n\t111 Les valeurs du premier lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n",Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        LectureDes ();

        Tour2et3();
        printf ("\n\t222 Les valeurs du deuxieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        LectureDes ();

        Tour2et3 ();
        printf ("\n\t333 Les valeurs du troisieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        LectureDes ();
        printf(" \n\n\n");
    
        printf ("\n\t*** Les valeurs du dernier lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        AffichageScoreEtPartie(nbLignes, NPlayer, Joueur, ScorePartie);

        printf("\nQuelle ligne voulez vous remplir ? ");
        scanf("%d", &LignePartie);

        if (LignePartie < 1 || LignePartie > nbLignes) {
            printf("Ligne invalide.\n");
            continue;
        }

        int joueur;
        printf("\nQuel joueur (1 à %d) ? ", NPlayer);
        scanf("%d", &joueur);

        if (joueur < 1 || joueur > NPlayer) {
            printf("Joueur invalide.\n");
            continue;
        }

        printf("\nQuel score inscrivons nous dans la ligne  %i de %s ? ", LignePartie, Joueur[joueur - 1]);
        scanf("%d", &ScoreLigne);

        ScorePartie[LignePartie - 1][joueur - 1] = ScoreLigne;
        printf("\nLigne %d, joueur %d remplie avec le score %d.\n", LignePartie, joueur, ScoreLigne);


        AffichageScoreEtPartie(nbLignes, NPlayer, Joueur, ScorePartie);
    }

//    AffichageScoreEtPartie(nbLignes, NPlayer, Joueur, ScorePartie);

    printf("\n\bLibération de la memoire stockant les joueurs.\n");
    for (int i = 0; i < NPlayer; i++) {
        free(Joueur[i]);
    }
    free(Joueur);
    printf("\n\b Mémoire libérée.\n");
    return 0;
}

void AffichageScoreEtPartie(int nbLignes, int NPlayer, char **Joueur, int ScorePartie[][NPlayer]) {
    printf("\nTableau complet AffichageScoreEtPartie:\n");
    for (int i = 0; i < nbLignes; i++) {
        printf("Score de la ligne[%d] : ", i + 1);
        for (int j = 0; j < NPlayer; j++) {
            printf(" %s, %d  %s[%d] = %d ***",
                   TableauScore[i].Nomligne,
                   TableauScore[i].ScoreLigne,
                   Joueur[j],
                   j,
                   ScorePartie[i][j]);
        }
        printf("\n");
    }
}

/******************************************************************************** */
/******************************************************************************** */
/**** Fonction des Verification des Dés  */

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


int CalculMoins8Plus25 ()
{
     Somme = A+ B + C + D + E;
     printf ("\n\t Calcul du moins 8 et plus 25.\n");
     if ((Somme) < 8)
     {printf ("\t\t *** Moins 8 détecté.\n");}

     if ((Somme) > 25)
     {printf ("\t\t *** Plus 25 détecté.\n");}

     if ((Somme >= 8) && (Somme <= 25))
     {printf ("\t\t  *** Pas de moins 8 ou de plus 25 détecté. --- %i --\n",Somme);}
}

int PetiteSuite ()
{
   printf ("\n\t Calcul de Petite suite.\n");

        /* Verification de la somme de 4 des 5 Dés *//*1234 = 10*/

   if
   (
   ((A == 1) || (B== 1) || (C== 1) || (D== 1) || (E== 1))
   && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
   && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
   && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
   )
     {
     printf("\t\t *** Suite 1234 detectée.\n");
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
        {printf("\t\t *** Suite 2345 detectée.\n");
        CompteurPetiteSuite++;}

   if
   (
    ((A == 6) || (B == 6) || (C == 6) || (D == 6) || (E == 6))
   && ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
   && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
   && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
   )
        {printf("\t\t *** Suite 3456 detectée.\n");
        CompteurPetiteSuite++;}

   if (CompteurPetiteSuite == 0)
     {printf ("\t\t *** Pas de Petite suite détectée !!! \n");}
     //printf ("\n");
}


int GrandeSuite ()
{
   printf ("\n\t Calcul de Grande suite.\n");

        /* Verification de la somme de 4 des 5 Dés *//*1234 = 10*/

   if
   (
   ((A == 1) || (B== 1) || (C== 1) || (D== 1) || (E== 1))
   && ((A == 2) || (B == 2) || (C == 2) || (D == 2) || (E == 2))
   && ((A == 3) || (B == 3) || (C == 3) || (D == 3) || (E == 3))
   && ((A == 4) || (B == 4) || (C == 4) || (D == 4) || (E == 4))
   && ((A == 5) || (B == 5) || (C == 5) || (D == 5) || (E == 5))
   )
     {
     printf("\t\t *** Grande Suite 12345 detectée.\n");
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
        {printf("\t\t *** Grande Suite 23456 detectée.\n");
        CompteurGrandeSuite++;}

   if (CompteurGrandeSuite == 0)
     {printf ("\t\t *** Pas de Grande suite détectée !!! \n");}
     //printf ("\n");
}


int Egalite()
{
   printf ("\n\t Détection de Dés identiques.");
   egaliteA = 0;
   if (A == B) {egaliteA = egaliteA +1;}
   if (A == C) {egaliteA = egaliteA +1;}
   if (A == E) {egaliteA = egaliteA +1;}
     if (egaliteA == 1) { printf ("\n\t\t Il y a une paire avec le Dé A");}
     if (egaliteA == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé A");}
     if (egaliteA == 3) { printf ("\n\t\t Il y a un carré avec le Dé A");}

   egaliteB = 0;
   if (B == A) {egaliteB = egaliteB +1;}
   if (B == C) {egaliteB = egaliteB +1;}
   if (B == D) {egaliteB = egaliteB +1;}
   if (B == E) {egaliteB = egaliteB +1;}
     if (egaliteB == 1) { printf ("\n\t\t Il y a une paire avec le Dé B");}
     if (egaliteB == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé B");}
     if (egaliteB == 3) { printf ("\n\t\t Il y a un carré avec le Dé B");}

   egaliteC = 0;
   if (C == A) {egaliteC = egaliteC +1;}
   if (C == B) {egaliteC = egaliteC +1;}
   if (C == D) {egaliteC = egaliteC +1;}
   if (C == E) {egaliteC = egaliteC +1;}
     if (egaliteC == 1) { printf ("\n\t\t Il y a une paire avec le Dé C");}
     if (egaliteC == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé C");}
     if (egaliteC == 3) { printf ("\n\t\t Il y a un carré avec le Dé C");}

   egaliteD = 0;
   if (D == A) {egaliteD = egaliteD +1;}
   if (D == B) {egaliteD = egaliteD +1;}
   if (D == C) {egaliteD = egaliteD +1;}
   if (D == E) {egaliteD = egaliteD +1;}
     if (egaliteD == 1) { printf ("\n\t\t Il y a une paire avec le Dé D");}
     if (egaliteD == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé D");}
     if (egaliteD == 3) { printf ("\n\t\t Il y a un carré avec le Dé D");}

   egaliteE = 0;
   if (E == A) {egaliteE = egaliteE +1;}
   if (E == B) {egaliteE = egaliteE +1;}
   if (E == C) {egaliteE = egaliteE +1;}
   if (D == E) {egaliteE = egaliteE +1;}
     if (egaliteE == 1) { printf ("\n\t\t Il y a une paire avec le Dé E");}
     if (egaliteE == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé E");}
     if (egaliteE == 3) { printf ("\n\t\t Il y a un carré avec le Dé E");}

   /* *** Detection du Yams */
   if ((A == B) && (B == C) && (C == D) && (D ==E))
   { printf ("\n\t\t  !!! Yams détecté. !!!");}
   printf ("\n");
}

int ConclusionEgalite()
{
   // printf ("\n");
   printf ("\n\t Nombre de Dé(s) identique(s) à A: %i", egaliteA);
   printf ("\n\t Nombre de Dé(s) identique(s) à B: %i", egaliteB);
   printf ("\n\t Nombre de Dé(s) identique(s) à C: %i", egaliteC);
   printf ("\n\t Nombre de Dé(s) identique(s) à D: %i", egaliteD);
   printf ("\n\t Nombre de Dé(s) identique(s) à E: %i\n", egaliteE);
   printf ("\n");
}

/************************************************************************ */
int Random()
{
   n = rand() % 6 + 1;
   return n;
}

int LectureDes ()
{
     CalculMoins8Plus25();
     PetiteSuite();
     GrandeSuite();
     Egalite();
     ConclusionEgalite();
     return 0;
}
/****************************************************************************** */
/******************************************************************************* */
/************************************************************************* */
/***** Gestion des tours  */

int Tour1()
{
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
//    printf(" \n 1er Lancé  : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
    return Etat [1,2,3,4,5];
}

int Tour2et3()
{
//    printf(" \n Tour entrée : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
    fgets(ReponseVide, sizeof(ReponseVide), stdin); // Lire la réponse et ne pas prendre le retour chariot précédent
    while (1)  //Interrogation sur le dé "A"
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\n Voulez_vous relancer le Dé \"A\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[1]);
        fgets(ReponseA, sizeof(ReponseA), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
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
        else 
        {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
        }
    }


    while (1)  //Interrogation sur le dé "B"
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\n Voulez_vous relancer le Dé \"B\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[2]);
        fgets(ReponseB, sizeof(ReponseB), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
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
        else 
        {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
        }
    }

 
    while (1)     //Interrogation sur le dé "C" 
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\n Voulez_vous relancer le Dé \"C\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[3]);
        fgets(ReponseC, sizeof(ReponseC), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
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
        else 
        {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
        }
    }


    while (1) //Interrogation sur le dé "D"
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\n Voulez_vous relancer le Dé \"D\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[4]);
        fgets(ReponseD, sizeof(ReponseD), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
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
        else 
        {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
        }
    }



    while (1) //Interrogation sur le dé "E"
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\n Voulez_vous relancer le Dé \"E\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non))", Etat[5]);
        fgets(ReponseE, sizeof(ReponseE), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
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
        else 
        {printf("Réponse invalide. Veuillez répondre par 'oui' ou rien.\n");
        }
    }
 
//    printf(" \n Tour2&3 sortie Joueur : %i, %i, %i, %i, %i", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
    return Etat [1,2,3,4,5];
}/***** Fin de Tour2et3*/
