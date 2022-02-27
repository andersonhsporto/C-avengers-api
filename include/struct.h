#ifndef STRUCT_H
# define STRUCT_H

# include "headers.h"

typedef struct s_mariadb {
	MYSQL			*mysql;
	char			*host;
	char			*user;
	char			*passwd;
	char			*db;
	unsigned int	port;
}	t_mariadb;

typedef struct s_json
{
	char	*id;
	char	*url;
	char	*name;
	char	*alias;
	char	*alias_br;
	char	*appearances;
	char	*current;
	char	*gender;
	char	*probationary;
	char	*full;
	int		year;
	int		year_since;
	char	*honorary;
	char	*death_one;
	char	*return_one;
	char	*death_two;
	char	*return_two;
	char	*note;
	int		len;
}	t_json;

typedef struct s_log {
	int		fd;
	char	*log_string;
}	t_log;
typedef struct s_flags {
	int		com_flag;
	char	*tmp;
	t_json	json_struc;
	t_log	log_data;

}	t_flags;

enum e_methods
{
	GET,
	DELETE,
	FAILED,
	ROGERS,
	NO_ROGERS
};

enum e_url
{
	root,
	id,
	alias,
	no_client_flag = 0
};

extern t_flags		g_com;
extern t_mg_mgr		g_net;
extern t_mariadb	g_db;

#endif