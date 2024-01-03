#include <stdio.h>
#include <stdlib.h>

void do_op(int nb1, int nb2, char operator){
    switch (operator)
    {
    case '+':
        printf("%d", nb1 + nb2);
        break;
    case '-':
        printf("%d", nb1 - nb2);
        break;
    case '*':
        printf("%d", nb1 * nb2);
        break;
    case '/':
        printf("%d", nb1 / nb2);
        break;
    case '%':
        printf("%d", nb1 % nb2);
        break;
    default:
        break;
    }
}

int main(int ac, char *av[])
{
    if (ac == 4){
        do_op(atoi(av[1]), atoi(av[3]), av[2][0]);
    }
    printf("\n");
    return 0;
}