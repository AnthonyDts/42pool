/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:15 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 18:14:41 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>

int main(void)
{
	char dest[6]; 
    char src[] = "Hello, world!"; 
    size_t length = ft_strlcpy(dest, src, sizeof(dest));

    // Affiche la chaîne destination et la longueur de la source
    printf("Chaîne copiée : %s\n", dest);
    printf("Longueur de la chaîne source : %zu\n", length);

    // Vérifie si la chaîne a été tronquée
    if (length >= sizeof(dest)) {
    	 printf("La chaîne source a été tronquée.\n");
    }	
    return 0;
}
*/
