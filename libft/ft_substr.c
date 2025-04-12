/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:30:30 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/16 13:25:06 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*resultat;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	resultat = ft_calloc(len + 1, sizeof(char));
	if (!resultat)
		return (NULL);
	while (i < len)
	{
		resultat[i] = s[start + i];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
/*
int	main(void)
{
	char	s[] = "ViveLaFrance";
	int		start;
	size_t	len;

	start = 4;
	len = 10;
	printf("%s\n", ft_substr(s, start, len));
}
*/
