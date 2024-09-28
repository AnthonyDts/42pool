/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:00:03 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 15:19:28 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= 32 && str[i] <= 126)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main (void)
{
	int test1 = ft_str_is_printable("AAAOSEHIESG");
	printf("la valeur devrait etre : 1 -> %d",test1);
	int test2 = ft_str_is_printable("aESFSFESFSA");
	printf("\nla valeur devrait etre : 1 -> %d",test2);
	int test3 = ft_str_is_printable("@!#$%^&");
	printf("\nla valeur devrait etre : 1 -> %d",test3);
	int test4 = ft_str_is_printable("12€ƒ34567");
	printf("\nla valeur devrait etre : 0 -> %d",test4);
	int test5 = ft_str_is_printable("");
	printf("\nla valeur devrait etre : 1 -> %d",test5);
}
*/
