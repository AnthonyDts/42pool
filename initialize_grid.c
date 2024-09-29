/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  andantas <andantas@student.42.fr>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by andantas          #+#    #+#             */
/*   Updated: 2024/09/29 18:55:12 by andantas         ###   ########.fr       */
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

void	initialize_grid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			game->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_grid(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = game->grid[i][j] + '0';
			write(1, &c, 1);
			if (j != 4 - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
