/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:26:03 by mcarton           #+#    #+#             */
/*   Updated: 2024/10/19 17:17:43 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nouvelle_liste;
	t_list	*nouveau_maillon;
	void	*nouveau_contenu;

	if (!lst || !f || !del)
		return (NULL);
	nouvelle_liste = NULL;
	while (lst)
	{
		nouveau_contenu = f(lst->content);
		nouveau_maillon = ft_lstnew(nouveau_contenu);
		if (!nouveau_maillon)
		{
			del(nouveau_contenu);
			ft_lstclear(&nouvelle_liste, del);
			return (NULL);
		}
		ft_lstadd_back(&nouvelle_liste, nouveau_maillon);
		lst = lst->next;
	}
	return (nouvelle_liste);
}
