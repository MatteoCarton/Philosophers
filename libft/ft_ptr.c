/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:51:21 by mcarton           #+#    #+#             */
/*   Updated: 2025/03/24 21:01:52 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_convert(unsigned long long nbr)
{
	const char	*hex_base;
	int			count;

	hex_base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_hex_convert(nbr / 16);
	count += ft_char(hex_base[nbr % 16]);
	return (count);
}

int	ft_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_hex_convert((unsigned long long)ptr);
	return (count);
}
