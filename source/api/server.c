#include "headers.h"

void	init_server(char *debug_status)
{
	mg_log_set(debug_status);
	mg_mgr_init(&g_net);
	g_com.com_flag = 1;
	signal(SIGINT, abort_sig);
	init_json_struct();
	init_database();
}

void	start_listener(void)
{
	char	api_address[20];
	char	*port = getenv("PORT");

	sprintf(api_address, "http://0.0.0.0:%s", port);
	mg_http_listen(&g_net, api_address, handler, NULL);
	while (g_com.com_flag)
	{
		mg_mgr_poll(&g_net, 1000);
	}
	mg_mgr_free(&g_net);
}

void	abort_sig(int signum __attribute__((unused)))
{
	printf("\n[EXIT]\n");
	g_com.com_flag = 0;
}
