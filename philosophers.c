/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:35 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/13 12:54:12 by mcarton          ###   ########.fr       */
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
    t_rules *rules ;
    struct timeval current_time;
    
    rules = malloc(sizeof(t_rules));
    if (!rules)
        return (NULL);
    // On start le chrono
    gettimeofday(&current_time, NULL);
    rules->start_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    
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
        rules->optional_arg = true;
    }
    else
        rules->optional_arg = false;
    if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
            return (free(rules), NULL);
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
    struct timeval current_time;
    
    philos = malloc(sizeof(t_philo) * rules->number_of_philosophers);
    if (!philos)
        return (NULL);

    i = 0;
    while (i < rules->number_of_philosophers)
    {
        philos[i].philo_id = i + 1; // l'id commence a 1 
        philos[i].rules = rules;
        philos[i].meals = 0;
        gettimeofday(&current_time, NULL);
        philos[i].last_meal_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
        philos[i].left_fork = &forks[i]; // Fourchette a gauche = celle de son ID
        if (i == rules->number_of_philosophers - 1) // Fourchette a droite = celle du philosophe suivant
            philos[i].right_fork = &forks[0];
        else
            philos[i].right_fork = &forks[i + 1];
        i++;
    }
    
    return (philos);
}

void display_state(t_philo *philo, char *msg)
{
    struct timeval current_time;
    long long now;

    gettimeofday(&current_time, NULL);
    now = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    pthread_mutex_lock(&philo->rules->print_mutex);
    printf("%lld %d %s\n", now - philo->rules->start_time, philo->philo_id, msg);
    pthread_mutex_unlock(&philo->rules->print_mutex);
    return ;
}

void *routine(void *arg)
{
    t_philo *philo;
    struct timeval current_time;
    long long now;
    
    philo = (t_philo *)arg;
    
    while (42)
    {
        // tv_sec * 1000 : convertit les minutes en millisecondes
        // tv_usec / 1000 : convertit les secondes en millisecondes
        gettimeofday(&current_time, NULL);
        now = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
        if (now - philo->last_meal_time >= philo->rules->time_to_die)
        {
            display_state(philo, "died");
            return (NULL);
        }
        if (philo->rules->optional_arg == true &&
            philo->meals == philo->rules->number_of_times_each_philosopher_must_eat)
            return (NULL);
        
        if (philo->philo_id == philo->rules->number_of_philosophers)
        { // si c'est le dernier philo il commence par la fourchette droite
            pthread_mutex_lock(&philo->right_fork->mutex);
            display_state(philo, "has taken a fork");
            pthread_mutex_lock(&philo->left_fork->mutex);
            display_state(philo, "has taken a fork");
        }
        else
        {
            pthread_mutex_lock(&philo->left_fork->mutex);
            display_state(philo, "has taken a fork");
            pthread_mutex_lock(&philo->right_fork->mutex);
            display_state(philo, "has taken a fork");
        }
        philo->current = eating;
        display_state(philo, "is eating");
        philo->meals++;
        gettimeofday(&current_time, NULL);
        philo->last_meal_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
        usleep(philo->rules->time_to_eat * 1000); // 1 milliseconde = 1000 microsecondes
        pthread_mutex_unlock(&philo->left_fork->mutex);
        pthread_mutex_unlock(&philo->right_fork->mutex);
        philo->current = sleeping;
        display_state(philo, "is sleeping");
        usleep(philo->rules->time_to_sleep * 1000); 
        philo->current = thinking;
        display_state(philo, "is thinking");
    }
    
    return (NULL); // voir ce qu'il faut return
}

int main(int argc, char **argv)
{
    int i;
    t_rules *rules;
    t_philo *philos;
    t_fork *forks;
    pthread_t *threads;

    // ON INIT TOUS (les regles, les fourchettes et les philosophes)
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
    
    
    // PROGRAMME EN COURS
    threads = malloc(sizeof(pthread_t) * rules->number_of_philosophers);
    if (!threads)
        return (free(rules), free(forks), free(philos), 1);
    i = 0;
    while (i < rules->number_of_philosophers)
    {
        if (pthread_create(&threads[i], NULL, routine, &philos[i]) != 0)
        {
            while (i > 0)
            {
                 i--;
                pthread_join(threads[i], NULL); // On attend que chaque thread se termine
            }
            return (free(rules), free(forks), free(philos), free(threads), 1);
        }
        i++;
    }
    
    // A LA FIN DU PROGRAMME, IL FAUT :
    // Detruire tous les mutex
    // Puis liberer toute la memoire
    i = 0;
    while (i < rules->number_of_philosophers)
    {
        pthread_mutex_destroy(&forks[i].mutex);
        pthread_join(threads[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&rules->print_mutex);
    free(rules);
    free(philos);
    free(forks);
    free(threads);
    return (0);
}