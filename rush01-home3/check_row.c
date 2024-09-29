/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_left_view(t_game *game, int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
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

	i = N - 1;
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
