#include <stdio.h>

/**
 * factorize - factorize number.
 *
 * @n: the number to factorize.
 */
void factorize(unsigned long long n)
{
	unsigned long long p = 2;

	while (p <= n / 2 && n % p != 0)
	{
		p++;
	}

	if (n % p == 0)
	{
		printf("%llu=%llu*%llu\n", n, n / p, p);
	}
	else
	{
		printf("%llu=%llu*1\n", n, n);
	}

}


/**
 * main - entry point of the program.
 * The program factorize a set of number in a file.
 *
 * @argc: the number of parameter sent to the program.
 * @argv: an array of string representing the parameters sent.
 * Return: 0 on success and 1 on error.
 */
int main(int argc, char **argv)
{
	unsigned long long n = 0;
	FILE *f = NULL;

	if (argc < 2)
	{
		printf("usage: factors <file>\n");
		return (1);
	}

	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		perror("Error while opening file");
		return (1);
	}

	while (fscanf(f, "%llu\n", &n) == 1)
	{
		factorize(n);
	}

	return (0);
}
