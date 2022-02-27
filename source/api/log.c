#include "headers.h"

void	add_log(char *method, char *path, char *status,
	struct mg_http_message *http)
{
	struct tm	tm = *localtime(&(time_t){time(NULL)});
    FILE		*log_file = fopen("./log/log.log", "a");
	char		*temp;

	temp = strtok(asctime(&tm), "\n");
	fprintf(log_file, "[%s] Method: %s ", temp, method);
	fprintf(log_file, "Path: %s ", path);
	temp = extract_between(http->method.ptr, "User-Agent:","\nAccept");
	fprintf(log_file, "Status: %s\n", status);
	free(temp);
	fclose(log_file);
}
