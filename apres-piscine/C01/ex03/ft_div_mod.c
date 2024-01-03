void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}
/*
#include <stdio.h>
int main() {
    int a = 11;
    int b = 5;
    int division = 0;
    int reste = 0;
    int *div;
    int *mod;
    div = &division;
    mod = &reste;
    printf("div %d, mod: %d\n", division, reste);
    ft_div_mod(a, b, div, mod);
    printf("div %d, mod: %d\n", division, reste);
    return 0;
}
*/