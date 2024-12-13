/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:55:51 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:55:51 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



size_t safe_strlen(const char *s) {
    return s ? strlen(s) : 0;
}

char *ft_strjoin_double_ptr(const char *s1, char **s2) {
    if (!s1 || !s2 || !*s2) {
        return NULL; // Handle NULL input
    }

    size_t len1 = safe_strlen(s1);
    size_t len2 = safe_strlen(*s2);
    char *result = malloc(len1 + len2 + 1);

    if (!result) {
        return NULL; // Handle memory allocation failure
    }

    // Copy s1 into result
    if (s1) {
        strcpy(result, s1);
    }

    // Concatenate *s2 to result
    if (*s2) {
        strcpy(result + len1, *s2);
    }

    return result;
}


char	*ft_find_path(char **cmd, char **envp)
{
	char	**poss_paths;
	char	*cmd_path;
	int		index;
	char	*temp_path;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	poss_paths = ft_split(envp[index] + 5, ':');
	index = 0;
	while (poss_paths[index])
	{
		temp_path = ft_strjoin(poss_paths[index], "/");
		cmd_path = ft_strjoin_double_ptr(temp_path, cmd);
		free(temp_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	index = -1;
	while (poss_paths[++index])
		free(poss_paths[index]);
	free(poss_paths);
	return (0);
}