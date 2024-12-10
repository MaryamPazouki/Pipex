
#include "pipex.h"

void ft_check_args(int argc) {
    if (argc != 5) {
        fprintf(stderr, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
        exit(EXIT_FAILURE);
    }
}
