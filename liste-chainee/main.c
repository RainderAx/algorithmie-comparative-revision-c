/* main.c - programme qui utilise le module liste
   Compilation : gcc -Wall -Wextra -o liste main.c liste.c
   Execution   : ./liste (Windows : liste) */
#include <stdio.h>
#include "liste.h"
 
int main(void)
{
    printf("--- R6 : liste chainee ---\n");
    Maillon *liste = NULL; /* une liste vide */
    for (int i = 1; i <= 5; i++) liste = liste_inserer(liste, i * 10);
    printf("  liste : ");
    liste_afficher(liste);
    printf("  longueur : %d\n", liste_longueur(liste));
    printf("  contient 30 : %s\n", liste_contient(liste, 30) ? "oui" : "non");
    printf("  contient 99 : %s\n", liste_contient(liste, 99) ? "oui" : "non");
    printf("  liste vide, contient 30 : %s\n", liste_contient(NULL, 30) ? "oui" : "non");
    liste_liberer(liste);
    printf("  liberee\n");
    return 0;
}