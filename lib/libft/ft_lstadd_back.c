/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 10:58:31 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 10:58:31 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = (t_list *)malloc(sizeof(t_list));
	if (!last)
		return (NULL);
	last = ft_lstlast (*lst);
	if (*lst == NULL) // if the list is empty
		*lst = new; //	add the new node at the start of the list
	else
	{ // if the list is not empty
		last = ft_lastlast(*lst); // get the last node of the list 
		last -> next = new; //	add the new node at the end of the list
	}
	
}
*/