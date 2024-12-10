/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 07:36:21 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-12 07:36:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>  // or #include <bsd/ctype.h> for some environments

int main() {
    int ch;

    printf("Enter a character: ");
    ch = getchar();

    if (ft_isascii(ch)) {
        printf("The character '%c' is an ASCII character.\n", ch);
    } else {
        printf("The character '%c' is not an ASCII character.\n", ch);
    }

    return 0;
}
*/