#include "headers.h"

void	get_id(struct mg_http_message *http_input,
	struct mg_connection *connec)
{
	char		query[200];
	MYSQL_RES	*result;
	MYSQL_ROW	record;

	g_com.tmp = extract_between(http_input->method.ptr, "GET /id/"," HTTP/1.1");
	sprintf(query, "SELECT * FROM `avengers` WHERE id=%s", g_com.tmp);
	mysql_query(g_db.mysql, query);
	result = mysql_store_result(g_db.mysql);
	record = mysql_fetch_row(result);
	if (!record)
	{
		add_log("GET", "/id/", "404", http_input);
		mg_http_reply(connec, 404, "", "");
		free(g_com.tmp);
		return ;
	}
	add_log("GET", "/id/", "200", http_input);
	init_json(record);
	send_json(connec);
	mysql_free_result(result);
	free(g_com.tmp);
	return ;
}

void	delete_id(struct mg_http_message *http_input,
	struct mg_connection *connec)
{
	char		query[200];

	g_com.tmp = extract_between(http_input->method.ptr, "DELETE /id/"," HTTP/1.1");
	sprintf(query, "DELETE FROM `avengers` WHERE id='%s'", g_com.tmp);
	mysql_query(g_db.mysql, query);
	if (mysql_affected_rows(g_db.mysql) > 0)
	{
		add_log("DELETE", "/id/", "200", http_input);
		mg_http_reply(connec, 200, "", "Avenger blipped");
		free(g_com.tmp);
		return ;
	}
	add_log("DELETE", "/id/", "404", http_input);
	mg_http_reply(connec, 404, "", "id Not Found");
	free(g_com.tmp);
	return ;
}

void	get_random_id(struct mg_http_message *http_input,
	struct mg_connection *connec)
{
	char		query[200];
	MYSQL_RES	*result;
	MYSQL_ROW	record;

	g_com.tmp = ft_itoa(random_number(1, 98));
	sprintf(query, "SELECT * FROM `avengers` WHERE id=%s", g_com.tmp);
	mysql_query(g_db.mysql, query);
	result = mysql_store_result(g_db.mysql);
	record = mysql_fetch_row(result);
	if (!record)
	{
		add_log("GET", "/", "404", http_input);
		mg_http_reply(connec, 404, "", "");
		free(g_com.tmp);
		return ;
	}
	if (ft_strcmp(g_com.tmp, record[0]) == 0)
	{
		add_log("GET", "/", "200", http_input);
		init_json(record);
		send_json(connec);
	}
	free(g_com.tmp);
	mysql_free_result(result);
	return ;
}