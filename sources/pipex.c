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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	ft_check_args(argc);
	data = ft_parse_args(argv);
	ft_init_pipex(data, argv);
	ft_execute(data, envp);
	ft_execute(data, envp);
	ft_cleanup(data);
	return (0);
}
