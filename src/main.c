/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:53 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/19 12:14:06 by kmehour          ###   ########.fr       */
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


/*
	Cheks number of arguments 
	and input/output access rights 
*/



int	main(int argc, char *argv[], char *const envp[])
{
	t_data	data;
	int pid[128];
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
	{
		waitpid(pid[i++], &wstat, 0);
		if(WIFEXITED(wstat))
		{
			if(WEXITSTATUS(wstat))
				ft_raise_err("", WEXITSTATUS(wstat));
		}
	}
		
	// char *cmd = argv[3];
	// char *cmd_path;
	// char **cmd_tab;
	// int i;

	// i = 0;
	// while(cmd[i])
	// {
	// 	if (cmd[i] == ' ')
	// 		cmd[i] = '\t';
	// 	if (cmd[i] == '"' || cmd[i] == '\'')
	// 	{
	// 		char *next_quote = ft_strchr(&cmd[i + 1], cmd[i]);
	// 		if (next_quote)
	// 		{
	// 			cmd[i] = '\t';
	// 			*next_quote = '\t';
	// 			i += next_quote - &cmd[i];
	// 		}
	// 	}	
	// 	i++;
	// }
	// cmd_tab = ft_split(cmd, '\t');
	// printf("Printing command args %s \n", cmd);
	// i = 0;
	// while(cmd_tab[i])
	// 	printf("arg : %s\n", cmd_tab[i++]);

	// cmd_path = ft_check_cmd(cmd, envp);
	// printf("Cmd path : %s\n", cmd_path);
	// // if (cmd_path)
	// 	// execve(cmd_path, cmd_tab, envp);
	// execve()
}
