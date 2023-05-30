#include "main.h"

/************************* EVALUATES AND PRINT THE WIDTH *************************/
/**
 * get_width - Evaluates the width for the print function
 * @format: Formats strings that are used print the diff arguments.
 * @i: List of all the arguments to be printed.
 * @list: list of all arguments to be printed.
 * Return:Results
 */

int get_width(const char *format, int *i, va_list list)
{
	int cst_i;
	int wid = 0;

	for (cst_i = *i + 1; format[cst_i] != '\0'; cst_i++)
	{
		if (is_digit(format[cst_i]))
		{
			wid*= 10;
			wid += format[cst_i] - '0';
		}
		else if (format[cst_i] == '*')
		{
			cst_i++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cst_i - 1;

	return (wid);
}
