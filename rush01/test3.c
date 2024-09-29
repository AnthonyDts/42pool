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

// Fonction pour vérifier si une ligne ou colonne est valide
int check_line(int left_clue, int right_clue) {
    int N = 4;  // Taille de la grille
    if (left_clue < 1 || left_clue > N || right_clue < 1 || right_clue > N)
        return 0; // Indices hors limites
    if (left_clue + right_clue > N + 1)
        return 0; // Somme des indices trop grande
    if (left_clue == 1 && right_clue == 1 && N > 1)
        return 0; // Impossible d'avoir deux indices de 1 sur une ligne/colonne
    if ((left_clue == N && right_clue == N) && N > 1)
        return 0; // Impossible d'avoir deux indices de N sur une ligne/colonne
    if ((left_clue == 1 && right_clue == N) || (left_clue == N && right_clue == 1))
        return 0; // Impossible d'avoir un indice de 1 et N opposés
    return 1; // Ligne/colonne valide
}

int main(int argc, char *argv[]) {
    int *col_tab_ptr;
    int *row_tab_ptr;
    int i;
    int possible = 1;

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

    // Vérifier les contradictions pour chaque colonne
    for (i = 0; i < 4; i++) {
        int up_clue = col_tab_ptr[i];       // Indice en haut
        int down_clue = col_tab_ptr[i + 4]; // Indice en bas
        if (!check_line(up_clue, down_clue)) {
            possible = 0;
            printf("Contradiction dans les indices de la colonne %d: %d et %d\n", i + 1, up_clue, down_clue);
        }
    }

    // Vérifier les contradictions pour chaque ligne
    for (i = 0; i < 4; i++) {
        int left_clue = row_tab_ptr[i];       // Indice à gauche
        int right_clue = row_tab_ptr[i + 4];  // Indice à droite
        if (!check_line(left_clue, right_clue)) {
            possible = 0;
            printf("Contradiction dans les indices de la ligne %d: %d et %d\n", i + 1, left_clue, right_clue);
        }
    }

    if (possible) {
        printf("Les indices sont valides. Une solution est possible.\n");
    } else {
        printf("Les indices sont contradictoires. Aucune solution n'est possible.\n");
    }

    // Libérer la mémoire allouée
    free(col_tab_ptr);
    free(row_tab_ptr);

    return 0;
}

