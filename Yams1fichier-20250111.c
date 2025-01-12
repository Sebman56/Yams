#include <stdio.h>
#include <stdlib.h>
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

char ReponseA;
char ReponseB;
char ReponseC;
char ReponseD;
char ReponseE;

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

int Feuille[][14];


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

int RemplissageTableauEtat(); ///
int Tour1();
int Tour2et3();
int Lecture ();

/************************************************************************ */
/* ****************************************** Developpement des fonctions */
/************************************************************************ */


int main()
{
    NombreDeJoueur();
    printf ("\n Nombre de joueur:  %d ", NPlayer);

    Tirage ();
    Tour1();
    printf ("\n\tLes valeurs des 05 D s sont: %i, %i, %i, %i, %i\n", A, B, C, D, E);

    Lecture ();
    printf ("\n\tLes valeurs des 05 D s sont: %i, %i, %i, %i, %i\n", A, B, C, D, E);

    Tour2et3();


    printf(" \n\n\n");
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

   if (NPlayer < 1 || NPlayer > 6)
   {
      printf("\n\t Nombre de joueur erron , au revoir.");
      return 0;
      exit(0);
   }
//   int Feuille[NPlayer][imperatif];   // construction du tableau de la feuille de route
}



int Tour1()
{
//   int Etat[NPlayer][5];
   for (NbreD = 1; NbreD < 6; NbreD++) // Lanc  de 5 d s
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
   //   printf ("\n\t Tirage Joueur %i: %i",NPlayer, n);
   printf(" \n Tour Joueur : %i, %i, %i, %i, %i",  Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);
   // Lecture ();
}

int Tour2et3()
{
        
   printf(" \n Tour 2 & 3 : %i, %i, %i, %i, %i",  Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);

        printf ("\n Voulez_vous relancer le D  \"A\" qui vaut %i ?  (oui=O  ; Non =N)", A);
        scanf("%c", &ReponseA);
        if (ReponseA)  /* Functionally equivalent to if (x != 0) or if (x != false) */
        {
            Random();
            A = n ;
        }

        printf ("\n Voulez_vous relancer le D  \"B\" qui vaut %i ?  (oui=O  ; Non =N)", B);
        scanf("%c", &ReponseB);
        if (ReponseB)  /* Functionally equivalent to if (x != 0) or if (x != false) */
        {
            Random();
            B = n ;
        }
        

        printf ("\n Voulez_vous relancer le D  \"C\" qui vaut %i ?  (oui=O  ; Non =N)", C);
        scanf("%c", &ReponseC);
        if (ReponseC)  /* Functionally equivalent to if (x != 0) or if (x != false) */
        {
            Random();
            C = n ;
        }
        
        

        printf ("\n Voulez_vous relancer le D  \"D\" qui vaut %i ?  (oui=O  ; Non =N)", D);
        scanf("%c", &ReponseD);
        if (ReponseD)  /* Functionally equivalent to if (x != 0) or if (x != false) */
        {
            Random();
            D = n ;
        }


        printf ("\n Voulez_vous relancer le D  \"E\" qui vaut %i ?  (oui=O  ; Non =N)", E);
        scanf("%d", &ReponseE);
        if (ReponseE)  /* Functionally equivalent to if (x != 0) or if (x != false) */
        {
            Random();
            E = n ;
        }



        printf(" \n Tour Joueur : %i, %i, %i, %i, %i",  Etat[1], Etat[2], Etat[3], Etat[4], Etat[5]);


    /*    
        printf ("\n Voulez_vous relancer le D  \"B\" qui vaut %i ?  (oui=O  ; Non =N)", B);
            scanf("%c", &ReponseB);
        printf ("\n Voulez_vous relancer le D  \"C\" qui vaut %i ?  (oui=O  ; Non =N)", C);
            scanf("%c", &ReponseC);
        printf ("\n Voulez_vous relancer le D  \"D\" qui vaut %i ?  (oui=O  ; Non =N)", D);
            scanf("%c", &ReponseD);
        printf ("\n Voulez_vous relancer le D  \"E\" qui vaut %i ?  (oui=O  ; Non =N)", E);
            scanf("%c", &ReponseE);
   
           if (ReponseA = N){
            Random();
            A = n ;
            Etat[NoJoueur][1]=A;}

        if (ReponseB = N){
            Random();
            B = n;
            Etat[NoJoueur][1]=B;}

        if (ReponseC = N){
            Random();
            C = n;
            Etat[NoJoueur][3]=C;}

        if (ReponseD = N){
            Random();
            D = n;
            Etat[NoJoueur][4]=D;}
       
        if (ReponseE = N){
            Random();
            E = n;
            Etat[NoJoueur][5]= E;}
    */
    return 0;
}





/* ********************** Remplissage total et automatique du tableau Etat

   int Etat[NPlayer][5];   // construction du tableau Etat
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

/* ***************************************  Affichage Etat
      for (i=0 ; i<NPlayer ; i++)
         {
         for (j= 0; j<5 ; j++)
            {
            printf (" \n Joueur %i: %i, %i, %i, %i, %i", i+1, Etat[i][j], Etat[i][j], Etat[i][j], Etat[i][j], Etat[j][j]);
            }
         printf ("\n");
         }     //  printf (" Joueur %i: %i, %i, %i, %i, " Etat [i][])
*/
/*
int RemplissageTableauEtat()
{
   //int Etat[NPlayer][5];                              // construction du tableau Etat
   for (NoJoueur = 0; NoJoueur < NPlayer; NoJoueur++) //
   {
      Tour();
   }
   // printf(" \n RemplissageTableauEtat Joueur %i: %i, %i, %i, %i, %i", NoJoueur, Etat[NoJoueur][0], Etat[NoJoueur][1], Etat[NoJoueur][2], Etat[NoJoueur][3], Etat[NoJoueur][4]);
}
*/


