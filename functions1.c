#include "main.h"

/************************* TO PRINT UNASIGNED NUMBERS *************************/
/**
 * print_unsigned - Prints all unsigned number
 * @types: List diffrent types of arguments
 * @buffer: Buffers array to assist print
 * @flags:  Calculates all active flags
 * @width: get the width of code
 * @precision: shows precision specification
 * @size: Show size
 * Return: results
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 10) + '0';
		num /= 10;
	}

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}

/************* TO PRINT ALL UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Functions that prints an unsigned number in an octal notation
 * @types: Lists all of the arguments
 * @buffer: Buffer array to assist print
 * @flags:  Calculates all active flags
 * @width: shows width
 * @precision: shows precision specification
 * @size: Size specifier
 * Return:  results
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[c--] = '0';

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}

/************** TO PRINT ALL UNSIGNED NUMBER IN HEXADECIMAL NOTATION **************/
/**
 * print_hexadecimal - Prints an input number in hexadecimal notation
 * @types: Lists all types of arguments
 * @buffer: Buffer array to assists print
 * @flags:  Calculates all present active flags
 * @width: get precise width
 * @precision: shows precision specification
 * @size: specifies size
 * Return: results
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lists all types of arguments
 * @buffer: Buffer array to assists print
 * @flags:  Calculates all present active flags
 * @width: get precise width
 * @precision: shows precision specification
 * @size: specifies size
 * Return: results
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**************  TO PRINT HEX NUMBER IN THELOWER OR UPPER NOTATION **************/
/**
 * print_hexa - Prints all hexadecimal numbers in lower or upper notation
 * @types: Lists all types of arguments
 * @map_to: shows array of values to map out the number in code
 * @buffer: Buffer array to assists print
 * @flags:  Calculates all present active flags
 * @flag_ch: Calculates all present active flags
 * @width: get precise width
 * @precision: Precision specification
 * @size: get precise size
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[b--] = flag_ch;
		buffer[b--] = '0';
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}


