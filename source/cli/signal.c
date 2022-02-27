#include "headers.h"

void	abort_sig(int sig __attribute__((unused)))
{
	exit_free();
}

void	get_sig(void)
{
	signal(SIGINT, abort_sig);
	signal(SIGQUIT, SIG_IGN);
}

void	exit_free(void)
{
	free(g_viewer.input);
	exit (0);
}
