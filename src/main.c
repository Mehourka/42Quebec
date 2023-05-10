#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
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



/*
Checks if a command exists in path folders
Return:
	0 if it exists
	-1 if it does not
*/
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


//	
int main(int argc, char *argv[], char *const envp[])
{

	char *env_path;
	// Recuperer les arguments

	// Check number of arguments
	// if (argc != 5)
	// {
	// 	printf("Invalid number of arguments \n");
	// 	return (1);
	// }

	// Check path variable


	env_path = ft_getenvpath(envp);
	// ft_check_cmd("ls", env_path);

	if (ft_check_cmd("ls", env_path) == -1)
	{
		printf("CMD DO NOT exists\n");
	} else {
		printf("CMD Exists\n");
	}

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