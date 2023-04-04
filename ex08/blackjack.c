#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CARDS "23456789TJDKA"

int main(int argc, char *argv[])
{
    int i;
    int    nb_total;
    int    a_total;

    if (argc != 2 || !strlen(argv[1]))
        return 1;
    i = 0;
    while (argv[1][i])
    {
        if (!strchr(CARDS, argv[1][i]))
            return 2;
        i++;
    }
    nb_total = 0;
    a_total = 0;
    for (int i = 0; argv[1][i]; i++)
    {
        if (isdigit(argv[1][i]))
            nb_total += (argv[1][i] - '0');
        else if (argv[1][i] == 'A')
            a_total++;
        else
            nb_total += 10;
    }
    nb_total += a_total;
    i = 0;
    while (i++ < a_total)
    {
        if (nb_total + 10 <= 21)
            nb_total += 10;
        else
            break;
    }
    if (nb_total == 21)
        printf("Blackjack!\n");
    else
        printf("%d\n", nb_total);
}