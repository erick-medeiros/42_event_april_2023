#include <stdlib.h>
#include <stdio.h>

#define INT_MAX 2147483647

#define is_even(x) !(x % 2)

void putn(char c, size_t size)
{
	int i = -1;
	while (++i < size)
		putc(c, stdout);
}

int offset_pyramid(int id)
{
	if (!is_even(id))
		id++;
	return ((id / 2) + 2) * 2;
}

int mid_odd(int size)
{
	return ((size - 1) / 2) + 1;
}

int	last_line_size(int len)
{
	int total = 1;
	int i = 0;
	while (++i <= len)
	{
		total += ((i + 1) * 2);
		if (i + 1 <= len)
			total += offset_pyramid(i);
	}
	total += 2;
	return (total);
}

void draw_door(int door)
{
	static int index = 0;

	index++;
	if (mid_odd(door) == index && door >= 5)
	{
		putn('|', door - 2);
		putn('$', 1);
		putn('|', 1);
	}
	else
		putn('|', door);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	long len = atol(argv[1]);
	if (len <= 0 || len > INT_MAX)
		return 0;
	//
	int buff = mid_odd(last_line_size(len));
	int door = is_even(len) ? len - 1 : len;
	//
	int ast = 1; //asterisk
	int i = 0;
	while (++i <= len)
	{
		for (int j = 0; j < i + 2; j++)
		{
			if (j)
				ast += 2;
			printf("%*s", buff - mid_odd(ast), "/");
			if (i == len && j >= i + 2 - door)
			{
				putn('*', (ast - door) / 2);
				draw_door(door);
				putn('*', (ast - door) / 2);
			}
			else
				putn('*', ast);
			printf("\\\n");
		}
		if (i + 1 <= len)
			ast += offset_pyramid(i);
	}
}
