#include "pipex.h"

void ft_cleanup(t_pipex *data) 
{
	free(data->cmd1);
	free(data->cmd2);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
