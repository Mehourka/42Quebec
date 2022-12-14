#include<stdio.h>
#include <stdlib.h>

int check_sep(char *str, char *sep)
{
	int i;

	i = 0;
	while(str[i] && sep[i] && (str[i] == sep[i]))
		i++;
	if (!(sep[i]))
		return (i);
	return (0);
}

int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int count_chunks(char *str, char *sep)
{
	int chunks;
	int i;
	int sep_size;

	i = 0;
	chunks = 0;
	sep_size = check_sep(sep, sep);
	while (check_sep(&str[i], sep))
			i += sep_size;
	while (str[i])
	{
		while (str[i] && !check_sep(&str[i], sep))
			i++;
		while (check_sep(&str[i], sep))
			i += sep_size;
		chunks++;
	}
	return chunks;

}

char *ft_strnup(char *str, int n)
{
	char *dest;
	int i;

	dest = (char *) malloc(sizeof(char) * (n + 1));

	i = 0;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int chunk_size (char *str, char *sep)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (!check_sep(&str[i], sep))
	{
		size++;
		i++;
	}
	return (size);
}

char **ft_split(char *str, char *charset)
{
	char **words;
	int nb_chunks;
	int i;
	int j;
	int next_size;

	nb_chunks = count_chunks(str, charset);
	words == malloc(sizeof(char *) * (nb_chunks + 1));

	i = 0;
	j = 0;
	while (j < nb_chunks)
	{
		next_size = chunk_size(&str[i], charset);
		if (next_size )
		{
			words[j] = ft_strnup(&str[i], next_size);
			j++;
		}
		i += next_size + str_len(charset);
	}
	words[j] = 0;
	return words;

}


int main(void)
{
	char *sep = "--";
	int sep_size;
	int i;
	char **words;
	char *str = "Karim--a -- ----ekje";

	// // Count sep size
	// sep_size = 0;
	// while (sep[sep_size])
	// 	sep_size++;

	// //

	// printf("%i\n", count_chunks(str, sep));

	words = ft_split(str, sep);
	i = 0;
	while(words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}

}
