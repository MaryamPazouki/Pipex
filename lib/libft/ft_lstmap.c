/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 07:18:39 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-24 07:18:39 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;
	void	*content_new;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		content_new = f(lst->content);
		node_new = ft_lstnew(content_new);
		if (!node_new)
		{
			del(content_new);
			ft_lstclear(&lst_new, (*del));
			return (lst_new);
		}
		ft_lstadd_back(&lst_new, node_new);
		lst = lst->next;
	}
	return (lst_new);
}
