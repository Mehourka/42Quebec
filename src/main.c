/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:53 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/18 18:01:43 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	check_args(int argc, char *argv[])
{
	if (argc < 5)
		ft_raise_err("Not enough arguments\nUsage : ./pipex infile cmd1 cmd2 outfile",
				2);
	// check input or output files
	if (access(argv[1], R_OK) != 0)
	{
		ft_raise_err("File access error", 12);
	}
	

}

int	main(int argc, char *argv[], char *const envp[])
{
	t_data	data;
	int pid[100];
	int		cmd_i;

	data =init_data(argc, argv);
	check_args(argc, argv);
	cmd_i = 2;
	while (cmd_i < argc - 1)
	{
		ft_setio(&data);
		pid[cmd_i - 2] = set_fork();
		if (pid[cmd_i - 2] == 0)
		{
			dup2(data.out, STDOUT_FILENO);
			close(data.out);
			dup2(data.in, STDIN_FILENO);
			close(data.in);
			close(data.fd[0]);
			close(data.fd[1]);
			exec_strcmd(argv[cmd_i], envp);
			perror(NULL);
			return (1);
		}
		close(data.out);
		close(data.in);
		data.cmd_idx++;
		cmd_i++;
	}
	int wstat;
	int i = 0;
	while(i <= cmd_i -3)
		waitpid(pid[i++], &wstat, 0);
	return (0);
}
