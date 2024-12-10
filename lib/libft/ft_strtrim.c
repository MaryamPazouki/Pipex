/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:55:54 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:55:54 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char src, const char *set)
{
	while (*set)
	{
		if (src == *set++)
			return (1);
	}
	return (0);
}

static char	*snew(size_t newlen)
{
	char	*new_loc;

	new_loc = (char *)malloc(sizeof(char) * (newlen));
	if (!new_loc)
		return (NULL);
	return (new_loc);
}

static char	*str_new_aloc(char *dest, const char *src, size_t src_len )
{
	size_t	i;

	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s_new;
	int			start;
	int			end;
	int			len;
	const char	*s1_start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set(s1[end - 1], set))
		end--;
	s_new = snew(end - start + 1);
	if (!s_new)
		return (NULL);
	len = end - start;
	s1_start = s1 + start;
	s_new = str_new_aloc(s_new, s1_start, len);
	return (s_new);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char str[] = "\tHello, World!\t  ";
// 	char set[] = "\t";
// 	char *trimmed = ft_strtrim(str, set);

// 	printf("Trimmed string: '%s'\n", trimmed);
// 	free(trimmed); // Don't forget to free the allocated memory
// 	return 0;
// }
