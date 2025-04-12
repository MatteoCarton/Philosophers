/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:20:35 by mcarton           #+#    #+#             */
/*   Updated: 2025/04/12 23:00:31 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
        argv[i] = ft_atoi(argv[i]);
        i++;
    }
    return (1);
}

int init_rules()
{
    
}

int main(int argc, char **argv)
{
    if(argc != 5 && argc != 6)
        return (1);
    if (init_rules() == 0)
        return (1);
    if (check_arguments(argc, argv) == 0)
        return (1);
}