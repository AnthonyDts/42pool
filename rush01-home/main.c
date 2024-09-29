/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:00 by user42            #+#    #+#             */
/*   Updated: 2023/10/03 14:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		grid[N][N];
	t_clues	clues;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	initialize_grid(grid);
	if (!parse_clues(argv[1], &clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, 0, 0, &clues))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

