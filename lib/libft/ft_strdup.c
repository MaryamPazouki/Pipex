/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:39:04 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:39:04 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dups;

	len = ft_strlen(s) + 1;
	dups = malloc(len);
	if (dups == NULL)
		return (NULL);
	ft_memcpy (dups, s, len);
	return (dups);
}

/*DESCRIPTION
	   The strdup() function returns a pointer to a new string
		which is a duplicate of the string s.  Memory for the new string 
		is obtained with malloc(3), and can be freed with free(3).
RETURN VALUE
	   On success, the strdup() function returns a pointer to
		the duplicated string.  It returns NULL if insufficient memory
		 was available, with errno set to indicate the cause of the error.*/

/*


int main() {
	const char *original = "Hello, World!";
	char *duplicate = ft_strdup(original);

	if (duplicate != NULL) {
		printf("Original string: %s\n", original);
		printf("Duplicated string: %s\n", duplicate);
		free(duplicate); // Free memory allocated by strdup
	} else {
		printf("Memory allocation failed!\n");
	}

	return 0;
}
*/