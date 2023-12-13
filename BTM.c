#include "shell.h"

/**
* active - returns true if shell is active mode
* @info: struct address
*
* Return: 1 if active mode, 0 otherwise
*/
int active(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* delim - checks if character is a delimeter
* @c: the char to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
*/
int delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
*alpha - checks for alphabetic character
*@d: The character to input
*Return: 1 if d is alphabetic, 0 otherwise
*/

int alpha(int d)
{
if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
return (1);
else
return (0);
}

/**
*__atoi - converts a string to an integer
*@s: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/

int __atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
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
