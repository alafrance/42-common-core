void ft_swap(int *a, int *b)
{
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}
/*
#include <stdio.h>
int main() {
    int *a;
    int *b;
    int nb = 6;
    int nb2 = 7;
    a = &nb;
    b = &nb2;
    printf("nb : %d\n", nb);
    printf("nb2 : %d\n", nb2);
    ft_swap(a, b);
    printf("nb : %d\n", nb);
    printf("nb2 : %d\n", nb2);
    return 0;
}
*/