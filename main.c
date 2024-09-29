/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  andantas <andantas@student.42.fr>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by andantas          #+#    #+#             */
/*   Updated: 2024/09/29 18:55:54 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_clues
{
	int		col_up[4];
	int		col_down[4];
	int		row_left[4];
	int		row_right[4];
}			t_clues;

typedef struct s_game
{
	int		grid[4][4];
	t_clues	clues;
}			t_game;

void		initialize_grid(t_game *game);
int			parse_clues(char *str, t_game *game);
int			solve(t_game *game, int row, int col);
void		print_grid(t_game *game);
int			is_valid(t_game *game, int row, int col, int num);
int			check_row(t_game *game, int row);
int			check_col(t_game *game, int col);

int	validate_input_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_clues(char *str, t_game *game)
{
	int	i;
	int	clues_values[16];

	if (!validate_input_format(str))
		return (0);
	i = 0;
	while (i < 16)
	{
		clues_values[i] = str[i * 2] - '0';
		i++;
	}
	i = 0;
	while (i < 4)
	{
		game->clues.col_up[i] = clues_values[i];
		game->clues.col_down[i] = clues_values[i + 4];
		game->clues.row_left[i] = clues_values[i + 8];
		game->clues.row_right[i] = clues_values[i + 12];
		i++;
	}
	return (1);
}

int	is_valid(t_game *game, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->grid[row][i] == num || game->grid[i][col] == num)
			return (0);
		i++;
	}
	game->grid[row][col] = num;
	if (col == 4 - 1 && !check_row(game, row))
	{
		game->grid[row][col] = 0;
		return (0);
	}
	if (row == 4 - 1 && !check_col(game, col))
	{
		game->grid[row][col] = 0;
		return (0);
	}
	return (1);
}

int	solve(t_game *game, int row, int col)
{
	int	num;

	if (row == 4)
		return (1);
	if (col == 4)
		return (solve(game, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(game, row, col, num))
		{
			if (solve(game, row, col + 1))
				return (1);
			game->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	initialize_grid(&game);
	if (!parse_clues(argv[1], &game))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(&game, 0, 0))
		print_grid(&game);
	else
		write(1, "Error\n", 6);
	return (0);
}
