void ft_rev_int_tab(int *tab, int size)
{
    int i = 0;
    while (i != size / 2)
    {
        int swap;
        swap = tab[i];
        tab[i] = tab[size - i - 1];
        tab[size - i - 1] = swap;
        i++;
    }
}
/*
#include <stdio.h>
int main() {
    int tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = -1;
    while(i++ != 9){
        printf("%d : %d\n", i, tab[i]);
    }
    i = -1;
    printf("\n");
    ft_rev_int_tab(tab, 9);
    while(i++ != 9){
        printf("%d : %d\n", i, tab[i]);
    }
    return 0;
}
*/