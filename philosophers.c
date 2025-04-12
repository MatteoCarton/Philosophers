/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:35 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/13 01:01:41 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int valid_number(char *str)
{
    size_t i;

    if (str == NULL || str[0] == '\0')
        return (0);
    i = 0;
    if (str[i] == '+')
        i++;
    while(str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int check_arguments(char **argv)
{
    size_t i;

    i = 1;
    while (argv[i] != NULL)
    {
        if (valid_number(argv[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

// j'init l'instance des regles puis je remplis chaque regle 1 par 1 via les args
t_rules *init_rules(int argc, char **argv)
{
    t_rules *rules = malloc(sizeof(t_rules));
    if (!rules)
        return (NULL);

    rules->number_of_philosophers = ft_atoi(argv[1]);
    if (rules->number_of_philosophers <= 0)
    {
        free(rules);
        return (NULL);
    }
    rules->time_to_die = ft_atoi(argv[2]);
    if (rules->time_to_die <= 0)
    {
        free(rules);
        return (NULL);
    }
    rules->time_to_eat = ft_atoi(argv[3]);
    if (rules->time_to_eat <= 0)
    {
        free(rules);
        return (NULL);
    }
    rules->time_to_sleep = ft_atoi(argv[4]);
    if (rules->time_to_sleep <= 0)
    {
        free(rules);
        return (NULL);
    }
    if (argc == 6)
    {
        rules->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
        if (rules->number_of_times_each_philosopher_must_eat <= 0)
        {
            free(rules);
            return (NULL);
        }
    }
    return (rules);
}

t_fork *init_forks(int number_of_philosophers)
{
    int i;
    t_fork *forks;

    forks = malloc(sizeof(t_fork) * number_of_philosophers);
    if (!forks)
        return (NULL);
    i = 0;
    while (i < number_of_philosophers)
    {
        if (pthread_mutex_init(&forks[i].mutex, NULL) != 0) // elle retourne 0 si c'est good
        { // si ca echoue il faut detruire tous les mutex qu'on a deja crees
            while (i > 0)
            {
                i--;
                pthread_mutex_destroy(&forks[i].mutex);
            }
            free (forks);
            return (NULL);
        }
        forks[i].is_taken = false;
        i++;
    }
    
    return (forks);
}

t_philo *init_philos(t_rules *rules, t_fork *forks)
{
    int i;
    t_philo *philos; // On cree un tableau de philosophes
    
    philos = malloc(sizeof(t_philo) * rules->number_of_philosophers);
    if (!philos)
        return (NULL);

    i = 0;
    while (i < rules->number_of_philosophers)
    {
        philos[i].philo_id = i;
        philos[i].rules = rules;
        philos[i].left_fork = &forks[i]; // Fourchette a gauche = celle de son ID
        if (i == rules->number_of_philosophers - 1) // Fourchette a droite = celle du philosophe suivant
            philos[i].right_fork = &forks[0];
        else
            philos[i].right_fork = &forks[i + 1];
        i++;
    }
    
    return (philos);
}

int main(int argc, char **argv)
{
    int i;
    t_rules *rules;
    t_philo *philos;
    t_fork *forks;
    if(argc != 5 && argc != 6)
        return (1);
    if (check_arguments(argv) == 0)
        return (1);
    rules = init_rules(argc, argv);
    if (!rules)
        return (1);
    forks = init_forks(rules->number_of_philosophers);
    if (!forks)
        return (free(rules), 1);
    philos = init_philos(rules, forks);
    if (!philos)
        return (free(rules), free(forks), 1);
    
    
    
    // A LA FIN DU PROGRAMME, IL FAUT :
    // Detruire tous les mutex
    // Puis liberer toute la memoire
    i = 0;
    while (i < rules->number_of_philosophers)
    {
        pthread_mutex_destroy(&forks[i].mutex);
        i ++;
    }
    free(rules);
    free(philos);
    free(forks);
    return (0);
}