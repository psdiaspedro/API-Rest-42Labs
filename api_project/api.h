#ifndef API_H
#define API_H

#include "mongoose.h"
#include "mjson.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>
#include <mysql/mysql.h>

#define DB_HOST "localhost"
#define DB_USER "paugusto"
#define DB_PASS "Miojofrito01."
#define DB_NAME "api"
#define DB_PORT 3306
#define DB_SOCK NULL
#define DB_FLAG 0

extern MYSQL *g_connection;

struct memory
{
	char	*memory;
	size_t	size;
};

char	*request_advice(void);
void	finish_with_error(void);
void	start_database_connection(void);
void	finish_database_connection(void);

//libft functions
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

//get method
void	kanye_rest(struct mg_connection *c);
void	show_database(struct mg_connection *c);
void	myself(struct mg_connection *c);

//post functions
void	populate_table(struct mg_connection *c, struct mg_http_message *message);

//delete functions
void	delete_data(struct mg_connection *c, struct mg_http_message *message);

//api utils
void	add_log(char *method, char *path, int status);
void	get_path(struct mg_http_message *message, struct mg_connection *c);

#endif
