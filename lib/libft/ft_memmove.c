/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:18:33 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:18:33 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (ptr_dest == ptr_src)
	{
		return (dest);
	}
	if (ptr_src < ptr_dest && (ptr_dest < ptr_src + n))
	{
		while (n--)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (ptr_dest);
}

/*DESCRIPTION
	   The memmove() function copies n bytes from memory area src
	    to memory area dest.  
	   The memory areas may overlap: copying takes place as though
	   the bytes in src are first copied into a temporary array
	    that does not overlap src or dest, 
	   and the bytes are then copied from the temporary array to dest.

RETURN VALUE
	   The memmove() function returns a pointer to dest.
	   
	   
Key Points
	Pointer Setup: We first cast the void* pointers dest
	 and src to unsigned char* because 
	unsigned char has a size of 1 byte, 
	making it suitable for byte-wise operations.

	Overlapping Regions: 
	memmove ensures that overlapping regions are handled correctly. 
	For example, if src and dest overlap,
	 memmove will ensure that the data is not corrupted.
	Non-overlapping Regions: For non-overlapping memory regions,
	 memmove behaves the same as memcpy.
*/

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char str[] = "Hello, World!";
// 	printf("Original string: %s\n", str);

// 	// Move part of the string to a new location within the same array
// 	memmove(str + 7, str, 5);
// 	printf("Modified string: %s\n", str);

// 	return 0;
// }