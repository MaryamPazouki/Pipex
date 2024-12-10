/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 07:14:42 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-12 07:14:42 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char d;

    printf("Enter a character: ");
    scanf("%c", &d);

    if (ft_isdigit(d)) {
        printf("%c is a digit.\n", d);
    } else {
        printf("%c is not a digit.\n", d);
    }

    return 0;
}
*/