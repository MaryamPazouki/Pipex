/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:22:22 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:22:22 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (s);
}

/*DESCRIPTION
	The memset() function fills the first n bytes of 
	the memory area pointed to by s with the constant byte c.

RETURN VALUE
	The memset() function returns a pointer to the memory area s.
	  
It starts by assigning the value of str to a variable 
ptr to keep track of the original pointer.

This function is commonly used to initialize memory or 
set memory regions to a specific value, 
such as setting an array of characters to null terminators 
or setting an array of integers to zeros.
	*/