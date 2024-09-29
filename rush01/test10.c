/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2024/09/28 23:03:56 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4

int		parse_clues(char *str, int *col_up, int *col_down,
			int *row_left, int *row_right);
int		is_valid(int grid[N][N], int row, int col, int num,
			int *row_left, int *row_right,
			int *col_up, int *col_down);
int		check_row(int grid[N][N], int row,
			int *row_left, int *row_right);
int		check_col(int grid[N][N], int col,
			int *col_up, int *col_down);
int		solve(int grid[N][N], int row, int col,
			int *row_left, int *row_right,
			int *col_up, int *col_down);
void	print_grid(int grid[N][N]);

int	main(int argc, char **argv)
{
	int	col_up[N];
	int	col_down[N];
	int	row_left[N];
	int	row_right[N];
	int	grid[N][N];
	int	i;
	int	j;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!parse_clues(argv[1], col_up, col_down, row_left, row_right))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, 0, 0, row_left, row_right, col_up, col_down))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

int	parse_clues(char *str, int *col_up, int *col_down,
		int *row_left, int *row_right)
{
	int	i;
	int	j;
	int	clues[16];

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			clues[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	i = -1;
	while (++i < N)
	{
		col_up[i] = clues[i];
		col_down[i] = clues[i + 4];
		row_left[i] = clues[i + 8];
		row_right[i] = clues[i + 12];
	}
	return (1);
}

int	is_valid(int grid[N][N], int row, int col, int num,
		int *row_left, int *row_right,
		int *col_up, int *col_down)
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
	if (col == N - 1 && !check_row(grid, row, row_left, row_right))
	{
		grid[row][col] = 0;
		return (0);
	}
	if (row == N - 1 && !check_col(grid, col, col_up, col_down))
	{
		grid[row][col] = 0;
		return (0);
	}
	return (1);
}

int	check_row(int grid[N][N], int row,
		int *row_left, int *row_right)
{
	int	left_view;
	int	right_view;
	int	max_height;
	int	count;
	int	i;

	max_height = 0;
	count = 0;
	i = -1;
	while (++i < N)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			count++;
		}
	}
	left_view = count;
	max_height = 0;
	count = 0;
	i = N;
	while (--i >= 0)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			count++;
		}
	}
	right_view = count;
	if ((row_left[row] && left_view != row_left[row]) ||
		(row_right[row] && right_view != row_right[row]))
		return (0);
	return (1);
}

int	check_col(int grid[N][N], int col,
		int *col_up, int *col_down)
{
	int	up_view;
	int	down_view;
	int	max_height;
	int	count;
	int	i;

	max_height = 0;
	count = 0;
	i = -1;
	while (++i < N)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
	}
	up_view = count;
	max_height = 0;
	count = 0;
	i = N;
	while (--i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
	}
	down_view = count;
	if ((col_up[col] && up_view != col_up[col]) ||
		(col_down[col] && down_view != col_down[col]))
		return (0);
	return (1);
}

int	solve(int grid[N][N], int row, int col,
		int *row_left, int *row_right,
		int *col_up, int *col_down)
{
	int	num;

	if (row == N)
		return (1);
	if (col == N)
		return (solve(grid, row + 1, 0,
				row_left, row_right, col_up, col_down));
	num = 0;
	while (++num <= N)
	{
		if (is_valid(grid, row, col, num,
				row_left, row_right, col_up, col_down))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1,
					row_left, row_right, col_up, col_down))
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}

void	print_grid(int grid[N][N])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j != N - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

