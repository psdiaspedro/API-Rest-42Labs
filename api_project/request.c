#include "api.h"

/**
 * @brief Função para armazenar informações da requisição
 */
static size_t writecallback(char *contents, size_t size, size_t nmemb, void *userp)
{
	size_t			realsize;
	struct memory	*mem;
	char			*ptr;

	realsize = size * nmemb;
	mem = (struct memory *)userp;
	ptr = realloc(mem->memory, mem->size + realsize + 1);
	if (ptr == NULL)
		return (0);
	mem->memory = ptr;
	memcpy(&mem->memory[mem->size], contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	return (realsize);
}

/**
 * @brief Faz uma request para outra API
 */
char	*request(void)
{
	CURL *curl;
	CURLcode response;
	struct memory chunk;

	chunk.memory = NULL;
	chunk.size = 0;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.kanye.rest");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
		response = curl_easy_perform(curl);
		if (response != CURLE_OK)
			fprintf(stderr, "Resquest failed: %s\n", curl_easy_strerror(response));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return(chunk.memory);
}
