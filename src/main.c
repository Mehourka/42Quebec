#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "pipex.h"
#include <string.h>
#include <sys/wait.h>

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



int main(int argc, char *argv[], char *const envp[])
{

	char *env_path;
	char **cmd_tab;
	char *cmd_path;
	int pid;
	int err;
	int wstatus;

	// Check number of arguments
	if (argc < 2)
	{
		printf("Invalid number of arguments \n");
		return (1);
	}

	// Split command
	cmd_tab = ft_split(argv[1], ' ');
	// Check cmd exists and get path
	cmd_path = ft_check_cmd(argv[1], envp);

	err = 0;

	// Forking
	pid = fork();

			// Child Process
	if (pid == 0)
	{
		err = execve(cmd_path, cmd_tab, envp);
		if (err == -1)
			printf("Execve ERROR\n");
		return (2);
	}
			// Parent process
	else{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statuscode = WEXITSTATUS(wstatus);
			if (statuscode == 0)
			{
				printf("Success !\n");
			} else
			{
				perror("FAILED PIPEX\n");
			}
		}
	}
	free(cmd_path);
	return (0);
}



/*
	int pid = fork();
	// Execute command
	if (pid)
	{
		// Parent process
		int wstatus;

		wait(&wstatus);

		if (WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success !\n");
			else
				printf("Failed ! with status code %d\n", statusCode);
		}
	}
	else
	{
		// Child process
		int err = execve(path, ft_split(cmd, ' '), envp);
		perror(NULL);
		if (err == -1){
			printf("Execution error\n");
		}
		return (1);

	}
 */