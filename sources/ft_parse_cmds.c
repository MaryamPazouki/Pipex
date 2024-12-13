/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:56:45 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:56:45 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **ft_parse_cmds(char *cmd) {
    // Split the command string into an array of arguments
    return ft_split(cmd, ' '); // Example: "ls -l" -> ["ls", "-l", NULL]
}
