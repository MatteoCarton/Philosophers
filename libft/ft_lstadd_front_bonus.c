/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:07:48 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/18 18:24:32 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int	main(void)
{
	t_list *maillon1 = (t_list *)malloc(sizeof(t_list));
	t_list *maillon2 = (t_list *)malloc(sizeof(t_list));

	maillon1->content = "Salut";
	maillon1->next = NULL;

	maillon2->content = "Yooo";
	maillon2->next = NULL;

	// permet de dire que la liste commence par le maillon 1
	t_list *list = maillon1;

	ft_lstadd_front(&list, maillon2);
	while (list)
	{
		printf("Contenu = %s\nPtr = %p\n", (char *)list->content, list->next);
		list = list->next;
	}
	free(maillon1);
	free(maillon2);

	return (0);
}
*/
