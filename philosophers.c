/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:35 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/12 23:41:09 by mcarton          ###   ########.fr       */
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

int check_arguments(int argc, char **argv)
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

int main(int argc, char **argv)
{
    t_rules *rules;
    if(argc != 5 && argc != 6)
        return (1);
    if (check_arguments(argc, argv) == 0)
        return (1);
    rules = init_rules(argc, argv);
    if (!rules)
        return (1);

    free(rules);
    return (0);
}