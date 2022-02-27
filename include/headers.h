#ifndef HEADERS_H
# define HEADERS_H

# include <mysql/mysql.h>

# include "../source/libs/mongoose.h"
# include "../source/libs/mJson.h"

# include "../source/libs/libft/libft.h"

# include "struct.h"
# include "logvi.h"

# define ADDRESS "http://0.0.0.0:4242"

# define PORT_DB 3306
# define USER "stark"
# define PASS "123"
# define HOST "localhost"
# define DB "api_vingadores"

# define STRUCT "CREATE TABLE `avengers` (id INT PRIMARY KEY AUTO_INCREMENT, \
`URL` VARCHAR(255), `NAME` VARCHAR(255), `ALIAS` VARCHAR(255), \
`BR` VARCHAR(255), `Appearances` INT(8), `Current` VARCHAR(255), \
`Gender` VARCHAR(255), `Probationary Introl` VARCHAR(255), \
`Full/Reserve Avengers Intro` VARCHAR(255), `Year` INT(101), \
`Years since joining` INT(3), `Honorary` VARCHAR(255), `Death1` VARCHAR(5), \
`Return1` VARCHAR(5),  `Death2` VARCHAR(5), `Return2` VARCHAR(5), \
`Notes` VARCHAR(255))"

# define TABLE "CREATE TABLE `avengers` (id INT PRIMARY KEY AUTO_INCREMENT, `Name` VARCHAR(255))"
# define S_TABLE "INSERT INTO `avengers` VALUES('"
# define F_TABLE "',"

# define TYPE "content-type: application/json; charset=utf-8\r\n"

// SERVER

void	init_server(char *debug_status);
void	start_listener(void);
void	abort_sig(int signum __attribute__((unused)));

// MARIADB

void	finish_with_error(MYSQL *con);
void	init_database(void);
void	populate_db(void);

// GET CSV

void	get_csv(void);
char	*get_csv_line(char *line, int id);
void	free_matrix(char **matrix);
void	join_in_matrix(char **line, char *c);

// ROUTES

void	handler(struct mg_connection *connec, int ev,
			void *ev_data __attribute__((unused)), void *fn_data);
void	get_routes(struct mg_http_message *http_input,
			struct mg_connection *connec);

// GET ID

void	get_id(struct mg_http_message *http_input,
			struct mg_connection *connec);
void	delete_id(struct mg_http_message *http_input,
			struct mg_connection *connec);
void	get_random_id(struct mg_http_message *http_input,
			struct mg_connection *connec);

// GET_ALIAS

void	get_alias(struct mg_http_message *http_input,
			struct mg_connection *connec);
void	delete_alias(struct mg_http_message *http_input,
			struct mg_connection *connec);

// JSON

int		get_json_len(MYSQL_ROW record);
void	init_json(MYSQL_ROW record);
void	init_json_struct(void);
void	send_json(struct mg_connection *connec);

// LOG

void	add_log(char *method, char *path, char *status,
			struct mg_http_message *http);

// UTILS

int		find_url(struct mg_http_message *http_input);
int		get_method(struct mg_http_message *request);
void	replace_space(void);
int		random_number(int min, int max);
char	*extract_between(const char *str, const char *p1, const char *p2);
#endif