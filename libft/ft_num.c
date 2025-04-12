/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:51:17 by mcarton           #+#    #+#             */
/*   Updated: 2025/03/24 21:01:57 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num(int nbr)
{
	int		count;
	char	*str;

	str = ft_itoa(nbr);
	count = ft_str(str);
	free(str);
	return (count);
}
