/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:55:41 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:55:41 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp) {
    t_pipex *data;

    // Step 1: Check arguments
    ft_check_args(argc);

    // Step 2: Parse arguments
    data = ft_parse_args(argv);

    // Step 3: Initialize pipex
    //ft_init_pipex(data, argv);

    // Step 4: Execute commands
    ft_execute(data, envp); // Execute the first command
    ft_execute(data, envp); // Execute the second command (last)

   
    // Step 7: Cleanup
    ft_cleanup(data);

    return 0;
}
