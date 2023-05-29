#include "main.h"

/****************** TO PRINT POINTER ******************/
/**
 * print_pointer - Prints the input value of pointer of a variable
 * @types: List all types of arguments
 * @buffer: Buffer array to assist print
 * @flags:  Calculates all present active flags
 * @width: shows precise width
 * @precision: shows precision specification
 * @size: specifies sixe
 * Return: Result
 */
 
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int vpv = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[vpv--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

    vpv++;
	
	return (write_pointer(buffer, vpv, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE HEXADECIMAL NOTATION*************************/
/**
 * print_non_printable - Prints ascii codes in hexadecimals in non printable chars
 * @types: List all types of arguments
 * @buffer: Buffer array to assist print
 * @flags:  Calculates all present active flags
 * @width: shows precise width
 * @precision: shows precision specification
 * @size: shows precise size
 * Return: Result
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = 0, ascii = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[c] != '\0')
	{
		if (is_printable(str[c]))
			buffer[c + ascii] = str[c];
		else
			ascii += append_hexa_code(str[c], buffer, c + ascii);

		c++;
	}

	buffer[c + ascii] = '\0';

	return (write(1, buffer, c + ascii));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints string in reverse
 * @types:  List all types of arguments
 * @buffer: Buffer array to assist print
 * @flags:  Calculates all present active flags
 * @width: shows precise width
 * @precision: shows precision specification
 * @size: shows precise size
 * Return: Result
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int b, val = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (b = 0; string[b]; b++)
		;

	for (b = b - 1; b >= 0; b--)
	{
		char z = string[b];

		write(1, &z, 1);
		val++;
	}
	return (val);
}
/************************* TO PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: List all types of arguments
 * @buffer: Buffer array to assist print
 * @flags:  Calculates all present active flags
 * @width: shows precise width
 * @precision: shows precision specification
 * @size: shows size
 * Return: Results
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	char b;
	unsigned int i, j;
	int val = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[i])
			{
				b = out[j];
				write(1, &b, 1);
				val++;
				break;
			}
		}
		if (!in[j])
		{
			b = string[i];
			write(1, &b, 1);
			val++;
		}
	}
	return (val);
}

