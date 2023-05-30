#include "main.h"

/************************* Evaluate and calculate the size to be cast *************************/
/**
 * get_size - Evaluates the precise size to cast the argument
 * @format: string that are formatted in which to print the arguments
 * @i: List of all arguments to be printed.
 * Return: Results
 */

int get_size(const char *format, int *i)
{
	int cst_i = *i + 1;
	int val = 0;

	if (format[cst_i] == 'l')
		val = S_LONG;
	else if (format[cst_i] == 'h')
		val = S_SHORT;

	if (val == 0)
		*i = cst_i - 1;
	else
		*i = cst_i;

	return (val);
}
