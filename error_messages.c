#include "monty.h"



/**
 * usage_error - prints usage errors
 *
 * Return: (EXIT_FAILURE)
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * unknown_op_error - prints unknown instruction errors
 * @opcode: opcode error
 * @line_number: line number where error occured
 *
 * Return: (EXIT_FAILURE)
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc errors
 *
 * Return: (EXIT_FAILURE)
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - prints file opening errors with file names
 * @filename: name of file failed to open
 *
 * Return: (EXIT_FAILURE)
 */
int open_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s, %s\n", filename, strerror(errno));
	exit(EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid push argument errors
 * @line_number: line number where error occurred
 *
 * Return: (EXIT_FAILURE)
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
