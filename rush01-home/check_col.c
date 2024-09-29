/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
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

int	check_col(int grid[N][N], int col, t_clues *clues);

int	count_up_view(int grid[N][N], int col)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_down_view(int grid[N][N], int col)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_col(int grid[N][N], int col, t_clues *clues)
{
	int	up_view;
	int	down_view;

	up_view = count_up_view(grid, col);
	down_view = count_down_view(grid, col);
	if ((clues->col_up[col] && up_view != clues->col_up[col])
		|| (clues->col_down[col] && down_view != clues->col_down[col]))
		return (0);
	return (1);
}
