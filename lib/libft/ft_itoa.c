/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-17 07:10:21 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-17 07:10:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*snew(size_t new_len)
{
	char	*new_loc;

	new_loc = (char *)malloc (sizeof(char) * (new_len));
	if (!new_loc)
		return (NULL);
	return (new_loc);
}

static long long	abs_val(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	nbr_len(int nbr)
{
	size_t	len_nbr;

	len_nbr = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len_nbr++;
	while (nbr)
	{
		nbr /= 10;
		len_nbr++;
	}
	return (len_nbr);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			len;
	int			is_negative;

	nbr = n;
	if (nbr < 0)
		is_negative = 1;
	else
		is_negative = 0;
	len = nbr_len(nbr);
	str = snew(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = abs_val(nbr);
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

/*
void main()
{
	printf("to characture, %s,", ft_itoa(12345));
	printf("to characture, %s,", ft_itoa(-648));
	printf("to characture, %s,", ft_itoa(0));
	printf("to characture, %s,", ft_itoa(-2147483648));
	printf("to characture, %s,", ft_itoa(2147483647));
}
*/