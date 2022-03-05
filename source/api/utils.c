#include "headers.h"

int	find_url(struct mg_http_message *http_input)
{
	if (mg_http_match_uri(http_input, "/"))
		return(root);
	else if (mg_http_match_uri(http_input, "/id") || \
	mg_http_match_uri(http_input, "/favicon.ico*"))
		return(favicon);
	else if (mg_http_match_uri(http_input, "/id") || \
	mg_http_match_uri(http_input, "/id/*"))
		return(id);
	else if (mg_http_match_uri(http_input, "/alias") || \
	mg_http_match_uri(http_input, "/alias/*"))
		return(alias);
	return(FAILED);
}

int	get_method(struct mg_http_message *request)
{
	if (!mg_ncasecmp(request->method.ptr, "GET", request->method.len))
	{
		return (GET);
	}
	else if (!mg_ncasecmp(request->method.ptr, "DELETE", request->method.len))
	{
		return (DELETE);
	}
	return (FAILED);
}

void	replace_space(void)
{
	int	index;

	index = 0;
	while (g_com.tmp[index] != '\0')
	{
		if (g_com.tmp[index] == '+')
		{
			g_com.tmp[index] = ' ';
		}
		index++;
	}
	return ;
}

int	random_number(int min, int max)
{
	int	nbr;

	nbr = (rand() % (max - min + 1)) + min;
	return (nbr);
}

char *extract_between(const char *str, const char *p1, const char *p2)
{
	const char		*i1 = strstr(str, p1);
	const size_t	pl1 = strlen(p1);
	const char		*i2 = strstr(i1 + pl1, p2);
	const size_t	mlen = i2 - (i1 + pl1);
	char			*ret = malloc(mlen + 1);

	if (i1 != NULL)
	{
		if (p2 != NULL)
		{
			if (ret != NULL)
			{
				memcpy(ret, i1 + pl1, mlen);
				ret[mlen] = '\0';
				return (ret);
			}
		}
	}
	return (NULL);
}
