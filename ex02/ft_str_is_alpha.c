/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:39:08 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 15:14:13 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (
					str[i] >= 'A' && str[i] <= 'Z')))
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
	int test1 = ft_str_is_alpha("abcdefg");
	printf("la valeur devrait etre : 1 -> %d",test1);
	int test2 = ft_str_is_alpha("");
	printf("\nla valeur devrait etre : 1 -> %d",test2);
	int test3 = ft_str_is_alpha("abc4efg");
	printf("\nla valeur devrait etre : 0 -> %d",test3);
	int test4 = ft_str_is_alpha("1234567");
	printf("\nla valeur devrait etre : 0 -> %d",test4);

}
*/
