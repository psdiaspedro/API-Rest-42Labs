#include "cli.h"

void	init(t_logs *logs)
{
	logs->is_get = 0;
	logs->is_post = 0;
	logs->is_delete = 0;
	logs->get_root = 0;
	logs->get_me = 0;
	logs->get_db = 0;
	logs->post = 0;
	logs->del = 0;
	logs->last_request_time = strdup("");
	logs->last_request_method = strdup("");
	logs->last_request_path = strdup("");
	logs->last_request_status = strdup("");
}

void	check_method(t_logs *logs, char *line)
{
	if (!strncmp(line, "Method: GET", 11))
	{
		logs->is_get = 1;
		free(logs->last_request_method);
		logs->last_request_method = strdup(line);
	}
	if (!strncmp(line, "Method: POST", 12))
	{
		logs->is_post = 1;
		free(logs->last_request_method);
		logs->last_request_method = strdup(line);
	}
	if (!strncmp(line, "Method: DELETE", 14))
	{
		logs->is_delete  = 1;
		free(logs->last_request_method);
		logs->last_request_method = strdup(line);
	}
}

void	check_path(t_logs *logs, char *line)
{
	if (!strncmp(line, "Path: /database", 15) && logs->is_get == 1)
	{
		logs->is_get = 0;
		logs->get_db++;
	}
	else if (!strncmp(line, "Path: /database", 15) && logs->is_post == 1)
	{
		logs->is_post = 0;
		logs->post++;
	}
	else if (!strncmp(line, "Path: /database", 15) && logs->is_delete  == 1)
	{
		logs->is_delete  = 0;
		logs->del++;
	}
	else if (!strncmp(line, "Path: /me", 9) && logs->is_get == 1)
	{
		logs->is_get = 0;
		logs->get_me++;
	}
	else if (!strncmp(line, "Path: /", 7) && logs->is_get == 1)
	{
		logs->is_get = 0;
		logs->get_root++;
	}
}

void	last_request_path(t_logs *logs, char *line)
{
	if (!strncmp(line, "Path: /database", 15))
	{
		free(logs->last_request_path);
		logs->last_request_path = strdup(line);
	}
	else if (!strncmp(line, "Path: /me", 9))
	{
		free(logs->last_request_path);
		logs->last_request_path = strdup(line);
	}
	else if (!strncmp(line, "Path: /", 7))
	{
		free(logs->last_request_path);
		logs->last_request_path = strdup(line);
	}
}

void	last_request_time(t_logs *logs, char *line)
{
	if (!strncmp(line, "Request Time:", 13))
	{
		logs->is_delete  = 1;
		free(logs->last_request_time);
		logs->last_request_time = strdup(line);
	}
}

void	last_request_status(t_logs *logs, char *line)
{
	if (!strncmp(line, "Status:", 7))
	{
		free(logs->last_request_status);
		logs->last_request_status = strdup(line);
	}
}

void	get_report(t_logs *logs)
{
	int		fd;
	char	*line;

	init(logs);
	fd = open("../api_project/logs.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		check_method(logs, line);
		check_path(logs, line);
		last_request_path(logs, line);
		last_request_time(logs, line);
		last_request_status(logs, line);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_method(logs, line);
			check_path(logs, line);
			last_request_path(logs, line);
			last_request_time(logs, line);
			last_request_status(logs, line);
		}
	}

}

void	print_last_request(t_logs *logs)
{
	printf("**** LAST REQUEST ****\n");
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



int	main(int argc, char **argv)
{
	t_logs logs;

	get_report(&logs);
	if (argc == 2)
	{
		if (!strcmp(argv[1], "list"))
		{
			char	*args[] = {"cat", "../api_project/logs.txt", NULL};
			execv("/bin/cat", args);
		}
		else if(!strcmp(argv[1], "table"))
			print_table(&logs);
		else if(!strcmp(argv[1], "last_request"))
			print_last_request(&logs);
	}
	else
		printf("wrong syntax, please -> ./cli + option");
}
