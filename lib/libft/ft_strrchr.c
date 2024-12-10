/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:54:46 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:54:46 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char const		*collect;
	unsigned char	chr;

	chr = (unsigned char)c;
	collect = NULL;
	while (*str)
	{
		if (*str == chr)
			collect = str;
		str++;
	}
	if (chr == '\0')
		return ((char *)str);
	else
		return ((char *)collect);
}

/*The strrchr() function returns a pointer to the last
 occurrence of the character c in the string s.
The strchr() and strrchr() functions return a pointer to 
the matched character or NULL if the character is not found.
  The terminating  null
	   byte is considered part of the string, so that if c is specified as '\0'
	   , these functions return a pointer to the terminator.*/