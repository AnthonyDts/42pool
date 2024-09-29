/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid(t_game *game, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (game->grid[row][i] == num || game->grid[i][col] == num)
			return (0);
		i++;
	}
	game->grid[row][col] = num;
	if (col == N - 1 && !check_row(game, row))
	{
		game->grid[row][col] = 0;
		return (0);
	}
	if (row == N - 1 && !check_col(game, col))
	{
		game->grid[row][col] = 0;
		return (0);
	}
	return (1);
}
