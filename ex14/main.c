#include <stdlib.h>
#include <stdio.h>

#define INT_MAX 2147483647

#define is_even(x) !(x % 2)
#define pyramid_height(id) id + 2

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

int increment_final_pyramid(int id)
{
	return (id + 1) * 2;
}

int mid_odd(int size)
{
	return ((size - 1) / 2) + 1;
}

int	last_line_size(int len)
{
	int total = 1;
	int id = 0;
	while (++id <= len)
	{
		total += increment_final_pyramid(id);
		if (id + 1 <= len)
			total += offset_pyramid(id);
	}
	total += 2;
	return (total);
}

void draw_door(int door_size)
{
	static int index = 0;

	index++;
	if (mid_odd(door_size) == index && door_size >= 5)
	{
		putn('|', door_size - 2);
		putn('$', 1);
		putn('|', 1);
	}
	else
		putn('|', door_size);
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
	int door_size = is_even(len) ? len - 1 : len;
	int ast = 1; //asterisk
	int id = 0;
	while (++id <= len)
	{
		for (int j = 0; j < pyramid_height(id); j++)
		{
			if (j)
				ast += 2;
			printf("%*s", buff - mid_odd(ast), "/");
			if (id == len && j >= pyramid_height(id) - door_size)
			{
				putn('*', (ast - door_size) / 2);
				draw_door(door_size);
				putn('*', (ast - door_size) / 2);
			}
			else
				putn('*', ast);
			printf("\\\n");
		}
		if (id + 1 <= len)
			ast += offset_pyramid(id);
	}
}
