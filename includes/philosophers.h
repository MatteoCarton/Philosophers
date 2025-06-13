/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:32 by mcarton           #+#    #+#             */
/*   Updated: 2025/06/13 02:05:08 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define RESET "\033[0m"

typedef struct s_rules
{
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				optional_arg;
	long long		start_time;
	int				someone_died;
	pthread_mutex_t	write;
	pthread_mutex_t	global;
}					t_rules;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				is_taken;
}					t_fork;

typedef struct s_philo
{
	int				id;
	long long		time_last_meal;
	int				meals;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_t		philo_thread;
	t_rules			*rules;
	pthread_mutex_t	mutex;
}					t_philo;

// utils.c
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				freeprog(t_rules *rules, t_fork *forks, t_philo *philos);
int					check_death(t_philo *philo);

// forks.c
int					take_forks(t_philo *philo);
void				release_forks(t_philo *philo);

// mutex.c
int					init_mutexes(t_rules *rules);

// time.c
long long			get_time(void);
void				philo_sleep(t_philo *philo, long long time);

// Main functions
int					main(int argc, char **argv);
int					check_arguments(char **argv);
t_rules				*init_rules(int argc, char **argv);
t_fork				*init_forks(t_rules *rules);
t_philo				*init_philos(t_rules *rules, t_fork *forks);
int					start_simulation(t_rules *rules, t_philo *philos);
void				free_all(t_rules *rules, t_fork *forks, t_philo *philos);

// Actions and utilities
void				msg(t_philo *philo, char *str);
void				philo_eat(t_philo *philo);
int					is_philo_dead(t_philo *philo);
void				*routine(void *arg);

// Referee functions
int					check_all_ate(t_rules *rules, t_philo *philos);
int					check_philo_death(t_rules *rules, t_philo *philo);
int					check_meal_completion(t_rules *rules, t_philo *philos);
void				referee_philos(t_rules *rules, t_philo *philos);

#endif
