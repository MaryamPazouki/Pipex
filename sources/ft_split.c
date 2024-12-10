/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-17 09:51:18 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-17 09:51:18 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
		{
			i++;
		}
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t			words;
	char			**array;

	words = count_word(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}

/*

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

void print_array(char **arr)
{
	if (arr == NULL)
	{
		printf("Array is NULL\n");
		return;
	}
	for (int i = 0; arr[i] != NULL; i++)
	{
		printf("%s\n", arr[i]);
	}
}

int main()
{
    const char *comma_str = "Hello,World,Split,Me";
    char **comma_split_array = ft_split(comma_str, ',');
    printf("Comma-separated string:\n");
    print_array(comma_split_array);

    const char *space_str = "";
    char **space_split_array = ft_split(space_str, ' ');
    printf("\nSpace-separated string:\n");
    print_array(space_split_array);

    const char *empty_str = "";
    char **empty_split_array = ft_split(empty_str, ',');
    printf("\nEmpty string:\n");
    print_array(empty_split_array);

    const char *single_word_str = "Hello";
    char **single_word_split_array = ft_split(single_word_str, ' ');
    printf("\nSingle word string:\n");
    print_array(single_word_split_array);

    const char *dash_str = "123-456-789-0";
    char **dash_split_array = ft_split(dash_str, '-');
    printf("\nDash-separated string:\n");
    print_array(dash_split_array);

    return 0;
}
*/