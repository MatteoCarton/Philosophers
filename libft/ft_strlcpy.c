/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:35:31 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 16:11:52 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	long_src;

	i = 0;
	long_src = 0;
	while (src[long_src] != '\0')
		long_src++;
	if (size == 0)
		return (long_src);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (long_src);
}
/*
int	main(void)
{
	char dest[] = "Salut";
	char src[] = "Bonjour";

	printf("%ld\n", ft_strlcpy(dest, src, 5));
}
*/
