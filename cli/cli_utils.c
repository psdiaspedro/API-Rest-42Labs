#include "cli.h"

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
