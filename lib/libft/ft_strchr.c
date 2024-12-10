/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:37:53 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:37:53 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		else
			str++;
	}
	if (chr == '\0')
		return ((char *)str);
	else
		return (NULL);
}

/*
The strchr() function returns a pointer to the first occurrence
 of the character c in the string s.

 The strchr() and strrchr() functions return a
 pointer to the matched character or 
 NULL if the character is not found.  The terminating  null
byte is considered part of the string, so that if c is specified as '\0', 
these functions return a pointer to the terminator.

*/