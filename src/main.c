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
		// printf("%s, exists and is readable\n", argv[1]);
	} else {
		ft_raise_err("File access error", 73);
	}

	// TODO : check if outfile is writable
}

int main(int argc, char *argv[], char *const envp[])
{
	int fd[2];
	t_data data;
	int cmd_i;

	data.argc = argc;
	data.argv = argv;
	data.fd = fd;
	data.in = 0;
	data.out = 0;
	// data.infile = open(argv[1], O_RDONLY, 0700);
	data.cmd_idx = 2;

	// Check args and files
	check_args(argc, argv);
	cmd_i = 2;
	// For each command
	while (cmd_i < argc - 1)
	{
		// Change the stdin
		ft_setio(&data);
		// In child process :
		if (set_fork() == 0){
			// Execute command
			dup2(data.in, STDIN_FILENO);
			dup2(data.out, STDOUT_FILENO);
			close(data.in);
			close(data.out);
			exec_strcmd(argv[cmd_i], envp);
			return (1);
		}
		close(data.in);
		close(data.out);
		data.cmd_idx++;
		cmd_i++;
	}
	while (cmd_i-- >= 2)
		waitpid(-1, NULL, 0);
	return (0);
}
