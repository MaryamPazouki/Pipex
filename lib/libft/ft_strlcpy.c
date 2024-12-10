/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 08:15:55 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-12 08:15:55 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

// #include <string.h>
// int  main(void)
// {
// char src[] = "Hello";
// char dest[6];
// strlcpy(dest, src, sizeof(dest));

// char src[] = "This is a very long string";
// char dest[10];
// strlcpy(dest, src, sizeof(dest));
// }

/*Advantages of strlcpy

	strlcpy is a function used in C programming to copy a string with a
	 guarantee of null-termination and to prevent buffer overflows. 
	The function copies up to size - 1 characters from the source string
	 to the destination buffer, null-terminating the result.

	Parameters

	dst: A pointer to the destination buffer where the string will be copied.
	src: A pointer to the source string that will be copied.
	size: The size of the destination buffer.

Return Value
	strlcpy returns the total length of the string it tried to create,
	 which is the length of src. This value can be used to
	  detect truncation by comparing it to size.

strlcpy returns the total length of the string it tried to create,
 which is the length of src. This value can be used to detect truncation
  by comparing it to size.

	Safety: Prevents buffer overflows by ensuring 
	that no more than size - 1 characters are copied to the destination buffer.
	Null-Termination: Guarantees that the destination buffer
	 is null-terminated if size is greater than 0.
	Ease of Use: Simplifies the process of copying strings safely,
	 making the code more readable and less error-prone.

Using strlcpy is a good practice when dealing with string copying in C,
 especially when the size of the destination buffer is known,
  and you want to ensure safe operations.
*/
