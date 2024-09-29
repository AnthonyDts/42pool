/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:00:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:00:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

typedef struct s_clues
{
	int	col_up[N];
	int	col_down[N];
	int	row_left[N];
	int	row_right[N];
}	t_clues;

int	solve(int grid[N][N], int row, int col, t_clues *clues);
int	is_valid(int grid[N][N], int row, int col, int num, t_clues *clues);

int	solve(int grid[N][N], int row, int col, t_clues *clues)
{
	int	num;

	if (row == N)
		return (1);
	if (col == N)
		return (solve(grid, row + 1, 0, clues));
	num = 1;
	while (num <= N)
	{
		if (is_valid(grid, row, col, num, clues))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, clues))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
