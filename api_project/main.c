#include "api.h"

MYSQL *g_connection;

/**
 * @brief Função Handler da mongoose, onde podemos fazer o gerenciamento das requisições
 *
 * @param C Conexão do evento
 * @param ev Um numero de evento, definido em mongoose.h
 * @param ev_data Estrutura que guarda as informações da requisição
 * @param fn_data Armazena informações especificas do protocolo
 */
static void handler(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	if (ev == MG_EV_HTTP_MSG)
	{
		struct mg_http_message *message = (struct mg_http_message *) ev_data;
		get_path(message, c);
	}
}

int main(int argc, char *argv[])
{
	struct mg_mgr mgr;
	start_database_connection();								// Inicia o DB
	mg_mgr_init(&mgr);											// Inicia o gerenciador
	mg_http_listen(&mgr, "http://localhost:8000", handler, &mgr);	// Listener
	while (true)
		mg_mgr_poll(&mgr, 1000);								// Loop de eventos
	mg_mgr_free(&mgr);											// Fecha o gerenciador
	finish_database_connection();								// Fecha o DB
	return 0;
}

