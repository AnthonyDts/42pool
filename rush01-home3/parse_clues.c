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

int	validate_input_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_clues(char *str, t_game *game)
{
	int	i;
	int	clues_values[16];

	if (!validate_input_format(str))
		return (0);
	i = 0;
	while (i < 16)
	{
		clues_values[i] = str[i * 2] - '0';
		i++;
	}
	i = 0;
	while (i < N)
	{
		game->clues.col_up[i] = clues_values[i];
		game->clues.col_down[i] = clues_values[i + 4];
		game->clues.row_left[i] = clues_values[i + 8];
		game->clues.row_right[i] = clues_values[i + 12];
		i++;
	}
	return (1);
}
