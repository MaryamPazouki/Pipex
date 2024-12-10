/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:17:08 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:17:08 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void	*src, size_t	numBytes)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	while (numBytes--)
	{
		*(char *) dest++ = *(char *) src++;
	}
	return (dest_ptr);
}

/*DESCRIPTION
	   The  memcpy()  function  copies n bytes from memory 
	   area src to memory area dest.  
	   The memory areas must not overlap.  Use memmove(3) if the
	   memory areas do overlap.

RETURN VALUE
	   The memcpy() function returns a pointer to dest.*/