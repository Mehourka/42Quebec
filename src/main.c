#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int pid = fork();

	if(pid == 0)
	{
		// Child process
		execlp("ping", "ping", "-c", "1", "google.com", NULL);
	}
	else{
		// Parent proc
		wait(NULL);
		printf("\nSuccess!\n");
	}
	return (0);
}