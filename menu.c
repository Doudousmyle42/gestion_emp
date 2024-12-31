#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void menu_general(liste_emp liste) {
    int choix;
    do {
        system("cls");
        printf("MENU GENERAL\n");
        printf("1. Creation des employes\n");
        printf("2. Mise a jour de la liste des employes\n");
        printf("3. Calcul et affichage des salaires des employes\n");
        printf("4. Recherche, affichage et Tri\n");
        printf("5. Quitter\n");
        printf("Saisir votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n');
            printf("Choix invalide\n");
            continue;
        }

        switch(choix) {
            case 1:
                system("cls");
                liste = CREATION();
                break;
            case 2:
                system("cls");
                menu_maj(liste);
                break;
            case 3:
                system("cls");
                printf("Calcul et affichage des salaires\n");
                break;
            case 4:
                system("cls");
                menu_rech_aff(liste);
                break;
            case 5:
                system("cls");
                liberer_liste(liste);
                printf("Au revoir!\n");
                exit(0);
            default:
                printf("Choix invalide\n");
        }
    } while (!(choix >= 1 && choix <= 5));
}

void menu_maj(liste_emp liste) {
    int choix;
    do {
        system("cls");
        printf("MENU MAJ\n");
        printf("1. Ajouter un employe\n");
        printf("2. Supprimer un employe\n");
        printf("3. Modifier un employe\n");
        printf("4. Retour menu general\n");
        printf("Choix: ");

        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n');
            printf("Choix invalide\n");
            continue;
        }

        switch(choix) {
            case 1:
                system("cls");
                menu_ajouter(liste);
                break;
            case 2:
                system("cls");
                menu_suppression(liste);
                break;
            case 3:
                system("cls");
                menu_modification(liste);
                break;
            case 4:
                system("cls");
                menu_general(liste);
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (!(choix >= 1 && choix <= 4));
}

void menu_ajouter(liste_emp liste) {
    int choix, pos;
    do {
        system("cls");
        printf("MENU AJOUTER\n");
        printf("1. Ajouter en tete\n");
        printf("2. Ajouter en queue\n");
        printf("3. Ajouter a une position\n");
        printf("4. Retour menu MAJ\n");
        printf("Choix: ");

        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n');
            printf("Choix invalide\n");
            continue;
        }

        switch(choix) {
            case 1:
                system("cls");
                liste = insere_tete_emp(liste);
                break;
            case 2:
                system("cls");
                insere_queue_emp(liste);
                break;
            case 3:
                system("cls");
                printf("Position: ");
                scanf("%d", &pos);
                insere_pos_emp(liste, pos);
                break;
            case 4:
                system("cls");
                menu_maj(liste);
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (!(choix >= 1 && choix <= 4));
}

// [Les autres fonctions de menu similairement corrigées]
