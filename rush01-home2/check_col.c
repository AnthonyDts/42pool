/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_up_view(t_game *game, int col)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (game->grid[i][col] > max)
		{
			max = game->grid[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_down_view(t_game *game, int col)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (game->grid[i][col] > max)
		{
			max = game->grid[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_col(t_game *game, int col)
{
	int	up_view;
	int	down_view;

	up_view = count_up_view(game, col);
	down_view = count_down_view(game, col);
	if ((game->clues.col_up[col] && up_view != game->clues.col_up[col])
		|| (game->clues.col_down[col]
			&& down_view != game->clues.col_down[col]))
		return (0);
	return (1);
}
