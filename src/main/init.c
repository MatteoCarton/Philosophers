/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:53:33 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_rules_values(t_rules *rules, int argc, char **argv)
{
	rules->number_of_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->someone_died = 0;
	if (argc == 6)
	{
		rules->optional_arg = 1;
		rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		rules->optional_arg = 0;
		rules->number_of_times_each_philosopher_must_eat = 0;
	}
}

t_rules	*init_rules(int argc, char **argv)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	set_rules_values(rules, argc, argv);
	if (!init_mutexes(rules))
		return (free(rules), NULL);
	return (rules);
}

t_fork	*init_forks(t_rules *rules)
{
	int		i;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * rules->number_of_philosophers);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&forks[i].mutex);
			}
			return (free(forks), NULL);
		}
		forks[i].is_taken = 0;
		i++;
	}
	return (forks);
}

static int	init_single_philo(t_philo *philo, t_rules *rules, t_fork *forks,
		int i)
{
	philo->id = i + 1;
	philo->meals = 0;
	philo->left_fork = &forks[i];
	philo->right_fork = &forks[(i + 1) % rules->number_of_philosophers];
	philo->rules = rules;
	if (pthread_mutex_init(&philo->mutex, NULL) != 0)
		return (0);
	return (1);
}

t_philo	*init_philos(t_rules *rules, t_fork *forks)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * rules->number_of_philosophers);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (init_single_philo(&philos[i], rules, forks, i) == 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&philos[i].mutex);
			}
			return (free(philos), NULL);
		}
		i++;
	}
	return (philos);
}
