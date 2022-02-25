#include "api.h"

void	finish_with_error(void)
{
	fprintf(stderr, "%s\n", mysql_error(g_connection));
	mysql_close(g_connection);
	exit(404);
}

void	start_database_connection(void)
{
	g_connection = mysql_init(NULL);
	if (g_connection == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(g_connection));
		exit(404);
	}
	if (mysql_real_connect(g_connection, DB_HOST, DB_USER, DB_PASS,
		DB_NAME, DB_PORT, DB_SOCK, DB_FLAG) == NULL)
	{
		finish_with_error();
		exit(404);
	}
}

void	finish_database_connection(void)
{
	mysql_close(g_connection);
}
