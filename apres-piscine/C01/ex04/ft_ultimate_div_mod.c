void ft_ultimate_div_mod(int *a, int *b)
{
    int swap;
    swap = *a;
    *a = *a / *b;
    *b = swap % *b;
}

/*
#include <stdio.h>
int main() {
    int nb = 15;
    int nb2 = 5;
    int *a;
    int *b;
    a = &nb;
    b = &nb2;
    printf("nb: %d, nb2 : %d\n", nb, nb2);
    ft_ultimate_div_mod(a, b);
    printf("nb: %d, nb2 : %d\n", nb, nb2);

    return 0;
}
*/