/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:04:15 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/18 16:05:14 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*resultat;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	resultat = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!resultat)
		return (NULL);
	while (s[i] != '\0')
	{
		resultat[i] = (*f)(i, s[i]);
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
