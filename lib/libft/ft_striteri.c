/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:40:53 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:40:53 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s && f)
	{
		i = 0;
		while (*s)
		{
			f(i++, s++);
		}
	}
}

/*
void uppercase(unsigned int index, char *ch)
{
	*ch = toupper(*ch);
}

int main()
{
	char str[] = "hello";
	ft_striteri(str, uppercase);
	printf("%s\n", str); 
	return(0);
}
*/