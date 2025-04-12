/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 03:49:25 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/16 16:30:01 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	resultat;

	signe = 1;
	i = 0;
	resultat = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10;
		resultat = resultat + (str[i] - 48);
		i++;
	}
	resultat = resultat * signe;
	return (resultat);
}
/*
int	main(void)
{
	char	str[] = "54f6i";

	printf("%d\n", ft_atoi(str));
}
*/
