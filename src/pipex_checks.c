#include "pipex.h"

char *ft_check_cmd(char *cmd, char *const envp[])
{
	char **path_tab;
	char *tmp;
	int res;
	int i;

	i = 0;
	path_tab = ft_getenvpaths(envp);
	cmd = ft_getfwd(cmd);
	res = -1;
	// try out every path
	while(path_tab[i])
	{
		tmp = ft_strjoin_path(path_tab[i], cmd);
		res = access(tmp, R_OK);
		if (res == 0)
			break;
		free(tmp);
		i++;
	}
	ft_free_tab(path_tab);
	free(cmd);
	if (res == 0)
		return (tmp);
	return NULL;
}

void ft_raise_err(char *err_str, int err_nb)
{
	perror(err_str);
	exit(err_nb);
}

void set_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		ft_raise_err("Pipe creation error", 3);
	}
}

int set_fork(void)
{
	int pid;

	pid = fork();
	if (pid == -1)
		ft_raise_err("Fork error", 5);
	return (pid);
}

void	check_args(int argc, char *argv[])
{
	int fd_in;
	int fd_out;
	if (argc < 5)
		ft_raise_err("Not enough arguments\nUsage : ./pipex infile cmd1 cmd2 outfile",
				2);
	// check input or output files
	
	fd_in = open(argv[1], O_RDONLY, 0644);
	
	if(fd_in == -1)
	{
		ft_raise_err(ERR_INFILE, 1);
	}
	close(fd_in);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		ft_raise_err(ERR_OUTFILE, 1);
	}
	close(fd_out);
}
