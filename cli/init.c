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
