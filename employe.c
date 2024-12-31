#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int taille_liste_emp(liste_emp LE) {
    int compteur = 0;
    while (LE != NULL) {
        compteur++;
        LE = LE->suiv;
    }
    return compteur;
}

struct Employe saisir_donnees_employe() {
    struct Employe nouvel_employe;
    
    nouvel_employe.DE = malloc(sizeof(struct date));
    if (!nouvel_employe.DE) {
        fprintf(stderr, "Erreur d'allocation mémoire pour la date d'embauche\n");
        exit(1);
    }

    printf("Entrer le matricule : ");
    while (scanf("%d", &nouvel_employe.mat) != 1) {
        printf("Matricule invalide. Réessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrer le nom : ");
    while (getchar() != '\n');
    fgets(nouvel_employe.nom, 20, stdin);
    nouvel_employe.nom[strcspn(nouvel_employe.nom, "\n")] = 0;

    printf("Entrer le prénom : ");
    fgets(nouvel_employe.prenom, 20, stdin);
    nouvel_employe.prenom[strcspn(nouvel_employe.prenom, "\n")] = 0;

    printf("Entrer l'adresse : ");
    fgets(nouvel_employe.adresse, 50, stdin);
    nouvel_employe.adresse[strcspn(nouvel_employe.adresse, "\n")] = 0;

    printf("Entrez la date d'embauche (jj mm aaaa) : ");
    while (scanf("%d %d %d", &nouvel_employe.DE->j, &nouvel_employe.DE->m, &nouvel_employe.DE->a) != 3) {
        printf("Date invalide. Réessayez (jj mm aaaa) : ");
        while (getchar() != '\n');
    }

    printf("Entrez le numéro de téléphone : ");
    while (scanf("%d", &nouvel_employe.telephone) != 1) {
        printf("Numéro invalide. Réessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrez le service (une lettre) : ");
    while (getchar() != '\n');
    nouvel_employe.service = getchar();

    printf("Entrez le salaire brut : ");
    while (scanf("%f", &nouvel_employe.salairebrut) != 1) {
        printf("Salaire invalide. Réessayez : ");
        while (getchar() != '\n');
    }

    nouvel_employe.suiv = NULL;
    return nouvel_employe;
}

liste_emp insere_tete_emp(liste_emp LE) {
    struct Employe *nouvel_employe = malloc(sizeof(struct Employe));
    if (!nouvel_employe) {
        printf("Erreur d'allocation mémoire\n");
        return LE;
    }

    *nouvel_employe = saisir_donnees_employe();
    nouvel_employe->suiv = LE;
    return nouvel_employe;
}

void insere_queue_emp(liste_emp LE) {
    if (LE == NULL) {
        LE = insere_tete_emp(NULL);
        return;
    }

    struct Employe *nouvel_employe = malloc(sizeof(struct Employe));
    if (!nouvel_employe) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    *nouvel_employe = saisir_donnees_employe();
    nouvel_employe->suiv = NULL;

    liste_emp courant = LE;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }
    courant->suiv = nouvel_employe;
}

void insere_pos_emp(liste_emp LE, int pos) {
    if (pos < 1) {
        printf("Position invalide\n");
        return;
    }
    if (pos == 1 || LE == NULL) {
        LE = insere_tete_emp(LE);
        return;
    }

    struct Employe *nouvel_employe = malloc(sizeof(struct Employe));
    if (!nouvel_employe) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    *nouvel_employe = saisir_donnees_employe();
    
    liste_emp courant = LE;
    for (int i = 1; i < pos - 1 && courant != NULL; i++) {
        courant = courant->suiv;
    }
    
    if (courant == NULL) {
        printf("Position trop grande\n");
        free(nouvel_employe->DE);
        free(nouvel_employe);
        return;
    }

    nouvel_employe->suiv = courant->suiv;
    courant->suiv = nouvel_employe;
}

// [Reste des fonctions de suppression et d'affichage restent identiques]

liste_emp CREATION() {
    liste_emp tete = NULL;
    char choix;

    do {
        struct Employe *nouvel_employe = malloc(sizeof(struct Employe));
        if (!nouvel_employe) {
            printf("Erreur d'allocation mémoire\n");
            return tete;
        }

        nouvel_employe->DE = malloc(sizeof(struct date));
        if (!nouvel_employe->DE) {
            free(nouvel_employe);
            printf("Erreur d'allocation mémoire\n");
            return tete;
        }

        *nouvel_employe = saisir_donnees_employe();

        // Vérification unicité matricule
        liste_emp temp = tete;
        while (temp != NULL) {
            if (temp->mat == nouvel_employe->mat) {
                printf("Matricule déjà existant!\n");
                free(nouvel_employe->DE);
                free(nouvel_employe);
                return tete;
            }
            temp = temp->suiv;
        }

        // Insertion en tête
        nouvel_employe->suiv = tete;
        tete = nouvel_employe;

        printf("Ajouter un autre employé? (o/n) : ");
        while (getchar() != '\n');
        choix = getchar();

    } while (choix == 'o' || choix == 'O');

    return tete;
}

void liberer_liste(liste_emp LE) {
    while (LE != NULL) {
        liste_emp temp = LE;
        LE = LE->suiv;
        free(temp->DE);
        free(temp);
    }
}
