/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:55:03 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->global);
	if (!philo->rules->someone_died || ft_strcmp(str, "died") == 0)
	{
		pthread_mutex_lock(&philo->rules->write);
		time = get_time() - philo->rules->start_time;
		printf("%lld %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->rules->write);
	}
	pthread_mutex_unlock(&philo->rules->global);
}

void	philo_eat(t_philo *philo)
{
	if (!take_forks(philo))
		return ;
	pthread_mutex_lock(&philo->rules->global);
	if (philo->rules->someone_died)
	{
		pthread_mutex_unlock(&philo->rules->global);
		release_forks(philo);
		return ;
	}
	pthread_mutex_lock(&philo->mutex);
	philo->time_last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->rules->global);
	msg(philo, GREEN "is eating" RESET);
	philo_sleep(philo, philo->rules->time_to_eat);
	release_forks(philo);
}

int	is_philo_dead(t_philo *philo)
{
	return (check_death(philo));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->number_of_philosophers == 1)
	{
		msg(philo, BLUE "has taken a fork" RESET);
		philo_sleep(philo, philo->rules->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (!check_death(philo))
	{
		philo_eat(philo);
		msg(philo, MAGENTA "is sleeping" RESET);
		philo_sleep(philo, philo->rules->time_to_sleep);
		msg(philo, YELLOW "is thinking" RESET);
		usleep(100);
	}
	return (NULL);
}
