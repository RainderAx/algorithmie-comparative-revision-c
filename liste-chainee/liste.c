#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* --- compteur d'allocations, interne au module --- */

static int blocs = 0;

static void *suivi_malloc(size_t taille)
{
    void *p = malloc(taille);
    if (p != NULL) blocs++;
    return p;
}

static void suivi_free(void *p)
{
    if (p != NULL) { blocs--; free(p); }
}

int liste_blocs_en_circulation(void)
{
    return blocs;
}

Maillon *liste_inserer(Maillon *tete, int valeur)
{
    Maillon *nouveau = suivi_malloc(sizeof *nouveau);
    if (nouveau == NULL) return tete;

    nouveau->valeur = valeur;
    nouveau->suivant = tete;
    return nouveau;
}

int liste_longueur(const Maillon *tete)
{
    int longueur = 0;
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        longueur++;
    return longueur;
}

bool liste_contient(const Maillon *tete, int valeur)
{
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        if (m->valeur == valeur) return true;
    return false;
}

void liste_afficher(const Maillon *tete)
{
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        printf("%d ", m->valeur);
    putchar('\n');
}

void liste_liberer(Maillon *tete)
{
    while (tete != NULL) {
        Maillon *suivant = tete->suivant;
        suivi_free(tete);
        tete = suivant;
    }
}
