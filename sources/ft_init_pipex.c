#include "pipex.h"

void ft_init_pipex(t_pipex *data, char **argv) 
{
	// Open input file
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd < 0) {
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}

	// Open output file
	data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	/*	Opens or creates the output file in write-only mode.
		The file is created if it doesn’t exist (O_CREAT) and truncated to zero length if it exists (O_TRUNC).
		File permissions are set to 0644 (readable by all, writable by the owner).
	*/

	
	if (data->outfile_fd < 0) {
		perror("Error opening output file");
		close(data->infile_fd); // Cleanup before exiting
		exit(EXIT_FAILURE);
	}

	// Create a pipe
	// pipefd[0] is the read end, and pipefd[1] is the write end.
	if (pipe(data->pipefd) == -1) {
		perror("Pipe creation failed");
		close(data->infile_fd);  // Cleanup before exiting
		close(data->outfile_fd);
		exit(EXIT_FAILURE);
	}
}
