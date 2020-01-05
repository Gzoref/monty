#include "monty.h"

/**
 * get_push - function that pushes an element onto top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * @temp: Pointer to instruction
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_push(stack_t **stack, unsigned int line_number, char *temp)
{

	stack_t *new_top;
	long int n;

	(void)line_number;

	if (temp != NULL)
	{
		if (atoi(temp) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = atoi(temp);
	}

	if (_isdigit(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_top->n = n;
	new_top->next = NULL;
	new_top->prev = NULL;

	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	*stack = new_top;
}


/**
 *  _isdigit - Finds if char is a digit or not
 *
 *  @str: Character passed in
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1); /* Success */
	}
	return (0);
}
