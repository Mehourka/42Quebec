#include "pipex.h"


/*
Checks if command (first word of cmd string) exists in path
return the path if it exists, else NULL
*/


/*
Extracts the PATH env variable as a string
*/
char **ft_getenvpaths(char *const envp[])
{
	char *env_paths;
	char **tab;

	env_paths = "";
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			env_paths = ft_strdup(*envp + 5);
		}
		envp++;
	}
	tab = ft_split(env_paths, ':');
	free(env_paths);
	return tab;
}

/*
Free ft_split tab
*/
void ft_free_tab(char **tab)
{
	int i = 0;

	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
Str join but add  '/' between joined words
*/
char	*ft_strjoin_path(const char *str1, const char *str2)
{
	char	*new_string;
	size_t	len_str1;
	size_t	len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	new_string = malloc(len_str1 + len_str2 + 2);
	if (!new_string)
		return (NULL);
	new_string[len_str1 + len_str2 + 1] = '\0';
	ft_memcpy(new_string, (void *)str1, len_str1);
	ft_memcpy((new_string + len_str1), "/",1);
	ft_memcpy((new_string + len_str1 + 1), (void *)str2, len_str2);
	return (new_string);
}

/*
Gets the first word of a string
*/
char *ft_getfwd(char *str)
{
	int i;
	char *word;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && !ft_iswhitsp(str[i]))
		i++;
	word = ft_substr(str, 0, i);
	return (word);
}

// Check if char is whitespace
int ft_iswhitsp(char c)
{
	return ((c >= 9 && c <=13) || c == 32);
}


/*
Executes a Unix string command
*/
int exec_strcmd(char *cmd, char *const envp[])
{
	char **cmd_tab;
	char *cmd_path;
	char *next_quote;
	int i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == ' ')
			cmd[i] = '\t';
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			next_quote = ft_strchr(&cmd[i + 1], cmd[i]);
			if (next_quote)
			{
				cmd[i] = '\t';
				*next_quote = '\t';
				i += next_quote - &cmd[i];
			}
		}	
		i++;
	}
	cmd_tab = ft_split(cmd, '\t');
	cmd_path = ft_check_cmd(cmd, envp);

	if (cmd_path)
		execve(cmd_path, cmd_tab, envp);
	ft_free_tab(cmd_tab);
	ft_raise_err("command not found", 1);
	return (2);
}
/*
Sets and duplicats input and set output file descriptors according to cmd
Returns the file descriptor of the output
*/
void ft_setio(t_data *data)
{
	int i;
	int argc;
	char **argv;

	i = data->cmd_idx;
	argc = data->argc;
	argv = data->argv;

	if (i == 2)
	{
		data->in = open(argv[1], O_RDONLY, 0644);
	} else {
		data->in = data->fd[0];
	}
	
	if (i == data->argc - 2)
		data->out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
	{
		set_pipe(data->fd);
		data->out = data->fd[1];
	}
}

t_data init_data(int argc, char *argv[])
{
	t_data	data;
	int		static fd[2];

	data.argc = argc;
	data.argv = argv;
	data.fd = fd;
	data.in = 0;
	data.out = 0;
	data.cmd_idx = 2;

	return data;
}
