#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int *tab_col(char *str) {
    int i;
    int j;
    int *col_tab;

    col_tab = malloc(8 * sizeof(int));  // Allouer mémoire pour 8 entiers
    if (!col_tab) {
        return NULL;
    }
    i = 0;
    j = 0;
    while (str[i] && j < 8) {
        if(str[i] >= '1' && str[i] <= '4') {
            col_tab[j] = str[i] - '0';  // Convertir le caractère en entier
            j++;
        }
        i++;
    }
    return col_tab;
}

int *tab_row(char *str) {
    int i;
    int j;
    int *row_tab;

    row_tab = malloc(8 * sizeof(int));  // Allouer mémoire pour 8 entiers
    if (!row_tab) {
        return NULL;
    }
    i = 0;
    j = 0;
    while (str[i] && j < 8) {
        if(str[i + 16] >= '1' && str[i + 16] <= '4') {
            row_tab[j] = str[i + 16] - '0';  // Convertir le caractère en entier
            j++;
        }
        i++;
    }
    return row_tab;
}

// Fonction pour vérifier si les indices sont valides (entre 1 et N)
int check_clue(int clue, int N) {
    return (clue >= 1 && clue <= N);
}

int main(int argc, char *argv[]) {
    int *col_tab_ptr;
    int *row_tab_ptr;
    int i;
    int possible = 1;
    int N = 4; // Taille de la grille

    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Convertir la chaîne en int pour les colonnes et les lignes
    col_tab_ptr = tab_col(argv[1]);
    row_tab_ptr = tab_row(argv[1]);

    if (!col_tab_ptr || !row_tab_ptr) {
        write(1, "Error\n", 6);
        return 1;
    }

    printf("Colonnes:\n");
    for (i = 0; i < 8; i++) {
        printf("col_tab[%d] = %d\n", i, col_tab_ptr[i]);
    }

    printf("Lignes:\n");
    for (i = 0; i < 8; i++) {
        printf("row_tab[%d] = %d\n", i, row_tab_ptr[i]);
    }

    // Vérifier que les indices sont dans la plage correcte
    for (i = 0; i < 8; i++) {
        if (!check_clue(col_tab_ptr[i], N)) {
            possible = 0;
            printf("Indice invalide pour la colonne %d: %d\n", i + 1, col_tab_ptr[i]);
        }
        if (!check_clue(row_tab_ptr[i], N)) {
            possible = 0;
            printf("Indice invalide pour la ligne %d: %d\n", i + 1, row_tab_ptr[i]);
        }
    }

    if (possible) {
        printf("Les indices sont valides. Une solution est possible.\n");
    } else {
        printf("Les indices sont invalides. Vérifiez les indices fournis.\n");
    }

    // Libérer la mémoire allouée
    free(col_tab_ptr);
    free(row_tab_ptr);

    return 0;
}

