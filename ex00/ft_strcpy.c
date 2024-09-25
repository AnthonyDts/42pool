/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:38:53 by andantas          #+#    #+#             */
/*   Updated: 2024/09/25 16:00:06 by andantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*main_dest;

	main_dest = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (main_dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char src[25] = "This is the source string";
	char dest [34] = "This is the destination string";
	char * return_string;
	return_string = ft_strcpy(dest, src);
	printf( "After strcpy, destination becomes: %s", dest);
}
*/
