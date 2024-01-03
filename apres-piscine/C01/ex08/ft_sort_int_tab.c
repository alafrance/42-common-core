void ft_sort_int_tab(int *tab, int size)
{
    int i = 0, j = 0;
    while (j != size - 1)
    {
        while (i != size - j - 1)
        {
            if (tab[i + 1] < tab[i])
            {
                int swap;
                swap = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = swap;
            }
            i++;
        }
        i = 0;
        j++;
    }
}

/*
#include <stdio.h>

int main()
{
    int size = 9;
    int tab[9] = {6, 5, 3, 2, 1, 7, 56, 4, 8};
    int i = -1;
    printf("{");
    while (++i != size){
        if (i == size - 1){
            printf("%d", tab[i]);
        }else{
            printf("%d, ", tab[i]);
        }
    }
    printf("}\n\n");
    i = -1;
    ft_sort_int_tab(tab, 9);
    printf("{");
    while(++i != size){
        if (i == size - 1){
            printf("%d", tab[i]);
        }else{
            printf("%d, ", tab[i]);
        }
    }
    printf("}");
}
*/