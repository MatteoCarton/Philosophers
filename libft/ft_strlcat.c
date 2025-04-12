/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:06:54 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/23 17:36:01 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	long_dest;
	size_t	long_src;
	size_t	i;

	long_src = 0;
	long_dest = 0;
	i = 0;
	if ((dest == NULL && src == NULL) || (dest == NULL && size == 0))
		return (0);
	while (src[long_src] != '\0')
		long_src++;
	while (dest[long_dest] != '\0')
		long_dest++;
	if (size == 0)
		return (long_src);
	if (long_dest >= size)
		return (size + long_src);
	while (src[i] != '\0' && (long_dest + i) < (size - 1))
	{
		dest[long_dest + i] = src[i];
		i++;
	}
	dest[long_dest + i] = '\0';
	return (long_dest + long_src);
}
/*
int	main(void)
{
	//char dest[] = "Bonjour";
	//char src[] = "Salut";

	char *dest2 = NULL;
	char *src2 = NULL;

	// printf("%ld\n", ft_strlcat(dest, src, 7));
	printf("%ld\n", ft_strlcat(dest2, src2, 7));
}
*/
