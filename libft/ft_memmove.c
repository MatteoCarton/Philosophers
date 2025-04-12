/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:54:36 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 16:46:35 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stddef.h>
#include <string.h>

int	main(void)
{
	char	dest1[50] = "TestCarJeComprendsPas";
	char	dest2[50] = "TestCarJeComprendsPas";
	size_t	size;

	size = 4;
	printf("Resultat avec VRAI memmove : %s\n", (char *)memmove(dest1, dest1
			+ 2, size));
	ft_memmove(dest2, dest2 + 2, size);
	printf("Resultat avec MON memmove : %s\n", dest2);
	return (0);
}
*/
