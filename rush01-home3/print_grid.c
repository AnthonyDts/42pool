/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

void	print_grid(t_game *game)
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
			c = game->grid[i][j] + '0';
			write(1, &c, 1);
			if (j != N - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
