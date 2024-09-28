#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 


int *tab_col(char *str) {
    int i;
	int j;
    int *col_tab;

    col_tab = malloc(8 * 4);  // Allouer mémoire pour 8 entiers
    if (!col_tab) {
        return NULL;  
    }
    i = 0;
	j = 0;
    while (str[i] && j < 8) {
		if(str[i] >= '1' && str[i] <= '4')
		{
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

    row_tab = malloc(8 * 4);  // Allouer mémoire pour 8 entiers
    if (!row_tab) {
        return NULL; 
    }
    i = 0;
	j = 0;
    while (str[i] && j < 8) {
		if(str[i + 16] >= '1' && str[i + 16] <= '4')
		{
        	row_tab[j] = str[i +16] - '0';  // Convertir le caractère en entier
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

    // Convertir la chaîne en int pour les colonnes et les lignes
    col_tab_ptr = tab_col(argv[1]);
    row_tab_ptr = tab_row(argv[1]);

    if (!col_tab_ptr || !row_tab_ptr) {
        write(1, "Error\n", 6);
        return 1;
    }

    printf("Colonnes:\n");
    i = 0;
    while (i < 8) {
        printf("col_tab[%d] = %d\n", i, col_tab_ptr[i]);
        i++;
    }

    printf("Lignes:\n");
    i = 0;
    while (i < 8) {
        printf("row_tab[%d] = %d\n", i, row_tab_ptr[i]);
        i++;
    }

    // Libérer la mémoire allouée
    free(col_tab_ptr);
    free(row_tab_ptr);

    return 0;
}
