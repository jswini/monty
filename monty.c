#include "monty.h"
int number;
/**
 *
 *
 * Return:
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

	/*void (*op_result)(stack_t **stack, unsigned int linenum);*/


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
			printf("line: %i\n", line);
			if (arraymain[j+1] != NULL)
				number = atoi(arraymain[j + 1]);
			printf("number = %i\n", number);
			get_op_code(arraymain[j])(&stack, line);
		}
	}
	fclose(whatever);
	free(buffer);
	return (0);
}

/**
 *
 *
 *
 */
char **tokenize(char *buffer)
{
	char **tokarray;
	char *token;
	int i;
	char delim[] = {' ', '\n'};


	tokarray = malloc(sizeof(char) * 1024);
/*for debug only*/
	write(STDOUT_FILENO, buffer, strlen(buffer));
/*end debug*/

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
 *
 *
 *
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
	printf("opcode: %s\n", s);
	while (i < 7)
	{
		if ((strcmp(op_code[i].opcode, s) == 0)  && (s != NULL))
			return (op_code[i].f);
		i++;
	}
	unknown_op_error(s);
	return (NULL);
}
