/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:51:15 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:51:15 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
The  strcmp()  function  compares  the two strings s1 and s2.  
The locale is not taken into account (for a locale-aware comparison, see str‐
	   coll(3)).  It returns an integer less than, equal to, 
	   or greater than zero if s1 is found, respectively, 
	   to be less than, to  match,  or  be
	   greater than s2.

	   The strncmp() function is similar, except it 
	   compares only the first (at most) n bytes of s1 and s2.
	   
	   
	   
	 The  strcmp()  and  strncmp()  functions return an integer less than, 
	 equal to, or greater than zero if s1 (or the first n bytes thereof) is
	   found, respectively, to be less than, to match, or be greater than s2.
*/