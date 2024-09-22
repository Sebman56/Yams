#include <stdio.h>

//Compiler version gcc  6.3.0

int n, A, B, C, D, E;

int Random ()
{  
  n = rand()  % 6+ 1;
  return n;
}


int Tirage()
{
  srand(time(NULL));
  
  Random();
  A = n;
  printf("Dé numéro A - %i\n",A);
  
  Random();
  B = n;
  printf("Dé numéro B - %i\n",B);
 
  Random();
  C = n;
  printf("Dé numéro C - %i\n",C);
 
  Random();
  D = n;
  printf("Dé numéro D - %i\n",D);
  
  Random();
  E = n;
  printf("Dé numéro E - %i\n",E);
 
  printf ("\n");
  return 0;
}

int Egalite()
{
  int egaliteA = 0;
  if (A == B) {egaliteA = egaliteA +1; printf ("egalitéA: %i\n",egaliteA);}
  if (A == C) {egaliteA = egaliteA +1; printf ("egalitéA: %i\n",egaliteA);}
  if (A == D) {egaliteA = egaliteA +1; printf ("egalitéA: %i\n",egaliteA);}
  if (A == E) {egaliteA = egaliteA +1; printf ("egalitéA: %i\n",egaliteA);}
    if (egaliteA == 1) { printf ("\n\t Il y a une paire avec le Dé A");}
    if (egaliteA == 2) { printf ("\n\t Il y a un brelan  avec le Dé A");}
    if (egaliteA == 3) { printf ("\n\t Il y a un carré avec le Dé A");}
        printf ("\n");

  int egaliteB = 0;
  if (B == A) {egaliteB = egaliteB +1; printf ("egalitéB: %i\n",egaliteB);}
  if (B == C) {egaliteB = egaliteB +1; printf ("egalitéB: %i\n",egaliteB);}
  if (B == D) {egaliteB = egaliteB +1; printf ("egalitéB: %i\n",egaliteB);}
  if (B == E) {egaliteB = egaliteB +1; printf ("egalitéB: %i\n",egaliteB);}
    if (egaliteB == 1) { printf ("\n\t Il y a une paire avec le Dé B");}
    if (egaliteB == 2) { printf ("\n\t Il y a un brelan  avec le Dé B");}
    if (egaliteB == 3) { printf ("\n\t Il y a un carré avec le Dé B");}
      printf ("\n");

  int egaliteC = 0;
  if (C == A) {egaliteC = egaliteC +1; printf ("egalitéC: %i\n",egaliteC);}
  if (C == B) {egaliteC = egaliteC +1; printf ("egalitéC: %i\n",egaliteC);}
  if (C == D) {egaliteC = egaliteC +1; printf ("egalitéC: %i\n",egaliteC);}
  if (C == E) {egaliteC = egaliteC +1; printf ("egalitéC: %i\n",egaliteC);}
    if (egaliteC == 1) { printf ("\n\t Il y a une paire avec le Dé C");}
    if (egaliteC == 2) { printf ("\n\t Il y a un brelan  avec le Dé C");}
    if (egaliteC == 3) { printf ("\n\t Il y a un carré avec le Dé C");}
        printf ("\n");

  int egaliteD = 0;
  if (D == A) {egaliteD = egaliteD +1; printf ("egalitéD: %i\n",egaliteD);}
  if (D == B) {egaliteD = egaliteD +1; printf ("egalitéD: %i\n",egaliteD);}
  if (D == C) {egaliteD = egaliteD +1; printf ("egalitéD: %i\n",egaliteD);}
  if (D == E) {egaliteD = egaliteD +1; printf ("egalitéD: %i\n",egaliteD);}
    if (egaliteD == 1) { printf ("\n\t Il y a une paire avec le Dé D");}
    if (egaliteD == 2) { printf ("\n\t Il y a un brelan  avec le Dé D");}
    if (egaliteD == 3) { printf ("\n\t Il y a un carré avec le Dé D");}
        printf ("\n");

  int egaliteE = 0;
  if (E == A) {egaliteE = egaliteE +1; printf ("egalitéE: %i\n",egaliteE);}
  if (E == B) {egaliteE = egaliteE +1; printf ("egalitéE: %i\n",egaliteE);}
  if (E == C) {egaliteE = egaliteE +1; printf ("egalitéE: %i\n",egaliteE);}
  if (D == E) {egaliteE = egaliteE +1; printf ("egalitéE: %i\n",egaliteE);}
    if (egaliteE == 1) { printf ("\n\t Il y a une paire avec le Dé E");}
    if (egaliteE == 2) { printf ("\n\t Il y a un brelan  avec le Dé E");}
    if (egaliteE == 3) { printf ("\n\t Il y a un carré avec le Dé E");}
        printf ("\n");

  // if (egalite > 0) {egalite = egalite +1;}
  
  // egalite = egalite /2;

  // printf ("\n");
  printf ("\n\t Nombre de Dé(s) identique(s) à A: %i", egaliteA);
  printf ("\n\t Nombre de Dé(s) identique(s) à B: %i", egaliteB);
  printf ("\n\t Nombre de Dé(s) identique(s) à C: %i", egaliteC);
  printf ("\n\t Nombre de Dé(s) identique(s) à D: %i", egaliteD);
  printf ("\n\t Nombre de Dé(s) identique(s) à E: %i\n", egaliteE);
  printf ("\n");
}

int main()
{
  Tirage();
  Egalite();
  return 0;
}
