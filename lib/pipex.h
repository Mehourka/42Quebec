#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data
{
	int			*fd;
	int			infile;
	int			cmd_idx;
	int			in;
	int			out;
	int			argc;
	char		**argv;

}				t_data;

char	*ft_check_cmd(char *cmd, char *const envp[]);
char	**ft_getenvpaths(char *const envp[]);
void	ft_free_tab(char **tab);
char	*ft_strjoin_path(const char *str1, const char *str2);
char	*ft_getfwd(char *str);
int		ft_iswhitsp(char c);
void ft_dup_stdout(int argc, char *argv[]);
int exec_strcmd(char *cmd, char *const envp[]);
void ft_raise_err(char *err_str, int err_nb);
void set_pipe(int *fd);
int set_fork(void);
void ft_setio(t_data *data);
t_data init_data(int argc, char *argv[]);

#endif