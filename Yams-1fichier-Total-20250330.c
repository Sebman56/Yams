/**********************************************************************************
 * *** Jeux de Yams ***************************************************************
 * *** Lancement de 05 Dés afin de faire des combinaisons imposées à tour de rôle.
 *********************************************************************************
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/****** Déclaration des variable et des tableaux  */
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/


/***** Declaration des variables créant la partie, feuille de match, nombre de joueur  */
int NPlayer;
int LignePartie;
int ScoreLigne;
int nbLignes = 16;

/***** Declaration des variables servant au contrôle et vérification des Dés  */
int egaliteA;
int egaliteB;
int egaliteC;
int egaliteD;
int egaliteE;

int Compteur;
int CompteurPetiteSuite;
int CompteurGrandeSuite;
int Somme;

/***** Declaration des variables servant à l'intérrogation des Dés  */
int i;
int n;
int A;
int B;
int C;
int D;
int E;

int NLance;
int NoJoueur;
int NbreD;
int Etat [5];
int Manche;

char ReponseVide[10];
char ReponseA [10];
char ReponseB [10];
char ReponseC [10];
char ReponseD [10];
char ReponseE [10];


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
    {"Bonus         ",63},
    {"Premier Total ", 0},
    {"Brelan        ", 0},
    {"Carre         ", 0},
    {"Full          ",25},
    {"Yams          ",50},
    {"Petite suite  ",30},
    {"Grande suite  ",40},
    {"Chance        ", 0},
    {"Deuxieme Total", 0}
};

//char **ListeJoueurs = (char **)malloc( * sizeof(char *));

void AffichageScoreEtPartie(int nbLignes, int NPlayer, char **ListeJoueurs, int ScorePartie[][NPlayer]);

/***** Delarations des fonction de lancement des Dés  */
int Tirage(void);
int SaisieDes(void);
int Random(void);

/***** Delarations des fonction de lecture des Dés  */
int LectureDes ();
int CalculMoins8Plus25();
int PetiteSuite();
int GrandeSuite();
int Egalite();
int ConclusionEgalite();

/***** Delarations des fonctions de des 03 tours des joueurs  */
int Lance1();
int Lance2et3();


char **ListeJoueurs;


