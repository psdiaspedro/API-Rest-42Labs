#include "api.h"

/**
 * @brief transforma a linha recebida do banco de dados em uma string com formato JSON
 *
 * @param buffer buffer com a string
 * @param i Qual coluna do banco de dados se encontra
 * @param row linha inteira tirada do banco de dados
 */
static char	*string_to_json(char *buffer, int i, char *row)
{
	char	*holder;

	holder = strdup("");
	if (i == 0)
		holder = ft_strjoin(strdup("\"id\": "), (row));
	if (i == 1)
		holder = ft_strjoin(strdup(", \"nome\": \""), (row));
	if (i == 2)
		holder = ft_strjoin(strdup(", \"fase\": "), (row));
	buffer = ft_strjoin(buffer, holder);
	if (i == 1)
		buffer = ft_strjoin(buffer, "\"");
	free(holder);
	return (buffer);
}

/**
 * @brief Consulta o banco de dados e retorna o JSON com todos os itens contidos
 *
 * @param C Conexão do evento
 */
void	show_database(struct mg_connection *c)
{
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		*buffer;
	int			num_fields;
	int			first;

	if (mysql_query(g_connection, "SELECT * FROM projects"))
		finish_with_error();
	result = mysql_store_result(g_connection);
	if (result == NULL)
		finish_with_error();
	num_fields = mysql_num_fields(result);
	buffer = strdup("[");
	while ((row = mysql_fetch_row(result)))
	{
		if (!first)
			buffer = ft_strjoin(buffer, ", ");
		buffer = ft_strjoin(buffer, "{");
		for (int i = 0; i < num_fields; i++)
			buffer = string_to_json(buffer, i, row[i]);
		first = 0;
		buffer = ft_strjoin(buffer, "}");
	}
	buffer = ft_strjoin(buffer, "]");
	mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", buffer);
	add_log("GET", "/database", 200);
	free(buffer);
	mysql_free_result(result);

}

/**
 * @brief Faz uma request para uma API externa, retorna o JSON e adiciona o log
 *
 * @param C Conexão do evento
 */
void	kanye_rest(struct mg_connection *c)
{
	char	*str;

	str = request();
	mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", str);
	add_log("GET", "/", 200);
}

/**
 * @brief Retorna um JSON com as informações do criador da API
 *
 * @param C Conexão do evento
 */
void	myself(struct mg_connection *c)
{
	char	*str;

	str = "{\"name\": \"Pedro Dias\", \"intra user\": \"paugusto\"}";
	mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", str);
	add_log("GET", "/me", 200);
}
