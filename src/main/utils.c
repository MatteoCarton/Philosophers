/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:05:14 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:33 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return (result);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

static void	destroy_mutexes(t_rules *rules, t_fork *forks, t_philo *philos)
{
	int	i;

	if (rules)
	{
		pthread_mutex_destroy(&rules->write);
		pthread_mutex_destroy(&rules->global);
	}
	if (forks)
	{
		i = 0;
		while (i < rules->number_of_philosophers)
		{
			pthread_mutex_destroy(&forks[i].mutex);
			i++;
		}
	}
	if (philos)
	{
		i = 0;
		while (i < rules->number_of_philosophers)
		{
			pthread_mutex_destroy(&philos[i].mutex);
			i++;
		}
	}
}

void	freeprog(t_rules *rules, t_fork *forks, t_philo *philos)
{
	destroy_mutexes(rules, forks, philos);
	if (rules)
		free(rules);
	if (forks)
		free(forks);
	if (philos)
		free(philos);
}

int	check_death(t_philo *philo)
{
	int	value;

	value = 0;
	pthread_mutex_lock(&philo->rules->global);
	if (philo->rules->someone_died)
		value = 1;
	pthread_mutex_unlock(&philo->rules->global);
	return (value);
}
