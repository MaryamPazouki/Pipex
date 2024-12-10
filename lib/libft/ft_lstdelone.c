/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 11:15:37 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 11:15:37 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst -> content);
	free(lst);
	lst = NULL;
}

/*
void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst ||	!del)	
		return ;
	(del)(lst -> content); 
	// This line is calling the function del 
	with the content of the list as an argument
	free(lst);// This line is freeing the memory of the list
	lst = NULL;// This line is setting the pointer to the list to NULL
}
*/
