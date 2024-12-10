/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:10:16 by MPazouki          #+#    #+#             */
/*   Updated: 2024/06/19 23:10:17 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
void main()
{
    ft_putchar_fd('A', 1);

    ft_putchar_fd('\n', 2);

    ft_putchar_fd('\t', 0);
}
*/

/*
You can use write to write data directly to a file, 
a device, or a socket.

*/