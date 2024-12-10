#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"


typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_pipex
{
	int     in_fd;
	int     out_fd;
	t_bool	here_doc; // use `int` if you prefer
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
} t_pipex;


#endif