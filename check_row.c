/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  andantas <andantas@student.42.fr>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by andantas          #+#    #+#             */
/*   Updated: 2024/09/29 18:54:29 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	count_left_view(t_game *game, int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (game->grid[row][i] > max)
		{
			max = game->grid[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_right_view(t_game *game, int row)
{
	int	i;
	int	max;
	int	count;

	i = 4 - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (game->grid[row][i] > max)
		{
			max = game->grid[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_row(t_game *game, int row)
{
	int	left_view;
	int	right_view;

	left_view = count_left_view(game, row);
	right_view = count_right_view(game, row);
	if ((game->clues.row_left[row] && left_view != game->clues.row_left[row])
		|| (game->clues.row_right[row]
			&& right_view != game->clues.row_right[row]))
		return (0);
	return (1);
}
