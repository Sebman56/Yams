/**********************************************************************************
* *** Jeux de Yams ***************************************************************
* *** Test de /**********************************************************************************
* *** Jeux de Yams ***************************************************************
* *** Test de la Gestion de le feuille de score. ***
************************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
       
       
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


    int ChoixLigneFeuille;
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


int main()
{
    /* Affichage du tableau*/
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
        return 0;
        exit(0);
}






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
*/



