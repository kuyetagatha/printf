#include "main.h"

/****************** EVALUATE A PRINTABLE CHAR ******************/
/**
 * is_printable - checks if a char input is printable
 * @c: Char to be checked
 * Return: 1 if yes, 0 if no
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/****************** APPEND ASCCI IN HEXADECIMAL CODE ******************/
/**
 * append_hexa_code - Append all ascci input in hexadecimal code to buffer
 * @buffer: list of difffrent array of different chars.
 * @b: Num which will start the appending process.
 * @ascii_code: assigned ascii codes
 * Return: 3
 */

int append_hexa_code(char ascii_code, char buffer[], int b)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	ascii_code *= -1;

	buffer[b++] = '\\';
	buffer[b++] = 'x';
	buffer[b++] = map_to[ascii_code / 16];
	buffer[b] = map_to[ascii_code % 16];

	return (3);
}

/****************** CHECKS IF CHAR IS A DIGIT ******************/
/**
 * is_digit - Checks if a char is a digit
 * @c: Char to be checked.
 * Return: 1 if yes, 0 if no
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/****************** CAST NUMBER TO A SPECIFIED SIZE ******************/
/**
 * convert_size_number - Inputs number to the precise size
 * @num: Number that are to be casted.
 * @size: all number indicating the type of size to be casted.
 * Return: results
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/****************** CONVERTS A NUM TO A SPECIFIED SIZE ******************/
/**
 * convert_size_unsgnd - Converts a number to the precise size
 * @num: Number that are to be casted
 * @size: all number indicating the type of size to be casted.
 * Return: result
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
