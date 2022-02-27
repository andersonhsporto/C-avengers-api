#ifndef LOGVI_H
# define LOGVI_H

# include "headers.h"
# include "struct.h"

# include	<readline/readline.h>
# include	<readline/history.h>

# define M_GET "Method: GET"
# define M_DEL "Method: DELETE"
# define PATH_R "Path: /"
# define PATH_I "Path: /id/"
# define PATH_A "Path: /alias/"

# define BOLDGREEN	"\033[1m\033[32m"
# define BOLDWHITE	"\033[1m\033[37m"
# define RESET		" $ \033[0m "
# define RESET_F	"\033[0m"
# define PROMPT		"\033[1m\033[32m[Logviwer] >> \033[0m "

# define FTLINE		"/* ************************************************************************** */"

# define LOGINFO	"Logviewer is a simple shell (with GNU readline capabilities) \n\
and shows log information about the avengers api\n \
\nLogviewer supports the following options:\n\n"

# define HELP		"Use the command `help` to provide information about the viewer"

typedef struct s_index {
	int	id;
	int	alias;
	int	root;
}	t_index;

typedef struct s_viwer {
	char		*input;
	t_index		get;
	t_index		delete;
	t_index		root;
}	t_viwer;

extern t_viwer	g_viewer;

// SIGNAL

void	abort_sig(int sig __attribute__((unused)));
void	get_sig(void);
void	exit_free(void);

// PRINTER

void	print_help(void);
void	print_get(void);
void	print_delete(void);
void	print_root(void);

// FILTER

void	check_log(void);
void	increment_log(char *line);
int		substr_inside(const char *line, const char *substr);
void	init_counter(void);

// PROMPT

void	start_prompt(void);
#endif