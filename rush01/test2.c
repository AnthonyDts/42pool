#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// La grille 4x4
int grid[4][4];

// Fonction pour afficher un nombre avec `write`
void write_number(int n) {
    char c = n + '0';  // Convertir l'entier en caractère
    write(1, &c, 1);
}

// Fonction pour afficher la grille avec `write`
void print_grid(int grid[4][4]) {
    int i = 0;
    int j;

    while (i < 4) {
        j = 0;
        while (j < 4) {
            write_number(grid[i][j]);
            if (j < 3) {
                write(1, " ", 1);  // Espace entre les nombres
            }
            j++;
        }
        write(1, "\n", 1);  // Nouvelle ligne après chaque ligne
        i++;
    }
}

// Fonctions pour vérifier les contraintes de visibilité
bool check_left_visibility(int grid[4][4], int row, int expected) {
    int max_seen = 0;
    int visible_count = 0;
    int i = 0;

    while (i < 4) {
        if (grid[row][i] > max_seen) {
            max_seen = grid[row][i];
            visible_count++;
        }
        i++;
    }

    return visible_count == expected;
}

bool check_right_visibility(int grid[4][4], int row, int expected) {
    int max_seen = 0;
    int visible_count = 0;
    int i = 3;

    while (i >= 0) {
        if (grid[row][i] > max_seen) {
            max_seen = grid[row][i];
            visible_count++;
        }
        i--;
    }

    return visible_count == expected;
}

bool check_top_visibility(int grid[4][4], int col, int expected) {
    int max_seen = 0;
    int visible_count = 0;
    int i = 0;

    while (i < 4) {
        if (grid[i][col] > max_seen) {
            max_seen = grid[i][col];
            visible_count++;
        }
        i++;
    }

    return visible_count == expected;
}

bool check_bottom_visibility(int grid[4][4], int col, int expected) {
    int max_seen = 0;
    int visible_count = 0;
    int i = 3;

    while (i >= 0) {
        if (grid[i][col] > max_seen) {
            max_seen = grid[i][col];
            visible_count++;
        }
        i--;
    }

    return visible_count == expected;
}

// Fonction de backtracking pour résoudre la grille
bool solve(int grid[4][4], int *col, int *row, int position) {
    if (position == 16) {
        return true;  // La grille est entièrement remplie
    }

    int row_idx = position / 4;
    int col_idx = position % 4;
    int height = 1;

    while (height <= 4) {
        grid[row_idx][col_idx] = height;

        // Vérifier les contraintes
        if (check_left_visibility(grid, row_idx, row[row_idx]) &&
            check_right_visibility(grid, row_idx, row[4 + row_idx]) &&
            check_top_visibility(grid, col_idx, col[col_idx]) &&
            check_bottom_visibility(grid, col_idx, col[4 + col_idx])) {

            // Si valide jusqu'ici, continuer à remplir la grille
            if (solve(grid, col, row, position + 1)) {
                return true;
            }
        }

        // Si ce placement ne fonctionne pas, revenir en arrière
        grid[row_idx][col_idx] = 0;
        height++;
    }

    return false;  // Retourner faux si aucune solution n'est trouvée
}

// Fonction pour convertir une chaîne en tableau d'entiers pour les colonnes
int *convert_col_tab(char *str) {
    int i = 0;
    int j = 0;
    int *col_tab;

    col_tab = malloc(8 * 4);  // Allouer mémoire pour 8 entiers
    if (!col_tab) {
        return NULL;  // Vérifier si l'allocation a échoué
    }

    // Parcourir la chaîne et extraire les chiffres pour les colonnes
    while (str[i] != '\0' && j < 8) {
        if (str[i] >= '1' && str[i] <= '4') {  // Ignorer les espaces et autres caractères non valides
            col_tab[j] = str[i] - '0';  // Convertir le caractère en entier
            j++;
        }
        i++;
    }

    return col_tab;
}

// Fonction pour convertir une chaîne en tableau d'entiers pour les lignes
int *convert_row_tab(char *str) {
    int i = 0;
    int j = 0;
    int *row_tab;

    row_tab = malloc(8 * 4);  // Allouer mémoire pour 8 entiers
    if (!row_tab) {
        return NULL;  // Vérifier si l'allocation a échoué
    }

    // Parcourir la chaîne pour obtenir les valeurs des lignes après avoir parcouru les colonnes
    while (str[i] != '\0' && j < 8) {
        if (str[i] >= '1' && str[i] <= '4' && i >= 16) {  // Vérifier que nous sommes après les 16 premiers caractères
            row_tab[j] = str[i] - '0';  // Convertir le caractère en entier
            j++;
        }
        i++;
    }

    return row_tab;
}

int main(int argc, char *argv[]) {
    int *col_tab_ptr;
    int *row_tab_ptr;
    int i;

    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Convertir la chaîne en tableaux d'entiers pour les colonnes et les lignes
    col_tab_ptr = convert_col_tab(argv[1]);
    row_tab_ptr = convert_row_tab(argv[1]);

    if (!col_tab_ptr || !row_tab_ptr) {
        write(1, "Memory allocation failed\n", 26);
        return 1;
    }

    // Afficher les colonnes et lignes extraites pour débogage
    write(1, "Colonnes:\n", 10);
    for (i = 0; i < 8; i++) {
        write_number(col_tab_ptr[i]);
        write(1, " ", 1);
    }
    write(1, "\n", 1);

    write(1, "Lignes:\n", 8);
    for (i = 0; i < 8; i++) {
        write_number(row_tab_ptr[i]);
        write(1, " ", 1);
    }
    write(1, "\n", 1);

    // Initialiser la grille à 0
    i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }

    // Appeler la fonction de backtracking pour résoudre la grille
    if (solve(grid, col_tab_ptr, row_tab_ptr, 0)) {
        print_grid(grid);  // Afficher la grille si une solution est trouvée
    } else {
        write(1, "Aucune solution trouvée\n", 24);
    }

    // Libérer la mémoire allouée
    free(col_tab_ptr);
    free(row_tab_ptr);

    return 0;
}

