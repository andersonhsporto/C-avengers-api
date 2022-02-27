#include "headers.h"

void	check_log(void)
{
	int		fd;
	char	*line;

	fd = open("./log/log.log", O_RDONLY);
	init_counter();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		increment_log(line);
		free(line);
	}
	close(fd);
	return ;
}

void	init_counter(void)
{
	g_viewer.get.root = 0;
	g_viewer.get.id = 0;
	g_viewer.get.alias = 0;
	g_viewer.delete.id = 0;
	g_viewer.delete.alias = 0;
}

int	substr_inside(const char *line, const char *substr)
{
	char	*tmp;

	tmp = strstr(line, substr);
	if (tmp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	increment_log(char *line)
{
	if (substr_inside(line, M_GET) && substr_inside(line, PATH_I))
		g_viewer.get.id++;
	else if (substr_inside(line, M_GET) && substr_inside(line, PATH_A))
		g_viewer.get.alias++;
	else if (substr_inside(line, M_DEL) && substr_inside(line, PATH_I))
		g_viewer.delete.id++;
	else if (substr_inside(line, M_DEL) && substr_inside(line, PATH_A))
		g_viewer.delete.alias++;
	else if (substr_inside(line, M_GET) && substr_inside(line, PATH_R))
		g_viewer.get.root++;
}
