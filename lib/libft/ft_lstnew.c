/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 08:08:41 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 08:08:41 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
/*
int main(void)
{
    int value = 42;
    t_list *node = ft_lstnew(&value);

    if (node)
    {
        printf("Node created successfully!\n");
        printf("Node content: %d\n", *(int *)(node->content));
    }
    else
    {
        printf("Failed to create node.\n");
    }

    // Free the allocated memory
    free(node);

    return 0;
}
*/