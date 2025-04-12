/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:28:50 by mcarton           #+#    #+#             */
/*   Updated: 2025/03/24 20:57:08 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_char(va_arg(args, int));
	else if (c == 's')
		count += ft_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_num(va_arg(args, int));
	else if (c == 'p')
		count += ft_ptr(va_arg(args, void *));
	else if (c == 'u')
		count += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_hex(va_arg(args, int), c);
	else
		count += ft_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("csdipuxX%", str[i + 1]))
		{
			i++;
			count += ft_specifier(str[i], args);
		}
		else
			count += ft_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
