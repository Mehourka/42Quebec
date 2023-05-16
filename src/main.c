#include "pipex.h"

#include <stdio.h>

/*
Testing programm execution

Parsing :
	Take the command from argcv and verify it's valid ==> DONE
	Parse the double quotes \" inside a command == > TBD

Pre-process :
	Extract the PATH env variable  	==> DONE
	Check if command exists  		==> DONE
	Check if file access is ok		==> Ongoing


Execution :
	Replicate execpl() with execve 	==> DONE
	Write to oufile 				==> DONE
	Execution in parallel			==> DONE

Error handeling :
	correctly handle errors			==> TBD
 */

void check_args(int argc, char *argv[])
{
	if (argc < 4)
		ft_raise_err("Not enough arguments: ./pipex infile cmd1 cmd2 outfile", 2);

	// check input or output files
	if(access(argv[1], R_OK) == 0)
	{
		printf("%s, exists and is readable\n", argv[1]);
	} else {
		ft_raise_err("File access error", 73);
	}

	// TODO : check if outfile is writable
}

int main(int argc, char *argv[], char *const envp[])
{
	int fd[2];
	int output_fd;
	int i;

	// Check args and files
	check_args(argc, argv);
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
