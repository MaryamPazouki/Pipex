/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 08:39:21 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 08:39:21 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	else
	{
		new -> next = *lst;
		*lst = new;
	}
}

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Adds the node ’new’ at the beginning of the list



t_list **lst	: the address of a pointer to 
the first link of a list.
it is a pointer to the first node of a list

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new) // check if the list and the new node are not NULL
	{
		new -> next = *lst; 
		// the next of the new node is the first node of the list
		*lst = new; // the first node of the list is the new node
	}
}

*/