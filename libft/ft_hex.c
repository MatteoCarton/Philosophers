/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:51:15 by mcarton           #+#    #+#             */
/*   Updated: 2025/03/24 21:01:33 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex(unsigned int nbr, char c)
{
	const char	*hex_base;
	int			count;

	if (c == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
		count += ft_hex(nbr / 16, c);
	count += ft_char(hex_base[nbr % 16]);
	return (count);
}
