#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define PADDING 4
#define BYTE_COMPLETE 0b11000000
#define BYTE_CONTINUATION 0b10000000

size_t utf8len(const char *s) {
    size_t count = 0;
	if (!s)
		return 0;
    while (*s)
        count += (*s++ & BYTE_COMPLETE) != BYTE_CONTINUATION;
    return count;
}

static void	print_border(int len)
{
	for (int i = 0; i < len + PADDING; i++)
		printf("*");
	printf("\n");
}

int main(int argc, char **argv)
{
	size_t len = 0;
	char *copy;

	setlocale(LC_ALL, "en_US.UTF-8");
	if (argc == 1)
		return (1);
	for (int i = 1;i<argc;i++)
	{
		copy = strdup(argv[i]);
		for (char *s = strtok(copy, " "); s; s = strtok(NULL, " "))
			len = utf8len(s) > len ? utf8len(s) : len;
		free(copy);
	}
	print_border(len);
	for (int i = 1;i<argc;i++)
		for (char *s = strtok(argv[i], " "); s; s = strtok(NULL, " "))
			printf("* %s%*s *\n", s, (int)(len - utf8len(s)), "");
	print_border(len);
}
