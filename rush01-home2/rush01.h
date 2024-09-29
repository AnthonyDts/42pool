/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define N 4

typedef struct s_clues
{
	int		col_up[N];
	int		col_down[N];
	int		row_left[N];
	int		row_right[N];
}	t_clues;

typedef struct s_game
{
	int		grid[N][N];
	t_clues	clues;
}	t_game;

void	initialize_grid(t_game *game);
int		parse_clues(char *str, t_game *game);
int		is_valid(t_game *game, int row, int col, int num);
int		check_row(t_game *game, int row);
int		check_col(t_game *game, int col);
int		solve(t_game *game, int row, int col);
void	print_grid(t_game *game);

#endif
