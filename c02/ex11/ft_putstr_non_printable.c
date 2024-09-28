/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:45:12 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 15:47:46 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	create_hex_chars(char hex_chars[17])
{
	hex_chars[0] = '0';
	hex_chars[1] = '1';
	hex_chars[2] = '2';
	hex_chars[3] = '3';
	hex_chars[4] = '4';
	hex_chars[5] = '5';
	hex_chars[6] = '6';
	hex_chars[7] = '7';
	hex_chars[8] = '8';
	hex_chars[9] = '9';
	hex_chars[10] = 'a';
	hex_chars[11] = 'b';
	hex_chars[12] = 'c';
	hex_chars[13] = 'd';
	hex_chars[14] = 'e';
	hex_chars[15] = 'f';
	hex_chars[16] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex_chars[17];
	char	hex_value[3];

	create_hex_chars(hex_chars);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] != 31)
			write(1, &str[i], 1);
		else
		{
			hex_value[0] = '\\';
			hex_value[1] = hex_chars[(unsigned char)str[i] / 16];
			hex_value[2] = hex_chars[(unsigned char)str[i] % 16];
			write(1, hex_value, 3);
		}
	i++;
	}
}
/*
int main (void)
{	char str[] = {"Coucou\ntu vas bien ? € 10€ TEST"};
	ft_putstr_non_printable(str);
}
*/
