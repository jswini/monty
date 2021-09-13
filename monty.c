#include "monty.h"
/**
 *
 *
 * Return:
 */
int main(int argc, char **argv)
{
	int fd, j, line;
	char **array;
	int (*op_result(unsigned int));


	if ((argv[1] == NULL) || (argc != 2))
	{
		usage_error(void);
	}
	else
	{
		fd = open(argv[1], O_PATH | O_RDONLY);
		if (fd == -1)
			open_file_error(char *filename);
		array = tokenize(fd);
	}
	close(fd);

	for (j = 0; array[j] != NULL; j += 2)
	{
		if (j % 2 == 0)
			line = ((j / 2) + 1);
		data_n = atoi(array[j + 1]);
		op_result = get_op_code(array[j], line);
	}

	return (0)
}

/**
 *
 *
 *
 */
char **tokenize(int fd)
{
	char **array;
	int i, count;
	char *buffer;

	buffer == malloc(sizeof(char) * 32);
	if (buffer == NULL)
		malloc_error(void);
	count = read(fd, buffer, 32);
/*for debug only*/
	write(STDOUT_FILENO, buffer, 32);
/*end debug*/

/*tokenize the array*/
	array[0] = strtok(count, " \n");

	for (i = 1; array[i] != NULL; i++)
	{
		array[i] = strtok(NULL, "  \n");
	}
/*prints array for debug*/
	for (i = 0; array[i] != NULL; i++)
	{
		printf("%s\n", array);
	}

	free(buffer);

	return (array);
}

/**
 *
 *
 *
 */
int (*get_op_code(char *s))(stack_t, unsigned int)
{
	instruction_t op_code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
		{NULL, NULL}
	};
	int i = 0;

	while (i < 7)
	{
		if ((op_code[i].opcode[0] == *s)  && (s[1] != '\0'))
			return (op_code[i].f);
		else
			unknown_op_error(op_code, line_number);
		i++;
	}
	return (NULL);
}
