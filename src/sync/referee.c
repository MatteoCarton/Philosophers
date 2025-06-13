/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   referee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:54:00 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_all_ate(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_mutex_lock(&philos[i].mutex);
		if (philos[i].meals < rules->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_unlock(&philos[i].mutex);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].mutex);
		i++;
	}
	return (1);
}

int	check_philo_death(t_rules *rules, t_philo *philo)
{
	long long	current_time;

	if (check_death(philo))
		return (0);
	pthread_mutex_lock(&philo->mutex);
	current_time = get_time() - philo->time_last_meal;
	if (current_time >= rules->time_to_die)
	{
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_lock(&philo->rules->global);
		philo->rules->someone_died = 1;
		pthread_mutex_unlock(&philo->rules->global);
		pthread_mutex_lock(&philo->rules->write);
		current_time = get_time() - rules->start_time;
		printf("%lld %d %s\n", current_time, philo->id, RED "died" RESET);
		pthread_mutex_unlock(&philo->rules->write);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	check_meal_completion(t_rules *rules, t_philo *philos)
{
	if (!rules->optional_arg)
		return (0);
	if (check_all_ate(rules, philos) == 1)
	{
		pthread_mutex_lock(&philos[0].rules->global);
		if (!philos[0].rules->someone_died)
		{
			philos[0].rules->someone_died = 1;
			pthread_mutex_unlock(&philos[0].rules->global);
			return (1);
		}
		pthread_mutex_unlock(&philos[0].rules->global);
	}
	return (0);
}

static int	check_philosophers(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (check_philo_death(rules, &philos[i]) == 1)
			return (1);
		if (check_meal_completion(rules, philos) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	referee_philos(t_rules *rules, t_philo *philos)
{
	while (42)
	{
		if (check_philosophers(rules, philos) == 1)
			return ;
		usleep(100);
	}
}
