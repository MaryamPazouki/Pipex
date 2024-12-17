/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:56:35 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:56:35 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_init_pipex(t_pipex *data, char **argv) {
    // Open input file
    data->infile_fd = open(argv[1], O_RDONLY);
    if (data->infile_fd < 0) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    //printf("Input file descriptor: %d\n", data->infile_fd);

    // Open output file
    data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (data->outfile_fd < 0) {
        perror("Error opening output file");
        close(data->infile_fd); // Cleanup before exiting
        exit(EXIT_FAILURE);
    }
    //printf("Output file descriptor: %d\n", data->outfile_fd);

    // Create a pipe
    if (pipe(data->pipefd) == -1) {
        perror("Pipe creation failed");
        close(data->infile_fd);  // Cleanup before exiting
        close(data->outfile_fd);
        exit(EXIT_FAILURE);
    }
    //printf("Pipe file descriptors: %d, %d\n", data->pipefd[0], data->pipefd[1]);
}

