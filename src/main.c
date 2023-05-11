#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "pipex.h"
#include <string.h>

//	Testing programm execution

//	Parsing 
//		Take the command from argcv and verify it's valid
//		? Verify the flags or just return the output ?

//	Pre-process
//		Extract the PATH env variable ; DONE
//		

//	Execution
//		Replicate execpl() with execve : DONE
//		Print to stdout 
//		

int main(int argc, char *argv[], char *const envp[])
{

	char *env_path;
	char *cmd_path;
	// Recuperer les arguments

	// Check number of arguments
	if (argc < 2)
	{
		printf("Invalid number of arguments \n");
		return (1);
	}

	cmd_path = ft_check_cmd(argv[1], envp);

	// Check path variable
	if (!cmd_path)
	{
		printf("CMD DO NOT exists\n");
	} else {
		// execve(cmd_path, ft_split(argv[1], ' '), envp);
		printf("CMD Exists\n");
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