/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:56:21 by mpazouki          #+#    #+#             */
/*   Updated: 2024-12-13 10:56:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void ft_cleanup(t_pipex *data) 
{
	free(data->cmd1);
	free(data->cmd2);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
