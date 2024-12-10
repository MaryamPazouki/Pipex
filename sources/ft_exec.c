#include "pipex.h"


void ft_exec(int *pipefd, char **cmd, int infile, int outfile, int is_last) 
{
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		if (is_last) {
			dup2(pipefd[0], STDIN_FILENO);
			dup2(outfile, STDOUT_FILENO);
		} else {
			dup2(infile, STDIN_FILENO);
			dup2(pipefd[1], STDOUT_FILENO);
		}
		close(pipefd[0]);
		close(pipefd[1]);

		execvp(cmd[0], cmd);
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}
}
