char *get_command_path(char *cmd, char **envp) {
    char **path_dirs;      // Directories from PATH
    char *path_var;        // The PATH environment variable
    char *full_path;       // Full path to the command
    int i;

    // 1. Retrieve PATH variable from envp
    path_var = find_env_variable("PATH", envp);
    if (!path_var)
        return NULL; // PATH is not set, return NULL

    // 2. Split PATH into directories
    path_dirs = ft_split(path_var, ':'); // Use your splitting function
    if (!path_dirs)
        return NULL; // Memory allocation error

    // 3. Iterate through each directory in PATH
    i = 0;
    while (path_dirs[i]) {
        full_path = ft_strjoin(path_dirs[i], "/");
        full_path = ft_strjoin(full_path, cmd); // Append command to the directory

        // 4. Check if the file exists and is executable
        if (access(full_path, X_OK) == 0) {
            free_path_dirs(path_dirs); // Free the array of directories
            return full_path; // Return the valid path
        }

        // Free the full_path for the current iteration
        free(full_path);
        i++;
    }

    // 5. Cleanup if command not found
    free_path_dirs(path_dirs); // Free the array of directories
    return NULL; // Command not found
}

char *find_env_variable(char *var_name, char **envp) {
    int i = 0;

    while (envp[i]) {
        if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0
            && envp[i][ft_strlen(var_name)] == '=') {
            return &envp[i][ft_strlen(var_name) + 1]; // Return the value after '='
        }
        i++;
    }
    return NULL;
}
