/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:56:40 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:56:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_parse_args(char **argv)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1 = ft_parse_cmds(argv[2]);
	if (!data->cmd1)
	{
		perror("Failed to parse cmd1");
		free(data);
		exit(EXIT_FAILURE);
	}
	data->cmd2 = ft_parse_cmds(argv[3]);
	if (!data->cmd2)
	{
		perror("Failed to parse cmd2");
		ft_cleanup(data);
		exit(EXIT_FAILURE);
	}
	return (data);
}
