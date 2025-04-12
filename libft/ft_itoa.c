/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:59:45 by mcarton           #+#    #+#             */
/*   Updated: 2024/12/03 15:20:56 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int	nbr;

	nbr = 0;
	if (n <= 0)
		nbr++;
	while (n != 0)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;
	long	nbr;

	nbr = n;
	length = num_length(nbr);
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		result[--length] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}
/*
int main(void)
{
    int n;

    n = -1234;
    printf("%s\n", ft_itoa(n));
}
*/
