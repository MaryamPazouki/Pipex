

#include "pipex.h"

/*
main()
{
	ft_init_pipex()
	ft_check_args()
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
	ft_cleanup()
}
*/

#include "pipex.h"

int main(int argc, char **argv) {
    t_pipex data; // Declare the t_pipex structure

    // Step 1: Check arguments
    ft_check_args(argc);

    // Step 2: Initialize the pipex structure
    ft_init_pipex(&data, argv);

    // (Optional) Debugging: Print initialized values
    printf("Input file descriptor: %d\n", data.infile_fd);
    printf("Output file descriptor: %d\n", data.outfile_fd);
    printf("Pipe read end: %d\n", data.pipefd[0]);
    printf("Pipe write end: %d\n", data.pipefd[1]);

    // Step 3: Proceed with parsing and execution
    // Example placeholder for next steps
    // ft_parse_args(...);
    // ft_exec(...);

    // Cleanup resources
    ft_cleanup(&data);

    return 0;
}

