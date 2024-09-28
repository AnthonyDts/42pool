/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:47:02 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 19:06:41 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		if ((str[i - 1] < 'A' || (str[i - 1] > 'Z' && str[i - 1] < 'a')
				|| str[i - 1] > 'z') && !(str[i - 1] >= '0'
				&& str[i - 1] <= '9') && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	i++;
	}
	return (str);
}

#include <stdio.h>

int main (void)
{	char str[] = {"salut, coMMent au Avas ? 42mots quarante-deux; cinquante+et+un"};
	ft_strcapitalize(str);
	printf("-> %s",str);
}

