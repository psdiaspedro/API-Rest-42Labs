#include "api.h"

void	add_log(char *method, char *path, int status)
{
	time_t now;
	FILE *log;

	log = fopen("./logs.txt", "a");
	time(&now);
	if (log != NULL)
	{
		fprintf(log, "Method: %s\n", method);
		fprintf(log, "Request Time: %s", ctime(&now));
		fprintf(log, "Path: %s\n", path);
		fprintf(log, "Status: %d\n", status);
		fprintf(log, "\n");
		fclose(log);
	}
}

void	get_path(struct mg_http_message *message, struct mg_connection *c)
{
	if (mg_http_match_uri(message, "/") && message->method.ptr[0] == 'G')
		kanye_rest(c);
	else if (mg_http_match_uri(message, "/me") && message->method.ptr[0] == 'G')
		myself(c);
	else if (mg_http_match_uri(message, "/database") && message->method.ptr[0] == 'G')
		show_database(c);
	else if (mg_http_match_uri(message, "/database") && message->method.ptr[0] == 'P')
		populate_table(c, message);
	else if (mg_http_match_uri(message, "/database") && message->method.ptr[0] == 'D')
		delete_data(c, message);
	else
		mg_http_reply(c, 404, "", "{\"status\":\"%d\"}", 404);
}
