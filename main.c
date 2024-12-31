#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
    liste_emp liste = NULL;
    printf("Gestion des employés\n");
    menu_general(liste);
    return 0;
}
