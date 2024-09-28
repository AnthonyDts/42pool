/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:25:09 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 15:58:43 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
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
	int test1 = ft_str_is_numeric("abcdefg");
	printf("la valeur devrait etre : 0 -> %d",test1);
	int test2 = ft_str_is_numeric("");
	printf("\nla valeur devrait etre : 1 -> %d",test2);
	int test3 = ft_str_is_numeric("abc4efg");
	printf("\nla valeur devrait etre : 0 -> %d",test3);
	int test4 = ft_str_is_numeric("1234567");
	printf("\nla valeur devrait etre : 1 -> %d",test4);

}
*/