/**********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
/****** Developpement des fonctions  */
/*********************************************************************************************************************************************/
/*********************************************************************************************************************************************/
int main() {

    printf("\033[2J\033[H"); // Efface l'écran et déplace le curseur en haut à gauche
    printf ("\n\t# Yams - Jeu du Yams \n");
    printf ("\n\tLe jeu de Yams est un jeu qui se joue avec  05 dés.\n");
    printf ("\tIl y a une feuille de score, avec des combinaisons de Dés pour faire des points\n\n");
    printf ("\tChaque joueur lance les 05 Dés afin de faire des combinaisons.\n");
    printf ("\tIl a un total de 03 lancés pour faire une combinaison désirée qu\'il faut choisir sur la feuille de score\n\n");
    printf ("\tA chaque tour le tableau doit être rempli, sinon on y marque 0 dans une des cases des combinaisons, au choix.\n");
    printf ("\tChaque case de combinaison est remplie une seul fois.Tout remplissage et irreversible.\n\n");
    printf ("\tLorsque la feuille de score est remplie ont fait les totaux.\n");

    printf("\nQuel est le nombre de joueur ? > ");
    scanf("%d", &NPlayer);

    char **ListeJoueurs = (char **)malloc(NPlayer * sizeof(char *));

    for (int i = 1; i < NPlayer+1; i++) {
        ListeJoueurs[i] = (char *)malloc(20 * sizeof(char));
        printf("\nNom du joueur %d : ", i);
        scanf("%s", ListeJoueurs[i]);
    }

    printf("\n\bBonjour ");
    for (int i = 1; i < NPlayer+1; i++) {
        printf(" %s, ", ListeJoueurs[i]);
    }
    printf(" Merci de venir jouer.\n");

    int ScorePartie[16][NPlayer];

    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j <= NPlayer; j++) {
            ScorePartie[i][j] = 0;
        }
    }
    /**************************************************************************************************************** La partie commence ici */
    for (int Tour = 0; Tour < 20 ; Tour++) 
    {   
        //Tirage ();
        int Manche =1;
        for (int Manche=1 ;  Manche < NPlayer+1; Manche ++  )
        {
            NLance = 1;
            printf("\033[2J\033[H"); // Efface l'écran et déplace le curseur en haut à gauche
            printf("\n\b****** Tour: %i  ***** Joueur: %s ***** Lancé: %i\n", Tour, ListeJoueurs[Manche], NLance);
            printf("\n");
            Lance1(); 
            printf ("\n\t111 Les valeurs du premier lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
            LectureDes ();
            printf ("\n\t111 Les valeurs du premier lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n",Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
               
            NLance =2; 
            Lance2et3(); 
            printf("\033[2J\033[H"); // Efface l'écran et déplace le curseur en haut à gauche
            printf("\n\b****** Tour: %i  ***** Joueur: %s ***** Lancé: %i\n", Tour, ListeJoueurs[Manche], NLance);
            printf ("\n\t222 Les valeurs du deuxieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
            LectureDes ();
            printf ("\n\t222 Les valeurs du deuxieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
      
            NLance=3;
            Lance2et3 ();
            printf("\033[2J\033[H"); // Efface l'écran et déplace le curseur en haut à gauche
            printf("\n\b****** Tour: %i  ***** Joueur: %s ***** Lancé: %i\n", Tour, ListeJoueurs[Manche], NLance);
            printf ("\t333 Les valeurs du troisieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
            LectureDes ();
            printf ("\t333 Les valeurs du troisieme lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
        
//            printf("\033[2J\033[H"); // Efface l'écran et déplace le curseur en haut à gauche
            printf(" \n*****************************************************************");
            printf("\n\b****** Tour: %i  ***** Joueur: %s ***** Lancé: %i", Tour, ListeJoueurs[Manche], NLance);
            printf ("\n\t*** Les valeurs du dernier lancé des 05 Dés sont: %i, %i, %i, %i, %i ***\n\n", Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
            AffichageScoreEtPartie(nbLignes, NPlayer, ListeJoueurs, ScorePartie);

            int LigneRemplie = 0;
            while (LigneRemplie<1)
            {
                printf("\nQuelle ligne voulez vous remplir %s ?\t:", ListeJoueurs[Manche]);
                scanf("%d", &LignePartie);

                if (LignePartie < 1 || LignePartie > nbLignes) 
                    {
                        printf("Ligne invalide.\n");
                        LigneRemplie =0;
                        continue;
                    }
                else if (ScorePartie[LignePartie-1][Manche] > 0)
                    {
                        printf("Cette ligne est déjà remplie: %i\n", ScorePartie[LignePartie-1][Manche]);
                        LigneRemplie =0;
                        continue;
                    }
                else
                    {
                        int joueur = Manche;
                        printf("\nQuel score inscrivons nous dans la ligne  %i de %s ? ", LignePartie, ListeJoueurs[Manche]);
                        scanf("%d", &ScoreLigne);
                        printf("\n\t Remplissage de de la feuille de partie.");
                        ScorePartie[LignePartie-1][Manche] = ScoreLigne;
                        LigneRemplie =1;
                        break;
                    }
                }
            printf("\nLigne %d, joueur %d remplie avec le score %d.\n", LignePartie, Manche, ScoreLigne);
            //return char ListeJoueurs[Manche];
            
            }
        printf("\n\b****** Fin du  Tour: %i ****\n", Tour);
        AffichageScoreEtPartie(nbLignes, NPlayer, ListeJoueurs, ScorePartie); 
    }

/****************************************Fin de partie libération de la memoire (malloc) */
    printf("\n\bLibération de la memoire stockant les joueurs.\n");
    for (int i = 0; i < NPlayer; i++) 
        {
        free(ListeJoueurs[i]);
        }
    free(ListeJoueurs);
    printf("\n\b Mémoire libérée.\n");
    return 0;
} /************************************************************************************************************ Fin du main  */
/******************************************************************************************************************************************************* */
/******************************************************************************************************************************************************* */
/******************************************************************************************************************************************************* */

/***** Fonction d'affichage de la partie */
void AffichageScoreEtPartie(int nbLignes, int NPlayer, char **ListeJoueurs, int ScorePartie[][NPlayer]) 
{
    printf("\n -*** Feuille de SCORE: ***-\n");
    
    for (int i = 0; i < nbLignes; i++) 
    {
        if ((i==6) || (i==9) || (i==16))
            {
                printf("\n");
            }
        printf(" Ligne[%d]: ", i+1);
        for (int j = 1; j <= NPlayer; j++) 
        {
            printf(" %s, %d \t\t\t %s[%d] = %d ***",
                   TableauScore[i].Nomligne,
                   TableauScore[i].ScoreLigne,
                   ListeJoueurs[j],
                   j,
                   ScorePartie[i][j]);
        }
        printf("\n");
    }
}

/*************************************************************************************************************** */
/*************************************************************************************************************** */
/*************************************************************************************************************** */
/***** Lancé N° 1  */

int Lance1()
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

/*
    Etat[1] = 1;
    Etat[2] = 1;
    Etat[3] = 1;
    Etat[4] = 2;
    Etat[5] = 3;
*/
    printf("\n");
    return Etat [1,2,3,4,5];
}


/*************************************************************************************************************** */
/*************************************************************************************************************** */
/*************************************************************************************************************** */
/***** Lancé N° 2 & 3  */

int Lance2et3(char **ListeJoueurs, int Manche)
{
    A = Etat[1];
    B = Etat[2];
    C = Etat[3];
    D = Etat[4];
    E = Etat[5];

    fgets(ReponseVide, sizeof(ReponseVide), stdin); // Lire la réponse et ne pas prendre le retour chariot précédent
    while (1)  //Interrogation sur le dé "A"
    { // Boucle infinie jusqu'à obtenir une réponse valide
        printf ("\nVoulez-vous relancer le Dé \"A\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non)): ", Etat[1]);
        fgets(ReponseA, sizeof(ReponseA), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
        if (((ReponseA [0]== 'o') || (ReponseA [0]== 'O')|| (ReponseA [0]== 'O')) && (ReponseA [1] == '\n'))
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
        printf ("\n Voulez-vous relancer le Dé \"B\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non)): ", Etat[2]);
        fgets(ReponseB, sizeof(ReponseB), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
        if (((ReponseB [0]== 'o') || (ReponseB [0]== 'O')|| (ReponseB [0]== 'O')) && (ReponseB [1] == '\n'))
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
        printf ("\n Voulez-vous relancer le Dé \"C\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non)): ", Etat[3]);
        fgets(ReponseC, sizeof(ReponseC), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
        if (((ReponseC [0]== 'o') || (ReponseC [0]== 'O')|| (ReponseC [0]== 'O')) && (ReponseC [1] == '\n'))
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
        printf ("\n Voulez-vous relancer le Dé \"D\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non)): ", Etat[4]);
        fgets(ReponseD, sizeof(ReponseD), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
        if (((ReponseD [0]== 'o') || (ReponseD [0]== 'O')|| (ReponseD [0]== 'O')) && (ReponseD [1] == '\n'))
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
        printf ("\n Voulez-vous relancer le Dé \"E\" qui vaut %i ? (\"o\" ou appuyez sur Entrée pour non)): ", Etat[5]);
        fgets(ReponseE, sizeof(ReponseE), stdin); // Lire la réponse Supprimer le saut de ligne à la fin de la chaîne
        if (((ReponseE [0]== 'o') || (ReponseE [0]== 'O')|| (ReponseE [0]== 'O')) && (ReponseE [1] == '\n'))        
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
}/***** Fin de Lance2et3*/









































/******************************************************************************** */
/******************************************************************************** */
/**** Fonction des Verification des Dés  */



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

   /* *** Detection du Yams */
   if ((A == B) && (B == C) && (C == D) && (D == E))   { printf ("\n\t\t  !!! Yams détecté. !!!\n");}

   egaliteA = 0;
   if (A == B) {egaliteA = egaliteA +1;}
   if (A == C) {egaliteA = egaliteA +1;}
   if (A == D) {egaliteA = egaliteA +1;}
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
   if (E == D) {egaliteE = egaliteE +1;}
     if (egaliteE == 1) { printf ("\n\t\t Il y a une paire avec le Dé E");}
     if (egaliteE == 2) { printf ("\n\t\t Il y a un brelan  avec le Dé E");}
     if (egaliteE == 3) { printf ("\n\t\t Il y a un carré avec le Dé E");}

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