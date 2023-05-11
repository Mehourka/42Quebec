#include "libft.h"
#include "pipex.h"



int ft_check_cmd(char *cmd, char *const envp[])
{
	char **path_tab;
	char *tmp;
	int res;
	int i;

	i = 0;
	path_tab = ft_getenvpaths(envp);

	res = -1;
	// try out every path
	while(path_tab[i])
	{
		// tmp = ft_strjoin(path_tab[i], "/"); // LEAK HERE
		tmp = ft_strjoin_path(path_tab[i], cmd); // idea : Maybe check that te joind str is a valid folder (has '/')
		res = access(tmp, R_OK);
		free(tmp);
		if (res == 0)
			break;
		i++;
	}
	ft_free_tab(path_tab);
	return res;

}

/*
Extracts the PATH env variable as a string
*/ 
char **ft_getenvpaths(char *const envp[])
{
	char *env_paths;
	char **tab;

	env_paths = "";
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			env_paths = ft_strdup(*envp + 5);
		}
		envp++;
	}
	tab = ft_split(env_paths, ':');
	free(env_paths);
	return tab;
}

void ft_free_tab(char **tab)
{
	int i = 0;

	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strjoin_path(const char *str1, const char *str2)
{
	char	*new_string;
	size_t	len_str1;
	size_t	len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	new_string = malloc(len_str1 + len_str2 + 2);
	if (!new_string)
		return (NULL);
	new_string[len_str1 + len_str2 + 1] = '\0';
	ft_memcpy(new_string, (void *)str1, len_str1);
	ft_memcpy((new_string + len_str1), "/",1);
	ft_memcpy((new_string + len_str1 + 1), (void *)str2, len_str2);
	return (new_string);
}
