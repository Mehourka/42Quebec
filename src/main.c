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
	int fd[2];
	int output_fd;
	int i;

	i = 2;
	fd[0] = -1;
	// For each command
	while (i < argc - 1)
	{
		// Change the stdin
		output_fd = ft_dupio(argc, argv, i, fd);

		// In child process :
		if (set_fork() == 0){
			// Execute command
			exec_strcmd(argv[i], envp, 0, output_fd);
			return (1);
		}
		close(fd[1]);
		i++;
	}
	while (i-- >= 2)
		waitpid(-1, NULL, 0);
	return (0);
}
