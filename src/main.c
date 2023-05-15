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

int main(int argc, char *argv[], char *const envp[])
{
	


	// Check number of arguments
	if (argc != 5)
	{
		printf("Invalid number of arguments \n");
		return (1);
	}

	// ft_dup_stdout(argc, argv);
	exec_strcmd(argv[2], envp, STDIN_FILENO, STDOUT_FILENO);

}