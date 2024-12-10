#include"pipex.h"


t_pipex *ft_parse_args(char **argv) {
    t_pipex *data = malloc(sizeof(t_pipex));
    if (!data)
        return NULL;

    data->cmd1 = ft_parse_cmds(argv[2]);
    data->cmd2 = ft_parse_cmds(argv[3]);
    data->infile = argv[1];
    data->outfile = argv[4];

    return data;
}
