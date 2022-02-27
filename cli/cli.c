#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "list"))
		{
			char	*args[] = {"cat", "logs.txt", NULL};
			execv("/bin/cat", args);
		}
		else if(!strcmp(argv[1], "report"))
			;
	}
	else
		printf("wrong syntax, please -> ./cli + option");
