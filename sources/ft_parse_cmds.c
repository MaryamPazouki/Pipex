#include "pipex.h"

char **ft_parse_cmds(char *cmd) {
    // Split the command string into an array of arguments
    return ft_split(cmd, ' '); // Example: "ls -l" -> ["ls", "-l", NULL]
}
