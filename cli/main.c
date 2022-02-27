#include "cli.h"

int	main(int argc, char **argv)
{
	t_logs logs;

	get_report(&logs);
	if (argc == 2)
	{
		if (!strcmp(argv[1], "lista"))
		{
			char	*args[] = {"cat", "../api_project/logs.txt", NULL};
			execv("/bin/cat", args);
		}
		else if(!strcmp(argv[1], "tabela"))
			print_table(&logs);
		else if(!strcmp(argv[1], "ultimo_request"))
			print_last_request(&logs);
		else
		{
			printf("Opção invalida\n");
			printf("\n");
			print_options();
		}

	}
	else
	{
		wrong_syntax();
	}
}
