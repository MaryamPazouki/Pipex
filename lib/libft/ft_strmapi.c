/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:47:45 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:47:45 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_loc(size_t n)
{
	char	*str;

	str = (char *)malloc (sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	str = str_loc (ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
static char uppercase(unsigned int i, char c)
{
	if (i % 2 == 0)
		return toupper(c);
	else
		return tolower(c);
}

int main()
{
	char *result;
	result =  ft_strmapi("Hello, World!", uppercase);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return(0);
}
*/