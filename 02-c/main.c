#include <stdio.h>
#include <unistd.h>

char *ft_strupcase(char *str) __attribute__((weak));
char *ft_strlowcase(char *str) __attribute__((weak));
char *ft_strcapitalize(char *str) __attribute__((weak));
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size) __attribute__((weak));



int main(void)
{
	// Exercice 7
	if (ft_strupcase)
	{
		char str[] = "Quebec 42";
		char *return_str;

		return_str = ft_strupcase(str);

		printf("%s\n", return_str);
	}

	// Exercice 8
	if (ft_strlowcase)
	{
		char str[] = "Quebec 42";
		char *return_str;

		return_str = ft_strlowcase(str);

		printf("%s\n", return_str);
	}


	// Exercice 9
	if (ft_strcapitalize)
	{
		char str[] = "queBEC 42";
		char *return_str;

		return_str = ft_strcapitalize(str);

		printf("%s\n", return_str);
	}

	//Exercice 10
	if (ft_strlcpy)
	{
		char *src = "Quebec 42";
		char stack_buffer[6];
		unsigned int length;

		length = ft_strlcpy(stack_buffer, src, sizeof(stack_buffer));
		printf("copy : %s\nLength : %i\n", stack_buffer, length);
	}
}
