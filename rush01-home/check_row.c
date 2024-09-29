/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_left_view(int grid[N][N], int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_right_view(int grid[N][N], int row)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_row(int grid[N][N], int row, t_clues *clues)
{
	int	left_view;
	int	right_view;

	left_view = count_left_view(grid, row);
	right_view = count_right_view(grid, row);
	if ((clues->row_left[row] && left_view != clues->row_left[row])
		|| (clues->row_right[row] && right_view != clues->row_right[row]))
		return (0);
	return (1);
}
