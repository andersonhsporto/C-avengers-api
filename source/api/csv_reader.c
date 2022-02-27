#include "headers.h"

void	get_csv(void)
{
	int		fd;
	int		id;
	char	*line;
	char	*tmp;

	fd = open("./utils/vingadores.csv", O_RDONLY);
	id = 1;
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strchr(line, '.'))
		{
			tmp = get_csv_line(line, id);
			if (mysql_query(g_db.mysql, tmp))
			{
				finish_with_error(g_db.mysql);
			}
			free(tmp);
			id++;
		}
		free(line);
	}
	close(fd);
}

char	*get_csv_line(char *line, int id)
{
	char	**split;
	char	*string;
	char	*tmp;
	char	*nbr;
	int		i;

	split = ft_split(line, ',');
	join_in_matrix(split, "'");
	tmp = strdup(F_TABLE);
	nbr = ft_itoa(id);
	i = 0;
	while (i < 18)
	{
		if (i == 16)
		{
			string = ft_strtjoin(tmp, split[i], ")");
			free(tmp);
			break ;
		}
		string = ft_strtjoin(tmp, split[i], ", ");
		free(tmp);
		tmp = strdup(string);
		free(string);
		i++;
	}
	free_matrix(split);
	tmp = ft_strtjoin(S_TABLE, nbr, string);
	free(nbr);
	free(string);
	return (tmp);
}

void	free_matrix(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index])
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

void	join_in_matrix(char **line, char *c)
{
	char	*tmp;
	int		index;

	index = 0;
	while (line[index] != 0)
	{
		if (ft_strcmp(line[index], "null"))
		{
			tmp = strdup(line[index]);
			free(line[index]);
			line[index] = NULL;
			line[index] = ft_strtjoin(c, tmp, c);
			free(tmp);
			tmp = NULL;
		}
		index++;
	}
	return ;
}
