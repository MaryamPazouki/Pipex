char	*ft_find_path(char *cmd, char **envp)
{
	char	**poss_paths;
	char	*cmd_path;
	int		index;
	char	*temp_path;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	poss_paths = ft_split(envp[index] + 5, ':');
	index = 0;
	while (poss_paths[index])
	{
		temp_path = ft_strjoin(poss_paths[index], "/");
		cmd_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	index = -1;
	while (poss_paths[++index])
		free(poss_paths[index]);
	free(poss_paths);
	return (0);
}