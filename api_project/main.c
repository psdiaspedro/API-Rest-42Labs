#include "api.h"

MYSQL *g_connection;

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	char *s;
	char	*str;
	// const char *buf;
	// int len;

	if (ev == MG_EV_HTTP_MSG)
	{
		struct mg_http_message *message = (struct mg_http_message *) ev_data;
		get_path(message, c);
	}
}

int main(int argc, char *argv[])
{
  struct mg_mgr mgr;
  start_database_connection();								// init DB
  mg_mgr_init(&mgr);										// Init manager
  mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);	// Setup listener
  for (;;) mg_mgr_poll(&mgr, 1000);							// Event loop
  mg_mgr_free(&mgr);										// Cleanup
  finish_database_connection();								// close DB
  return 0;
}

