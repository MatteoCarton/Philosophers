/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:00:46 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 15:15:25 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
void fonction_test(void *i)
{
    int *valeur = (int *) i;
    *valeur += 10;
}

int main(void)
{
    int *num1 = (int *)malloc(sizeof(int));
    int *num2 = (int *)malloc(sizeof(int));
    int *num3 = (int *)malloc(sizeof(int));

    *num1 = 1;
    *num2 = 2;
    *num3 = 3;

    t_list *maillon1 = ft_lstnew(num1);
    t_list *maillon2 = ft_lstnew(num2);
    t_list *maillon3 = ft_lstnew(num3);

    maillon1->next = maillon2;
    maillon2->next = maillon3;

    printf("AVANT LA FONCTION = \n");
    t_list *liste = maillon1;
    while (liste)
    {
        printf("Contenu : %d\n", *(int *)liste->content);
        liste = liste->next;
    }

    liste = maillon1;
    ft_lstiter(liste, fonction_test);
    printf("APRES LA FONCTION = \n");
    while (liste)
    {
        printf("Contenu : %d\n", *(int *)liste->content);
        liste = liste->next;
    }
    return 0;
}
*/
