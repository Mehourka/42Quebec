#include "pipex.h"

#include <stdio.h>

/*
Testing programm execution

Parsing :
	Take the command from argcv and verify it's valid ==> DONE
	? Verify the flags or just return the output ? : Probably just the flags

Pre-process :
	Extract the PATH env variable  ==> DONE


Execution :
	Replicate execpl() with execve ==> DONE
	Print to stdout
 */

void print_fd(fd)
{
	char buff[10];

	ft_putstr_fd("Input content :", 1);
	read(fd, buff, 3);
	write(1, buff, 3);
	write(1, "\n", 1);
}

int main(int argc, char *argv[], char *const envp[])
{
	int fd[2];
	int input; 
	int output;
	int pid;
	int i;	

	input= open(argv[1], O_RDONLY, 0700);
	i = 2;

	while (i < argc - 1)
	{
		dup2(input, STDIN_FILENO);
		close(fd[0]);
		if(pipe(fd) == -1){return 1;}
		pid = fork();
		if(pid == -1) {return 2;}
		if (pid == 0){
			// Child process 1 (ping)
			if (i == argc - 2)
				output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0700);
			else 
				output = fd[1];

			dup2(output, STDOUT_FILENO);

			close(fd[0]);
			close(fd[1]);
			close(input);
			close(output);


			// exec_strcmd(argv[i], envp, )
			char **cmd_tab = ft_split(argv[i], ' ');
			char *cmd_path = ft_check_cmd(argv[i], envp);
			execve(cmd_path, cmd_tab, envp);
			return (1);
		}
		int wstat;

		// printf("pid : %d\nwait status : %d\n", pid, wstat);
		input = fd[0];
		close(fd[1]);
		i++;
	}
	waitpid(-1, NULL, 0);
	return (0);
}
