/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 08:51:59 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 08:51:59 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
/*
int main()
{
	t_list *head = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("NOde 2");
	t_list *node3 = ft_lstnew("Node 3");

	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	int size = ft_lstsize(head);
	printf("The size of the list is %d\n", size);

	return 0;

}
*/
