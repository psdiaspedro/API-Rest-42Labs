#include "api.h"

void populate_table(struct mg_connection *c, struct mg_http_message *message)
{
	const char	*buf;
	char		nome[200];
	char		query[2000];
	double		id;
	double		fase;
	int			len;

	if (mjson_get_number(message->body.ptr, ft_strlen(message->body.ptr), "$.id", &id))
		printf("%g\n", id);
	if (mjson_find(message->body.ptr, ft_strlen(message->body.ptr), "$.nome", &buf, &len))
		sprintf(nome, "%.*s", len, buf);
	if (mjson_get_number(message->body.ptr, ft_strlen(message->body.ptr), "$.fase", &fase))
		printf("fase: %g\n", fase);
	sprintf(query, "INSERT INTO projects VALUES(%g,%s,%g)", id, nome, fase);
	printf("%s\n", query);
	if (mysql_query(g_connection, query))
	{
		mg_http_reply(c, 400, "", "%s\n", "{\"status\": \"400 BAD REQUEST\"}");
		add_log("POST", "/database", 400);
	}
	else
	{
		mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", "{\"status\": \"200 OK\"}");
		add_log("POST", "/database", 200);
	}
}
