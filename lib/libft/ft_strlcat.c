/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 08:33:14 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-12 08:33:14 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen (dest);
	slen = ft_strlen (src);
	i = dlen;
	j = 0;
	if (size != 0 && dlen < size - 1)
	{
		while (i < size - 1 && src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	if (dlen >= size)
		return (slen + size);
	else
		return (dlen + slen);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char first[] = "This is ";
// 	char last[] = "a potentially long string";
// 	int r;
// 	int size = 16;
// 	char buffer[size];

// 	strcpy(buffer,first);
// 	r = strlcat(buffer,last,size);

// 	puts(buffer);
// 	printf("Value returned: %d\n",r);
// 	if( r > size )
// 		puts("String truncated");
// 	else
// 		puts("String was fully copied");

// 	return(0);
// }

/*Parameters

	dst: A pointer to the destination buffer where the concatenation will occur.
	src: A pointer to the source string that will 
	be concatenated onto the destination.
	size: The size of the destination buffer.

Return Value

strlcat returns the total length of the resulting string after concatenation. 
If the resulting string length is greater than or equal to size,
 truncation has occurred.


*/