#include "cli.h"

void	print_last_request(t_logs *logs)
{
	printf("**** ULTIMO LOG ****\n");
	printf("\n");
	printf("%s", logs->last_request_method);
	printf("%s", logs->last_request_time);
	printf("%s", logs->last_request_path);
	printf("%s", logs->last_request_status);
}

void	print_table(t_logs *logs)
{
	printf("----------------------------------------------------\n");
	printf("|   total requests  |   HTTP Method   |     Path   |\n");
	printf("----------------------------------------------------\n");
	printf("|        %d          |       GET       |      /     |\n", logs->get_root);
	printf("----------------------------------------------------\n");
	printf("|        %d          |       GET       |     /me    |\n", logs->get_me);
	printf("----------------------------------------------------\n");
	printf("|        %d          |       GET       |  /database |\n", logs->get_db);
	printf("----------------------------------------------------\n");
	printf("|        %d         |      POST       |  /database |\n", logs->post);
	printf("----------------------------------------------------\n");
	printf("|        %d          |     DELETE      |  /database |\n", logs->del);
	printf("----------------------------------------------------\n");
}
