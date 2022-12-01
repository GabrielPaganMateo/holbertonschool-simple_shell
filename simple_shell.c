#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *Return: infinite loop to display prompt and read lines
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char *line = NULL, **tokens = NULL;
	size_t buflen = 0;
	int flag;

	while (1)
	{
		if (isatty(0))
		{
			write(1, "$ ", 2);
		}
		flag = getline(&line, &buflen, stdin);
		if (flag == EOF)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			write(1, "$ ", 2);
			continue;
		}
		tokens = split_input(line, " \n");
		execute(tokens, env);
		free(line);
	}
	return(0);
}
