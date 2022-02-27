#include "headers.h"

void	handler(struct mg_connection *connec, int ev,
			void *ev_data, void *fn_data  __attribute__((unused)))
{
	struct mg_http_message	*http_input;

	http_input = (struct mg_http_message *)ev_data;
	if (ev == MG_EV_HTTP_MSG)
	{
		get_routes(http_input, connec);
	}
}

void	get_routes(struct mg_http_message *http_input,
			struct mg_connection *connec)
{
	int	url;
	int	method;

	url = find_url(http_input);
	method = get_method(http_input);
	if (url == id && method == GET)
		get_id(http_input, connec);
	else if (url == alias && method == GET)
		get_alias(http_input, connec);
	else if (url == id && method == DELETE)
		delete_id(http_input, connec);
	else if (url == alias && method == DELETE)
		delete_alias(http_input, connec);
	else if (url == root && method == GET)
		get_random_id(http_input, connec);
	else
		mg_http_reply(connec, 404, "", "");
	return ;
}