/************************************************************************ */
/* ********** Developpement des fonctions de Lecture v rification des d s */
/************************************************************************ */

int Lecture ()
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
     {printf ("\t\t  *** Pas de moins 8 ou de plus 25 d tect . --- %i --\n",Somme);}
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
     if (egaliteA == 1) { printf ("\n\t\t Il y a une paire avec le D  A");}
     if (egaliteA == 2) { printf ("\n\t\t Il y a un brelan  avec le D  A");}
     if (egaliteA == 3) { printf ("\n\t\t Il y a un carr  avec le D  A");}

   egaliteB = 0;
   if (B == A) {egaliteB = egaliteB +1;}
   if (B == C) {egaliteB = egaliteB +1;}
   if (B == D) {egaliteB = egaliteB +1;}
   if (B == E) {egaliteB = egaliteB +1;}
     if (egaliteB == 1) { printf ("\n\t\t Il y a une paire avec le D  B");}
     if (egaliteB == 2) { printf ("\n\t\t Il y a un brelan  avec le D  B");}
     if (egaliteB == 3) { printf ("\n\t\t Il y a un carr  avec le D  B");}

   egaliteC = 0;
   if (C == A) {egaliteC = egaliteC +1;}
   if (C == B) {egaliteC = egaliteC +1;}
   if (C == D) {egaliteC = egaliteC +1;}
   if (C == E) {egaliteC = egaliteC +1;}
     if (egaliteC == 1) { printf ("\n\t\t Il y a une paire avec le D  C");}
     if (egaliteC == 2) { printf ("\n\t\t Il y a un brelan  avec le D  C");}
     if (egaliteC == 3) { printf ("\n\t\t Il y a un carr  avec le D  C");}

   egaliteD = 0;
   if (D == A) {egaliteD = egaliteD +1;}
   if (D == B) {egaliteD = egaliteD +1;}
   if (D == C) {egaliteD = egaliteD +1;}
   if (D == E) {egaliteD = egaliteD +1;}
     if (egaliteD == 1) { printf ("\n\t\t Il y a une paire avec le D  D");}
     if (egaliteD == 2) { printf ("\n\t\t Il y a un brelan  avec le D  D");}
     if (egaliteD == 3) { printf ("\n\t\t Il y a un carr  avec le D  D");}

   egaliteE = 0;
   if (E == A) {egaliteE = egaliteE +1;}
   if (E == B) {egaliteE = egaliteE +1;}
   if (E == C) {egaliteE = egaliteE +1;}
   if (D == E) {egaliteE = egaliteE +1;}
     if (egaliteE == 1) { printf ("\n\t\t Il y a une paire avec le D  E");}
     if (egaliteE == 2) { printf ("\n\t\t Il y a un brelan  avec le D  E");}
     if (egaliteE == 3) { printf ("\n\t\t Il y a un carr  avec le D  E");}

   /* *** Detection du Yams */
   if ((A == B) && (B == C) && (C == D) && (D ==E))
   { printf ("\n\t\t  !!! Yams d tect . !!!");}
   printf ("\n");
}

int ConclusionEgalite()
{
   // printf ("\n");
   printf ("\n\t Nombre de D (s) identique(s)   A: %i", egaliteA);
   printf ("\n\t Nombre de D (s) identique(s)   B: %i", egaliteB);
   printf ("\n\t Nombre de D (s) identique(s)   C: %i", egaliteC);
   printf ("\n\t Nombre de D (s) identique(s)   D: %i", egaliteD);
   printf ("\n\t Nombre de D (s) identique(s)   E: %i\n", egaliteE);
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

   printf("Entrez la valeur du D  num ro A: ");
   scanf ("%i",&A);
   printf("Entrez la valeur du D  num ro B: ");
   scanf ("%i",&B);
   printf("Entrez la valeur du D  num ro C: ");
   scanf ("%i",&C);
   printf("Entrez la valeur du D  num ro D: ");
   scanf ("%i",&D);
   printf("Entrez la valeur du D  num ro E: ");
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
   printf("D  num ro A - %i\n", A);

   Random();
   B = n;
   printf("D  num ro B - %i\n", B);

   Random();
   C = n;
   printf("D  num ro C - %i\n", C);

   Random();
   D = n;
   printf("D  num ro D - %i\n", D);

   Random();
   E = n;
   printf("D  num ro E - %i\n", E);

   // TableauScore[5] = { A , B , C , D , E}; //1 , 2 , 3 , 56, 76 };

   printf("\n");
   return 0;
}

/*
int Tirage() // *** Fonction Tirage avec des variables fixe
{
  printf ("\n");

  A = 1;
  printf("D  num ro A - %i\n",A);

  B = 1;
  printf("D  num ro B - %i\n",B);

  C = 2;
  printf("D  num ro C - %i\n",C);

  D = 3;
  printf("D  num ro D - %i\n",D);

  E = 4;
  printf("D  num ro E - %i\n",E);

  printf ("\n");
  return 0;
}
*/