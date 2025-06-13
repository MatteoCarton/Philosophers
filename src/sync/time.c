/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:55:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 0)
		return (time.tv_usec / 1000LL + time.tv_sec * 1000LL);
	return (0);
}

void	philo_sleep(t_philo *philo, long long time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		pthread_mutex_lock(&philo->rules->global);
		if (philo->rules->someone_died)
		{
			pthread_mutex_unlock(&philo->rules->global);
			break ;
		}
		pthread_mutex_unlock(&philo->rules->global);
		usleep(100);
	}
}
