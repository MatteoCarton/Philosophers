/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:10 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	valid_number(char *str)
{
	size_t	i;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (valid_number(argv[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
		return (0);
	return (1);
}
