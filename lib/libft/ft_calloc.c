/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-20 07:44:00 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-20 07:44:00 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero (array, (nmemb * size));
	return (array);
}

/*
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

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num_elements = 5;
	int element_size = sizeof(int);
	int *arr;

	// Allocate memory for an array of 5 integers
	arr = (int *)ft_calloc(num_elements, element_size);

	if (arr == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	// Initialize the array elements 
	(although calloc already initializes them to zero)
	for (int i = 0; i < num_elements; ++i) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// Free the allocated memory when done using it
	free(arr);

	return 0;
}*/
/*
The calloc() function allocates memory for an array of nmemb 
elements of size bytes each and returns 
a pointer to the allocated memory.  
The memory is set to zero.  If nmemb or size is 0, 
then calloc() returns either NULL, or a unique pointer value
that  can  later be successfully passed to free().  
If the multiplication of nmemb and size would result 
in integer overflow, then calloc() returns an error.  
By contrast, an integer overflow would not be detected 
in the following call to malloc(),
with the result that an incorrectly sized block 
of memory would be allocated:

		   malloc(nmemb * size);*/