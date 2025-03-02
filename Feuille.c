/**********************************************************************************
* *** Jeux de Yams ***************************************************************
* *** Test de **********************************************************************************
* *** Jeux de Yams ***************************************************************
* *** Test de la Gestion de le feuille de score. ***
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>


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
    {"Trois         " ,  3,  1 , 2 , 3 , 4 , 5 , 6 },
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


int main()
{
    struct LigneFeuille LiveScore [16];
    memcpy(LiveScore, Feuille, tailleFeuilleScore);
    int t;
    for (t=0; t < 13 ; t++)
    {
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
/*
AffichageScore()
{
    printf("\n\b Acces au tableau de score.\n");
    for (int i = 0; i < 16; i++)
    {
        printf (" %s,\b %d, \b  %d,%d,%d,%d,%d,%d.\n",
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
    return 0;
}*/
/*
AffichageScore()
{    
   
}

EcritureScore()
{
    printf("\n\bIl faut saisir une ligne de la feuille de score:");
    scanf("%i",&ChoixLigneFeuille);
}
*/





/*            for (int j = 0; j < 8; j++)
                {
                    printf(" %c", Feuille[i][j].Nomligne);
            }{
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

 *   if (((ReponseE [0]== 'o') || (ReponseE [0]== 'O')) && (ReponseE [1] == '\n'))
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
*/
