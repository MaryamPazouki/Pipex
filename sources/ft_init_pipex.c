void ft_init_pipex(int *pipefd, int *infile, int *outfile, char **argv)
{
    pipefd[0] = -1;
    pipefd[1] = -1;
    *infile = open(argv[1], O_RDONLY);
    if (*infile == -1)
    {
        perror("Error opening input file!");
        exit(EXIT_FAILURE);
    }
    *outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*outfile == -1)
    {
        perror("Error opening output file!");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1)
    {
        perror("pipe creation failed!");
        exit(EXIT_FAILURE);
    }
}