#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 4  // Taille de la grille

// Fonction pour parser les indices à partir de la chaîne d'entrée
int parse_clues(char *str, int *col_up, int *col_down, int *row_left, int *row_right);

// Fonctions pour vérifier les contraintes
int is_valid(int grid[N][N], int row, int col, int num, int *row_left, int *row_right, int *col_up, int *col_down);
int check_row(int grid[N][N], int row, int *row_left, int *row_right);
int check_col(int grid[N][N], int col, int *col_up, int *col_down);

// Fonction de résolution
int solve(int grid[N][N], int row, int col, int *row_left, int *row_right, int *col_up, int *col_down);

// Fonction pour afficher la grille
void print_grid(int grid[N][N]);

int main(int argc, char *argv[]) {
    int col_up[N], col_down[N], row_left[N], row_right[N];
    int grid[N][N];  // Grille de jeu

    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Initialiser la grille à zéro
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;

    // Parser les indices à partir de la chaîne d'entrée
    if (!parse_clues(argv[1], col_up, col_down, row_left, row_right)) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Résoudre le puzzle
    if (solve(grid, 0, 0, row_left, row_right, col_up, col_down)) {
        print_grid(grid);
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}

// Fonction pour parser les indices à partir de la chaîne d'entrée
int parse_clues(char *str, int *col_up, int *col_down, int *row_left, int *row_right) {
    int i = 0, j = 0;
    int clues[16];

    while (str[i] != '\0' && j < 16) {
        if (str[i] >= '1' && str[i] <= '4') {
            clues[j] = str[i] - '0';
            j++;
        } else if (str[i] != ' ') {
            // Caractère invalide
            return 0;
        }
        i++;
    }

    if (j != 16) {
        return 0; // Erreur : Nombre d'indices insuffisant
    }

    // Assignation des indices aux tableaux correspondants
    for (i = 0; i < N; i++) {
        col_up[i] = clues[i];          // indices 0 à 3
        col_down[i] = clues[i + 4];    // indices 4 à 7
        row_left[i] = clues[i + 8];    // indices 8 à 11
        row_right[i] = clues[i + 12];  // indices 12 à 15
    }

    return 1;
}

// Fonction pour vérifier si un nombre peut être placé à une position donnée
int is_valid(int grid[N][N], int row, int col, int num, int *row_left, int *row_right, int *col_up, int *col_down) {
    int i;

    // Vérifier les duplicatas dans la ligne et la colonne
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }

    grid[row][col] = num;

    // Vérifier les indices de la ligne si elle est complète
    if (col == N - 1) {
        if (!check_row(grid, row, row_left, row_right)) {
            grid[row][col] = 0;  // Annuler le placement
            return 0;
        }
    }

    // Vérifier les indices de la colonne si elle est complète
    if (row == N - 1) {
        if (!check_col(grid, col, col_up, col_down)) {
            grid[row][col] = 0;  // Annuler le placement
            return 0;
        }
    }

    return 1;
}

// Fonction pour compter les immeubles visibles depuis la gauche et la droite pour une ligne donnée
void count_visible_in_row(int *row_data, int *left_view, int *right_view) {
    int i;
    int max_height;
    int count;

    // Depuis la gauche
    max_height = 0;
    count = 0;
    for (i = 0; i < N; i++) {
        if (row_data[i] > max_height) {
            max_height = row_data[i];
            count++;
        }
    }
    *left_view = count;

    // Depuis la droite
    max_height = 0;
    count = 0;
    for (i = N - 1; i >= 0; i--) {
        if (row_data[i] > max_height) {
            max_height = row_data[i];
            count++;
        }
    }
    *right_view = count;
}

// Fonction pour vérifier les indices d'une ligne
int check_row(int grid[N][N], int row, int *row_left, int *row_right) {
    int left_view, right_view;
    int expected_left = row_left[row];
    int expected_right = row_right[row];
    int row_data[N];
    int i;

    // Vérifier si la ligne est complète
    for (i = 0; i < N; i++) {
        if (grid[row][i] == 0)
            return 1;  // Ligne incomplète, ne pas vérifier pour le moment
        row_data[i] = grid[row][i];
    }

    count_visible_in_row(row_data, &left_view, &right_view);

    if (expected_left != 0 && left_view != expected_left)
        return 0;
    if (expected_right != 0 && right_view != expected_right)
        return 0;

    return 1;
}

// Fonction pour compter les immeubles visibles depuis le haut et le bas pour une colonne donnée
void count_visible_in_col(int grid[N][N], int col, int *up_view, int *down_view) {
    int i;
    int max_height;
    int count;

    // Depuis le haut
    max_height = 0;
    count = 0;
    for (i = 0; i < N; i++) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            count++;
        }
    }
    *up_view = count;

    // Depuis le bas
    max_height = 0;
    count = 0;
    for (i = N - 1; i >= 0; i--) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            count++;
        }
    }
    *down_view = count;
}

// Fonction pour vérifier les indices d'une colonne
int check_col(int grid[N][N], int col, int *col_up, int *col_down) {
    int up_view, down_view;
    int expected_up = col_up[col];
    int expected_down = col_down[col];
    int i;

    // Vérifier si la colonne est complète
    for (i = 0; i < N; i++) {
        if (grid[i][col] == 0)
            return 1;  // Colonne incomplète, ne pas vérifier pour le moment
    }

    count_visible_in_col(grid, col, &up_view, &down_view);

    if (expected_up != 0 && up_view != expected_up)
        return 0;
    if (expected_down != 0 && down_view != expected_down)
        return 0;

    return 1;
}

// Fonction de résolution utilisant le backtracking
int solve(int grid[N][N], int row, int col, int *row_left, int *row_right, int *col_up, int *col_down) {
    int num;

    if (row == N)
        return 1;  // Solution trouvée

    if (col == N) {
        // Passer à la ligne suivante
        return solve(grid, row + 1, 0, row_left, row_right, col_up, col_down);
    }

    for (num = 1; num <= N; num++) {
        if (is_valid(grid, row, col, num, row_left, row_right, col_up, col_down)) {
            grid[row][col] = num;

            if (solve(grid, row, col + 1, row_left, row_right, col_up, col_down))
                return 1;

            // Backtracking
            grid[row][col] = 0;
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

