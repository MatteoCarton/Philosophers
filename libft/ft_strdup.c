/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:35:50 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/16 04:47:19 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc(i * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	s[] = "Salut";
	char	*dupli;

	dupli = ft_strdup(s);
	if (dupli != NULL)
	{
		printf("%s\n", dupli);
		free(dupli);
	}
	else
	{
		printf("NULL\n");
	}
	return (0);
}
*/
