/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid(int grid[N][N], int row, int col, int num, t_clues *clues)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	grid[row][col] = num;
	if (col == N - 1 && !check_row(grid, row, clues))
	{
		grid[row][col] = 0;
		return (0);
	}
	if (row == N - 1 && !check_col(grid, col, clues))
	{
		grid[row][col] = 0;
		return (0);
	}
	return (1);
}
