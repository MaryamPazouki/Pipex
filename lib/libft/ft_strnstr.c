/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:52:09 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:52:09 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	i = 0;
	while (*big && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && little[j] != '\0')
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*
The ft_strnstr function 
searches for the first occurrence of a substring
 within a given string, up to a specified length.
Return
If the substring is found, a pointer to the first
 occurrence of the substring within the string is returned.
If the substring is not found or if n is zero, NULL is returned.*/