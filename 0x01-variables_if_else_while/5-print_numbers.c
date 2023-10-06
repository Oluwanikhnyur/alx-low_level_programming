#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single-digit numbers of base 10
 *              starting from 0 on a single line without spaces.
 *
 * Return: Always 0
 */
int main(void)
{
int i;

for (i = 0; i < 10; i++)
{
printf("%d", i);
}

printf("\n");

return (0);
}
