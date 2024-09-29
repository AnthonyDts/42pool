/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve(t_game *game, int row, int col)
{
	int	num;

	if (row == N)
		return (1);
	if (col == N)
		return (solve(game, row + 1, 0));
	num = 1;
	while (num <= N)
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
