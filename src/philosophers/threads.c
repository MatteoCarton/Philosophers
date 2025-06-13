/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:08:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		philos[i].time_last_meal = rules->start_time;
		if (pthread_create(&philos[i].philo_thread, NULL, routine,
				&philos[i]) != 0)
		{
			rules->someone_died = 1;
			while (i > 0)
			{
				i--;
				pthread_join(philos[i].philo_thread, NULL);
			}
			return (0);
		}
		i++;
	}
	return (1);
}

static void	wait_for_philosophers(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_join(philos[i].philo_thread, NULL);
		i++;
	}
}

int	start_simulation(t_rules *rules, t_philo *philos)
{
	rules->start_time = get_time();
	if (!create_philosophers(rules, philos))
		return (0);
	referee_philos(rules, philos);
	return (wait_for_philosophers(rules, philos), 1);
}
