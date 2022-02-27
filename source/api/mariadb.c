#include "headers.h"

void	finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit (1);
}

void	init_database(void)
{
	g_db.mysql = mysql_init(NULL);
	g_db.host = HOST;
	g_db.user = USER;
	g_db.passwd = PASS;
	g_db.db = DB;
	g_db.port = PORT_DB;

	if ((mysql_real_connect(g_db.mysql,
							g_db.host,
							g_db.user,
							g_db.passwd,
							g_db.db,
							g_db.port,
							NULL,
							no_client_flag)) == NULL)
	{
		fprintf(stderr,
				"Failed to connect to database: Error: %s\n",
				mysql_error(g_db.mysql));
		mysql_close(g_db.mysql);
		exit(EXIT_FAILURE);
	}
	populate_db();
}

void	populate_db(void)
{
	if (mysql_query(g_db.mysql, "DROP TABLE IF EXISTS avengers"))
	{
		finish_with_error(g_db.mysql);
	}
	if (mysql_query(g_db.mysql, STRUCT))
	{
		finish_with_error(g_db.mysql);
	}
	get_csv();
}
