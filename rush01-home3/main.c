/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: votre_login <votre_email@student.42.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:00:00 by votre_login       #+#    #+#             */
/*   Updated: 2023/10/04 10:00:00 by votre_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	initialize_grid(&game);
	if (!parse_clues(argv[1], &game))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(&game, 0, 0))
		print_grid(&game);
	else
		write(1, "Error\n", 6);
	return (0);
}
