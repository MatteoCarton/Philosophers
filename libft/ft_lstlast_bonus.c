/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:05 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 14:13:21 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
    t_list *maillon1 = ft_lstnew("numero 1");
    t_list *maillon2 = ft_lstnew("numero 2");
    t_list *maillon3 = ft_lstnew("numero 3");
    t_list *liste;
    t_list *dernier;

    maillon1->next = maillon2;
    maillon2->next = maillon3;

    liste = maillon1;
    dernier = ft_lstlast(liste);
    printf("Le dernier maillon = %s\n", (char *)dernier->content);

    free(maillon1);
    free(maillon2);
    free(maillon3);
    return(0);
}
*/
