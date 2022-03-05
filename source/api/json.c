#include "headers.h"

int	get_json_len(MYSQL_ROW record)
{
	int		index;
	size_t	len;

	index = 0;
	len = 0;
	while (index < 17)
	{
		len = len + strlen(record[index]);
		index++;
	}
	return ((int)len);
}

void	init_json(MYSQL_ROW record)
{
	g_com.json_struc.id = record[0];
	g_com.json_struc.url = record[1];
	g_com.json_struc.name = record[2];
	g_com.json_struc.alias = record[3];
	g_com.json_struc.alias_br = record[4];
	g_com.json_struc.appearances = record[5];
	g_com.json_struc.current = record[6];
	g_com.json_struc.gender = record[7];
	g_com.json_struc.probationary = record[8];
	g_com.json_struc.full = record[9];
	g_com.json_struc.year = atoi(record[10]);
	g_com.json_struc.year_since = atoi(record[11]);
	g_com.json_struc.honorary = record[12];
	g_com.json_struc.death_one = record[13];
	g_com.json_struc.return_one = record[14];
	g_com.json_struc.death_two = record[15];
	g_com.json_struc.return_two = record[16];
	g_com.json_struc.note = record[17];
	g_com.json_struc.len = get_json_len(record);
}

void	init_json_struct(void)
{
	g_com.json_struc.id = NULL;
	g_com.json_struc.url = NULL;
	g_com.json_struc.name = NULL;
	g_com.json_struc.alias = NULL;
	g_com.json_struc.alias_br = NULL;
	g_com.json_struc.appearances = NULL;
	g_com.json_struc.current = NULL;
	g_com.json_struc.gender = NULL;
	g_com.json_struc.probationary = NULL;
	g_com.json_struc.full = NULL;
	g_com.json_struc.year = 0;
	g_com.json_struc.year_since = 0;
	g_com.json_struc.honorary = NULL;
	g_com.json_struc.death_one = NULL;
	g_com.json_struc.return_one = NULL;
	g_com.json_struc.death_two = NULL;
	g_com.json_struc.return_two = NULL;
	g_com.json_struc.note = NULL;
	g_com.json_struc.len = 0;
}

void	send_json(struct mg_connection *connec)
{
	char	*json_buff;

	json_buff = (char *)calloc(sizeof(char *), g_com.json_struc.len);
	mjson_snprintf(json_buff,
			g_com.json_struc.len + 500,
			"{%Q: %d, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %d, %Q: %d, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s, %Q: %s}",
			"id", atoi(g_com.json_struc.id),
			"URL", g_com.json_struc.url,
			"Name", g_com.json_struc.name,
			"Alias", g_com.json_struc.alias,
			"Alias-br", g_com.json_struc.alias_br,
			"Appearances", g_com.json_struc.appearances,
			"Current", g_com.json_struc.current,
			"Gender", g_com.json_struc.gender,
			"Probationary", g_com.json_struc.probationary,
			"Full/Reserve Avengers Intro", g_com.json_struc.full,
			"Year", g_com.json_struc.year,
			"Year since joining", g_com.json_struc.year_since,
			"Honorary", g_com.json_struc.honorary,
			"Death 1", g_com.json_struc.death_one,
			"Return 1", g_com.json_struc.return_one,
			"Death 2", g_com.json_struc.death_two,
			"Return 2", g_com.json_struc.return_two,
			"Notes", g_com.json_struc.note
			);
	mg_http_reply(connec, 200, TYPE, json_buff);
	free(json_buff);
}
