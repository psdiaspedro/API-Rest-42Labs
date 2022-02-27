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
	}
	else
	{
		printf("sintaxe errada, tente: ./cli + UMA opção\n");
		printf("\n");
		printf("------------------------------------------------------------\n");
		printf("|                 OPÇÕES DISPONÍVEIS                       |\n");
		printf("------------------------------------------------------------\n");
		printf("lista: para gerar uma lista com todos os logs gerados\n");
		printf("tabela: para gerar uma tabela organizada dos logs gerados\n");
		printf("ultimo_request: para ter o último request feito\n");
	}
}
