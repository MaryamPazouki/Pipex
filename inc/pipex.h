/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:57:16 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:57:16 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

// Define the structure to hold program data
typedef struct s_pipex {
    char    **cmd1;       // Parsed command 1 (e.g., ["ls", "-l", NULL])
    char    **cmd2;       // Parsed command 2 (e.g., ["wc", "-l", NULL])
    char    *infile;      // Input file name
    char    *outfile;     // Output file name
    int     infile_fd;    // File descriptor for infile
    int     outfile_fd;   // File descriptor for outfile
    int     pipefd[2];    // Pipe file descriptors (pipefd[0] = read, pipefd[1] = write)
}   t_pipex;

// Function prototypes
void ft_init_pipex(t_pipex *data, char **argv);
void ft_check_args(int argc);
char **ft_parse_cmds(char *cmd);
t_pipex *ft_parse_args(char **argv);
char	*ft_find_path(char **cmd, char **envp);
void ft_execute(t_pipex *data, char **envp);
void ft_cleanup(t_pipex *data);
void	child_process(t_pipex *data, char **envp);
void	parent_process(t_pipex *data, char **envp);
void	ft_error(void);
size_t  safe_strlen(const char *s);
char *ft_strjoin_double_ptr(const char *s1, char **s2);

#endif
