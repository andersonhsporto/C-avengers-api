#include "headers.h"

t_viwer	g_viewer;

int	main(void)
{
	check_log();
	printf("    %sLogviwer%s        \n%s\n", BOLDWHITE, RESET_F, HELP);
	while (true)
	{
		start_prompt();
		get_sig();
	}
	return (0);
}
