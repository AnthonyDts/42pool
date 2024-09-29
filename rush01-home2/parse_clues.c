/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_clue_values(char *str, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < 16)
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
	return (1);
}

void	assign_clues(int *clues_values, t_game *game)
{
	int	i;

	i = 0;
	while (i < N)
	{
		game->clues.col_up[i] = clues_values[i];
		game->clues.col_down[i] = clues_values[i + 4];
		game->clues.row_left[i] = clues_values[i + 8];
		game->clues.row_right[i] = clues_values[i + 12];
		i++;
	}
}

int	parse_clues(char *str, t_game *game)
{
	int	clues_values[16];

	if (!parse_clue_values(str, clues_values))
		return (0);
	assign_clues(clues_values, game);
	return (1);
}
