/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_clues(char *str, t_clues *clues)
{
	int	i;
	int	j;
	int	tmp[16];

	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			tmp[j] = str[i] - '0';
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
		clues->col_up[i] = tmp[i];
		clues->col_down[i] = tmp[i + 4];
		clues->row_left[i] = tmp[i + 8];
		clues->row_right[i] = tmp[i + 12];
	}
	return (1);
}
