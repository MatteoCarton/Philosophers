/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:55:32 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 14:18:19 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dernier;

	dernier = ft_lstlast(*lst);
	if (!dernier)
	{
		*lst = new;
		return ;
	}
	dernier->next = new;
}
/*
int main(void)
{
    t_list *maillon1 = ft_lstnew("numero 1");
    t_list *maillon2 = ft_lstnew("numero 2");
    t_list *maillon3 = ft_lstnew("numero 3");
    t_list *new_maillon = ft_lstnew("le nouveau");
    t_list *liste;

    maillon1->next = maillon2;
    maillon2->next = maillon3;
    liste = maillon1;
    
   ft_lstadd_back(&liste, new_maillon);

    while (liste)
	{
		printf("Contenu = %s Ptr = %p\n", (char *)liste->content, liste->next);
		liste = liste->next;
	}

    free(maillon1);
    free(maillon2);
    free(maillon3);
    return(0);
}
*/
