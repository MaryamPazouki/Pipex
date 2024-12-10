#include "pipex.h"

void ft_exec(t_pipex *data, char **cmd, int is_last) {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        ft_cleanup(data); // Ensure cleanup before exiting
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        if (is_last) {
            // Redirect pipe input to stdin and output to the outfile
            dup2(data->pipefd[0], STDIN_FILENO);
            dup2(data->outfile_fd, STDOUT_FILENO);
        } else {
            // Redirect input from infile and output to the pipe
            dup2(data->infile_fd, STDIN_FILENO);
            dup2(data->pipefd[1], STDOUT_FILENO);
        }

        // Close unused pipe ends
        close(data->pipefd[0]);
        close(data->pipefd[1]);

        // Execute the command
        for (int i = 0; cmd[i] != NULL; i++) {
            printf("cmd[%d]: %s\n", i, cmd[i]);
        }

        execvp(cmd[0], cmd);
        perror("Command execution failed"); // This only runs if exec fails
        ft_cleanup(data);
        exit(EXIT_FAILURE);
    }
}
