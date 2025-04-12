/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:28:16 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 14:59:50 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
void del(void *content)
{
    free(content);
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

    ft_lstclear(&maillon1, del);
    printf("APRES LA FONCTION = \n");
    while (liste)
    {
        printf("Contenu : %d\n", *(int *)liste->content);
        liste = liste->next;
    }
    return 0;
}
*/
