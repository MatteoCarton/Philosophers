/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:22:00 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 13:52:43 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*maillon1 = ft_lstnew("numero 1");
	t_list	*maillon2 = ft_lstnew("numero 2");
	t_list	*maillon3 = ft_lstnew("numero 3");
	t_list	*liste = maillon1;

	maillon1->next = maillon2;
	maillon2->next = maillon3;
    
	printf("Nombre de maillons = %d\n", ft_lstsize(liste));
    
	free(maillon1);
	free(maillon2);
	free(maillon3);
	return (0);
}
*/
