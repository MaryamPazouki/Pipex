/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 07:50:31 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-12 07:50:31 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*
#include <strings.h> // For bzero
#include <stdio.h>
#include "libft.h"

int main() {
    char buffer[10];
    ft_bzero(buffer, 10); // Set all bytes of buffer to 0

    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]); // Will print "0 0 0 0 0 0 0 0 0 0 "
    }

    return 0;
}
*/