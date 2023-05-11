#ifndef PIPEX_H
# define PIPEX_H

char	*ft_check_cmd(char *cmd, char *const envp[]);
char	**ft_getenvpaths(char *const envp[]);
void	ft_free_tab(char **tab);
char	*ft_strjoin_path(const char *str1, const char *str2);
char	*ft_getfwd(char *str);
int		ft_iswhitsp(char c);
#endif