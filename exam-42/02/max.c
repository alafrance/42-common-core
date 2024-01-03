
int		max(int* tab, unsigned int len){
    int max = 0;
    unsigned int i = 0;
    while(i != len){
        if (tab[i] > max){
            max = tab[i];
        }
        i++;
    }
    return max;
}

#include <stdio.h>
int main()
{
    int tab[10] = {0, 3, 6, 4, 2, 2, 2};
    printf("max = %d\n", max(tab, 2));
    return 0;
}