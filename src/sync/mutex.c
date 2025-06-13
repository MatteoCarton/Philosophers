/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:55:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes(t_rules *rules)
{
	if (pthread_mutex_init(&rules->write, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&rules->global, NULL) != 0)
	{
		pthread_mutex_destroy(&rules->write);
		return (0);
	}
	return (1);
}
