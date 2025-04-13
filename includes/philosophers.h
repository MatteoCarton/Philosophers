/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:32 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/13 11:25:57 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include "../libft/libft.h"
#include <pthread.h>
#include <sys/time.h>

typedef enum {
    false,
    true
} bool;

typedef enum {
    eating,
    thinking,
    sleeping
}   philo_state;

typedef struct s_fork {
    pthread_mutex_t mutex; // le cadenas
    bool is_taken;
} t_fork;

typedef struct s_rules {
    int number_of_philosophers;
    long long time_to_die;
    long long time_to_eat;
    long long time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    bool optional_arg;
} t_rules;

typedef struct s_philo
{
    int philo_id;
    t_rules *rules; // lien vers les regles
    t_fork *right_fork;
    t_fork *left_fork;
    pthread_t philo_thread;
    philo_state current;
    long long last_meal_time;
    int meals;
    
} t_philo;


int main(int argc, char **argv);

#endif
