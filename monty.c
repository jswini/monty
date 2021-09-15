#include "monty.h"
int number;
/**
 * main - driver for monty interpreter
 * @argc: number of args
 * @argv: array of agrs
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	unsigned int line = 0;
	unsigned int j = 0;
	char **arraymain;
	size_t size;
	FILE *whatever;
	char *buffer = NULL;
	stack_t *stack = NULL;
	int n;

	if ((argv[1] == NULL) || (argc != 2))
	{
		usage_error();
	}
	else
	{
		whatever = fopen(argv[1], "r");
		if (whatever == NULL)
		{
			open_file_error(argv[1]);
		}
		while (getline(&buffer, &size, whatever) != -1)
		{
			arraymain = tokenize(buffer);
			line++;
			for (n = 0; (arraymain[j + 1]) && (arraymain[j + 1][n] != '\0'); n++)
			{
				if (arraymain[j + 1][n] == '-')
					n++;
				if ((arraymain[j + 1][n] < 48) || (arraymain[j + 1][n] > 57))
					no_int_error(line);
				number = atoi(arraymain[j + 1]);
			}
			get_op_code(arraymain[j])(&stack, line);
			free(arraymain);
		}
	}
	free_stuff(whatever, buffer, stack);
	return (0);
}


/**
 * tokenize - what it says on the label
 * @buffer: buffer from fread
 *
 * Return: tokenized array
 */
char **tokenize(char *buffer)
{
	char **tokarray;
	char *token;
	int i;
	char delim[] = {' ', '\n'};

	tokarray = malloc(sizeof(char) * 1024);
/*
*for debug only
*	write(STDOUT_FILENO, buffer, strlen(buffer));
*end debug
*/

	token = strtok(buffer, delim);
/*	printf("0: %s\n", token);*/
	tokarray[0] = token;
	for (i = 1; token != NULL; i++)
	{
		token = strtok(NULL, delim);
		tokarray[i] = token;
/*		printf("j+1 = %d: %s\n", i, token);*/
	}

	return (tokarray);
}

/**
 * get_op_code - gets the op code
 * @s: op_code passed
 *
 * Return: op code function
 */
void (*get_op_code(char *s))(stack_t **stack, unsigned int lineinfo)
{
	instruction_t op_code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;
/*	printf("opcode: %s\n", s);*/
	while (i < 7)
	{
		if ((strcmp(op_code[i].opcode, s) == 0)  && (s != NULL))
			return (op_code[i].f);
		i++;
	}
	unknown_op_error(s);
	return (NULL);
}

/**
 * free - frees all the things
 * @whatever: file to be freed
 * @buffer: buffer to be freed
 * @stack: linked list
 * @next: temp node to help free
 *
 * Return: void
 */
void free_stuff(FILE *whatever, char *buffer, stack_t *stack)
{
	stack_t *next;

	fclose(whatever);
	free(buffer);
	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
