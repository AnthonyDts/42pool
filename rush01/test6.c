#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 4  // Taille de la grille

// Fonction pour parser les indices à partir de la chaîne d'entrée
int parse_clues(char *str, int *col_clues, int *row_clues);

// Fonctions pour vérifier les contraintes
int is_valid(int grid[N][N], int row, int col, int num, int *row_clues, int *col_clues);
int check_row(int grid[N][N], int row, int *row_clues);
int check_col(int grid[N][N], int col, int *col_clues);

// Fonction de résolution
int solve(int grid[N][N], int row, int col, int *row_clues, int *col_clues);

// Fonction pour afficher la grille
void print_grid(int grid[N][N]);

int main(int argc, char *argv[]) {
    int col_clues[8];
    int row_clues[8];
    int grid[N][N] = {0};  // Initialiser la grille à zéro

    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Parser les indices à partir de la chaîne d'entrée
    if (!parse_clues(argv[1], col_clues, row_clues)) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Résoudre le puzzle
    if (solve(grid, 0, 0, row_clues, col_clues)) {
        print_grid(grid);
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}

// Fonction pour parser les indices à partir de la chaîne d'entrée
int parse_clues(char *str, int *col_clues, int *row_clues) {
    int i = 0, j = 0;
    int clues[16];

    while (str[i] != '\0' && j < 16) {
        if (str[i] >= '1' && str[i] <= '4') {
            clues[j] = str[i] - '0';
            j++;
        }
        i++;
    }

    if (j != 16) {
        return 0; // Erreur : Nombre d'indices insuffisant
    }

    // Assignation des indices aux colonnes et lignes
    for (i = 0; i < 8; i++) {
        col_clues[i] = clues[i];       // Les 8 premiers indices pour les colonnes
        row_clues[i] = clues[i + 8];   // Les 8 suivants pour les lignes
    }

    return 1;
}

// Fonction pour vérifier si un nombre peut être placé à une position donnée
int is_valid(int grid[N][N], int row, int col, int num, int *row_clues, int *col_clues) {
    int i;

    // Vérifier les duplicatas dans la ligne et la colonne
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }

    // Placer le nombre temporairement pour vérifier les indices
    grid[row][col] = num;

    // Vérifier les indices de la ligne et de la colonne si elles sont complètes
    if (col == N - 1) {
        if (!check_row(grid, row, row_clues)) {
            grid[row][col] = 0;  // Annuler le placement
            return 0;
        }
    }
    if (row == N - 1) {
        if (!check_col(grid, col, col_clues)) {
            grid[row][col] = 0;  // Annuler le placement
            return 0;
        }
    }

    grid[row][col] = 0;  // Annuler le placement
    return 1;
}

// Fonction pour compter les immeubles visibles depuis la gauche et la droite pour une ligne donnée
void count_visible_in_row(int *row, int *left_clue, int *right_clue) {
    int i, max_height, visible_count;

    // Compter depuis la gauche
    max_height = 0;
    visible_count = 0;
    for (i = 0; i < N; i++) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
    }
    *left_clue = visible_count;

    // Compter depuis la droite
    max_height = 0;
    visible_count = 0;
    for (i = N - 1; i >= 0; i--) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
    }
    *right_clue = visible_count;
}

// Fonction pour vérifier les indices d'une ligne
int check_row(int grid[N][N], int row, int *row_clues) {
    int left_clue, right_clue;
    int expected_left = row_clues[row];
    int expected_right = row_clues[row + N];
    int row_data[N];
    int i;

    // Vérifier si la ligne est complète
    for (i = 0; i < N; i++) {
        if (grid[row][i] == 0) {
            return 1; // Ligne incomplète, pas besoin de vérifier pour le moment
        }
        row_data[i] = grid[row][i];
    }

    // Compter les immeubles visibles
    count_visible_in_row(row_data, &left_clue, &right_clue);

    // Vérifier les indices (0 signifie pas d'indice)
    if (expected_left != 0 && left_clue != expected_left)
        return 0;
    if (expected_right != 0 && right_clue != expected_right)
        return 0;

    return 1;
}

// Fonction pour compter les immeubles visibles depuis le haut et le bas pour une colonne donnée
void count_visible_in_col(int grid[N][N], int col, int *up_clue, int *down_clue) {
    int i, max_height, visible_count;

    // Compter depuis le haut
    max_height = 0;
    visible_count = 0;
    for (i = 0; i < N; i++) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
    }
    *up_clue = visible_count;

    // Compter depuis le bas
    max_height = 0;
    visible_count = 0;
    for (i = N - 1; i >= 0; i--) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
    }
    *down_clue = visible_count;
}

// Fonction pour vérifier les indices d'une colonne
int check_col(int grid[N][N], int col, int *col_clues) {
    int up_clue, down_clue;
    int expected_up = col_clues[col];
    int expected_down = col_clues[col + N];
    int i;

    // Vérifier si la colonne est complète
    for (i = 0; i < N; i++) {
        if (grid[i][col] == 0) {
            return 1; // Colonne incomplète, pas besoin de vérifier pour le moment
        }
    }

    // Compter les immeubles visibles
    count_visible_in_col(grid, col, &up_clue, &down_clue);

    // Vérifier les indices (0 signifie pas d'indice)
    if (expected_up != 0 && up_clue != expected_up)
        return 0;
    if (expected_down != 0 && down_clue != expected_down)
        return 0;

    return 1;
}

// Fonction de résolution utilisant le backtracking
int solve(int grid[N][N], int row, int col, int *row_clues, int *col_clues) {
    int num;
    int next_row = row;
    int next_col = col + 1;

    if (col == N) {
        next_col = 0;
        next_row = row + 1;
    }

    if (row == N) {
        // La grille est complète
        return 1;
    }

    for (num = 1; num <= N; num++) {
        if (is_valid(grid, row, col, num, row_clues, col_clues)) {
            grid[row][col] = num;

            if (solve(grid, next_row, next_col, row_clues, col_clues))
                return 1;

            grid[row][col] = 0;  // Backtrack
        }
    }
    return 0;  // Aucune solution trouvée
}

// Fonction pour afficher la grille
void print_grid(int grid[N][N]) {
    int i, j;
    char c;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j != N - 1)
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}

