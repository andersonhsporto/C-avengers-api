#include "headers.h"

void	get_alias(struct mg_http_message *http_input,
	struct mg_connection *connec)
{
	char		query[200];
	MYSQL_RES	*result;
	MYSQL_ROW	record;

	g_com.tmp = extract_between(http_input->method.ptr, "GET /alias/"," HTTP/1.1");
	replace_space();
	sprintf(query, "SELECT * FROM `avengers` WHERE ALIAS = '%s'", g_com.tmp);
	mysql_query(g_db.mysql, query);
	result = mysql_store_result(g_db.mysql);
	record = mysql_fetch_row(result);
	if (!record)
	{
		add_log("GET", "/alias/", "404", http_input);
		mg_http_reply(connec, 404, "", "ERRO");
		free(g_com.tmp);
		return ;
	}
	add_log("GET", "/alias/", "200", http_input);
	init_json(record);
	send_json(connec);
	mysql_free_result(result);
	free(g_com.tmp);
	return ;
}

void	delete_alias(struct mg_http_message *http_input,
	struct mg_connection *connec)
{
	char		query[200];

	g_com.tmp = extract_between(http_input->method.ptr, "DELETE /alias/"," HTTP/1.1");
	replace_space();
	sprintf(query, "DELETE FROM `avengers` WHERE ALIAS = '%s'", g_com.tmp);
	mysql_query(g_db.mysql, query);
	if (mysql_affected_rows(g_db.mysql) > 0)
	{
		add_log("DELETE", "/alias/", "200", http_input);
		mg_http_reply(connec, 200, "", "Avenger blipped");
		free(g_com.tmp);
		return ;
	}
	add_log("DELETE", "/alias/", "404", http_input);
	mg_http_reply(connec, 404, "", "Alias Not Found");
	free(g_com.tmp);
	return ;
}