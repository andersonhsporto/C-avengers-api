#include "headers.h"

t_mg_mgr	g_net;
t_flags		g_com;
t_mariadb	g_db;

int	main(void)
{
	init_server("3");
	start_listener();
	mg_mgr_free(&g_net);
	mysql_close(g_db.mysql);
	mysql_library_end();
	return (0);
}
