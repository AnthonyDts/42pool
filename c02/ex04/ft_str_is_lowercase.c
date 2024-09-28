/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:43:02 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 15:59:06 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')))
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
	int test1 = ft_str_is_lowercase("abcdefg");
	printf("la valeur devrait etre : 1 -> %d",test1);
	int test2 = ft_str_is_lowercase("aESFSFESFSA");
	printf("\nla valeur devrait etre : 0 -> %d",test2);
	int test3 = ft_str_is_lowercase("abc4efg");
	printf("\nla valeur devrait etre : 0 -> %d",test3);
	int test4 = ft_str_is_lowercase("1234567");
	printf("\nla valeur devrait etre : 0 -> %d",test4);
}
*/
