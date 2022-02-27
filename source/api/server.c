#include "headers.h"

// Set to 3 to enable debug
// Initialise event manager
void	init_server(char *debug_status)
{
	mg_log_set(debug_status);
	mg_mgr_init(&g_net);
	g_com.com_flag = 1;
	signal(SIGINT, abort_sig);
	init_json_struct();
	init_database();
}

// Create HTTP listener
// and infinite event loop
void	start_listener(void)
{
	mg_http_listen(&g_net, ADDRESS, handler, NULL);
	while (g_com.com_flag)
	{
		mg_mgr_poll(&g_net, 1000);
	}
	mg_mgr_free(&g_net);
}

// Handle SIGINT
// and exit event loop
void	abort_sig(int signum __attribute__((unused)))
{
	printf("\n[EXIT]\n");
	g_com.com_flag = 0;
}
