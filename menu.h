#ifndef HEADER_H
#define HEADER_H

struct date {
    int j;
    int m;
    int a;
};

struct Employe {
    int mat;
    char nom[20];
    char prenom[20];
    char adresse[50];
    struct date *DE;
    int telephone;
    char service;
    float salairebrut;
    struct Employe *suiv;
};

typedef struct Employe * liste_emp;

// Menus
void menu_general(liste_emp liste);
void menu_maj(liste_emp liste);
void menu_ajouter(liste_emp liste);
void menu_suppression(liste_emp liste);
void menu_modification(liste_emp liste);
void menu_rech_aff(liste_emp liste);

// Opérations sur la liste
int taille_liste_emp(liste_emp LE);
liste_emp insere_tete_emp(liste_emp LE);
void insere_queue_emp(liste_emp LE);
void insere_pos_emp(liste_emp LE, int pos);
void supprimer_tete_emp(liste_emp LE);
void supprimer_queue_emp(liste_emp LE);
void suppression_pos_emp(liste_emp LE, int posi);
void suppression_employee_donne(liste_emp LE, int num);
void suppression_employes_service(liste_emp LE, char service);
void afficher_liste_employes(liste_emp LE);
void liberer_liste(liste_emp LE);

// Création
liste_emp CREATION();

#endif
