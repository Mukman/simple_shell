#include "shell.h"

/**
* interactive - returns true if shell is interactive mode
* @addres: struct address
*
* Return: 1 if interactive mode, 0 otherwise
*/
int interactive(info_t *addres)
{
return (isatty(STDIN_FILENO) && addres->readfd <= 2);
}

/**
* is_delimeter - checks if character is a delimeter
* @x: the char to check
* @delimeter: the delimeter string
* Return: 1 if true, 0 if false
*/
int is_delimeter(char x, char *delimeter)
{
while (*delimeter)
if (*delimeter++ == x)
return (1);
return (0);
}

/**
*_isalphabet - checks for alphabetic character
*@x: The character to input
*Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalphabet(int x)
{
if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
return (1);
else
return (0);
}

/**
*conv_int - converts a string to an integer
*@n: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/

int conv_int(char *n)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  n[i] != '\0' && flag != 2; i++)
{
if (n[i] == '-')
sign *= -1;

if (n[i] >= '0' && n[i] <= '9')
{
flag = 1;
result *= 10;
result += (n[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
