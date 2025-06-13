/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:35 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 03:30:58 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_philos_forks(t_rules *rules, t_fork *forks, t_philo *philos)
{
	int	i;

	i = 0;
	if (philos)
	{
		while (i < rules->number_of_philosophers)
		{
			pthread_mutex_destroy(&philos[i].mutex);
			i++;
		}
		free(philos);
	}
	i = 0;
	if (forks)
	{
		while (i < rules->number_of_philosophers)
		{
			pthread_mutex_destroy(&forks[i].mutex);
			i++;
		}
		free(forks);
	}
}

static void	free_rules(t_rules *rules)
{
	if (rules)
	{
		pthread_mutex_destroy(&rules->write);
		pthread_mutex_destroy(&rules->global);
		free(rules);
	}
}

void	free_all(t_rules *rules, t_fork *forks, t_philo *philos)
{
	free_philos_forks(rules, forks, philos);
	free_rules(rules);
}

static int	init_simulation(t_rules **rules, t_fork **forks, int argc,
		char **argv)
{
	*rules = init_rules(argc, argv);
	if (!*rules)
		return (0);
	*forks = init_forks(*rules);
	if (!*forks)
	{
		free(*rules);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_fork	*forks;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (1);
	if (check_arguments(argv) == 0)
		return (1);
	if (!init_simulation(&rules, &forks, argc, argv))
		return (1);
	philos = init_philos(rules, forks);
	if (!philos)
	{
		free_all(rules, forks, NULL);
		return (1);
	}
	if (!start_simulation(rules, philos))
	{
		free_all(rules, forks, philos);
		return (1);
	}
	free_all(rules, forks, philos);
	return (0);
}
