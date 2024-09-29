/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define N 4

typedef struct s_clues
{
	int	col_up[N];
	int	col_down[N];
	int	row_left[N];
	int	row_right[N];
}	t_clues;

void	initialize_grid(int grid[N][N]);
int		parse_clues(char *str, t_clues *clues);
int		is_valid(int grid[N][N], int row, int col, int num, t_clues *clues);
int		check_row(int grid[N][N], int row, t_clues *clues);
int		check_col(int grid[N][N], int col, t_clues *clues);
int		solve(int grid[N][N], int row, int col, t_clues *clues);
void	print_grid(int grid[N][N]);

#endif
