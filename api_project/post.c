#include "api.h"

void populate_table(struct mg_connection *c, struct mg_http_message *message)
{
	const char	*buf;
	char		name[200];
	char		query[2000];
	double		id;
	double		price;
	int			len;

	if (mjson_get_number(message->body.ptr, ft_strlen(message->body.ptr), "$.id", &id))
	if (mjson_find(message->body.ptr, ft_strlen(message->body.ptr), "$.name", &buf, &len))
		sprintf(name, "%.*s", len, buf);
	if (mjson_get_number(message->body.ptr, ft_strlen(message->body.ptr), "$.price", &price))
		printf("price: %g\n", price);
	sprintf(query, "INSERT INTO cars VALUES(%g,%s,%g)", id, name, price);
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
