#include "monty.h"
/**
 *
 *
 * Return:
 */
int main(int argc, char **argv)
{
	int fd;
	char **array;


	if (argv[1] == NULL)
	{
		printf("error1\n");
	}
	else
	{
		fd = open(argv[1], O_PATH | O_RDONLY);
			if (fd == -1)
		printf("error2\n");
		array = tokenize(fd);
	}
	close(fd);
		/*for j = 0; array[j] != NULL; j += 2
	{
		call first part of array[j], with 2nd part of array[j] as arg
		"           push          ", "                 1            "
		f(array[j], array[j+1]);
	}
	*/
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
		printf("error3\n");
	count = read(fd, buffer, 32);

	write(STDOUT_FILENO, buffer, 32);

	array[0] = strtok(count, " \n");

	for (i = 1; array[i] != NULL; i++)
	{
		array[i] = strtok(NULL, "  \n");
	}

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
int(*get_op_code(stack_t **stack)(unsigned int line_number))
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
		if ((op_code[i] == **stack)  && (stack->n != '\0'))
			return (op_code[i].f);
		i++;
	}
	return (NULL);
}
