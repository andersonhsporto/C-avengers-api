#include "headers.h"

void	start_prompt(void)
{
	g_viewer.input = readline(PROMPT);
	add_history(g_viewer.input);
	if (!ft_strcmp("exit", g_viewer.input))
		exit_free();
	else if (!ft_strcmp("help", g_viewer.input) || !ft_strcmp("HELP", g_viewer.input))
		print_help();
	else if (!ft_strcmp("GET", g_viewer.input) || !ft_strcmp("get", g_viewer.input))
		print_get();
	else if (!ft_strcmp("DELETE", g_viewer.input) || !ft_strcmp("delete", g_viewer.input))
		print_delete();
	else if (!ft_strcmp("root", g_viewer.input) || !ft_strcmp("ROOT", g_viewer.input))
		print_root();
	else if (!ft_strcmp("clear", g_viewer.input) || !ft_strcmp("clean", g_viewer.input))
		system("clear");
	else
	{
		printf("%sError: Command <%s> not found.%s \n", BOLDWHITE, g_viewer.input, RESET_F);
		printf("Use the command `help` to provide information about the viewer\n");
	}
	return ;
}