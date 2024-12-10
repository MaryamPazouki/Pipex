#include "pipex.h"

int main(int argc, char **argv) {
    t_pipex *data;

    // Step 1: Check arguments
    ft_check_args(argc);

    // Step 2: Parse arguments
    data = ft_parse_args(argv);

    // Step 3: Initialize pipex
    ft_init_pipex(data, argv);

    // Step 4: Execute commands
    ft_exec(data, data->cmd1, 0); // Execute the first command
    ft_exec(data, data->cmd2, 1); // Execute the second command (last)

    // Step 5: Wait for the children to finish
   // waitpid(pid1, &status, 0); // Wait for the first child
    //waitpid(pid2, &status, 0); // Wait for the second child

    // Step 7: Cleanup
    ft_cleanup(data);

    return 0;
}
