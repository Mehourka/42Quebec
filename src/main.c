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
	if(pipe(fd) == -1){return 1;}

	int infile = open(argv[1], O_RDONLY, 0777);
	int outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	
	int pid1 = fork();
	if(pid1 == -1) {return 2;}

	

	if (pid1 == 0){
		// Child process 1 (ping)

		dup2(infile, STDIN_FILENO);
		close(infile);

		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);

		char **cmd_tab = ft_split(argv[2], ' ');
		char *cmd_path = ft_check_cmd(argv[2], envp);
		execve(cmd_path, cmd_tab, envp);
	}



	int pid2 = fork();
	if (pid2 < 0){return 3;}

	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);

		dup2(outfile, STDOUT_FILENO);
		close(outfile);

		char **cmd_tab = ft_split(argv[3], ' ');
		char *cmd_path = ft_check_cmd(argv[3], envp);
		execve(cmd_path, cmd_tab, envp);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(0, NULL, 0); // Watch out this one
	// waitpid(pid1, NULL, 0); // Watch out this one
	
	return (0);
}