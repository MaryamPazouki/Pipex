#include "pipex.h"

void ft_cleanup(t_pipex *data, int *pipefd) {
    free(data->cmd1);
    free(data->cmd2);
    close(pipefd[0]);
    close(pipefd[1]);
}
