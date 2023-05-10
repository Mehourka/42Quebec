int ft_check_cmd(char *cmd, char *env_paths)
{
	// first, let's check a single known file
	char **path;
	char *tmp;
	int res;

	path = ft_split(env_paths, ':');
	free(env_paths);

	res = -1;
	// try out every path
	while(*path)
	{
		tmp = ft_strjoin(*path, "/"); // LEAK HERE
		tmp = ft_strjoin(tmp, cmd); // idea : Maybe check that te joind str is a valid folder (has '/')
		res = access(tmp, R_OK);
		printf("Checking  : %s\n", tmp);
		if (res == 0)
		{
			break;
		}
		free(tmp);
		path++;
	}

	// free(path); // TODO c
	return res;

}

/*
Extracts the PATH env variable as a string
*/ 
char *ft_getenvpath(char *const envp[])
{
	char *env_paths;

	env_paths = "";
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			env_paths = ft_strdup(*envp + 5);
		}
		envp++;
	}
	return env_paths;
}