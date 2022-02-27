#include "cli.h"

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
