#include "api.h"

void delete_data(struct mg_connection *c, struct mg_http_message *message)
{
	const char	*buf;
	char		query[2000];
	double		id;

	if (mjson_get_number(message->body.ptr, ft_strlen(message->body.ptr), "$.id", &id))
	sprintf(query, "DELETE FROM cars WHERE id=%g", id);
	if (mysql_query(g_connection, query))
	{
		mg_http_reply(c, 400, "", "%s\n", "{\"status\": \"400 BAD REQUEST\"}");
		add_log("DELETE", "/database", 400);
		printf("%s\n", query);
	}
	else
	{
		mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", "{\"status\": \"200 OK\"}");
		add_log("DELETE", "/database", 200);
	}
}
