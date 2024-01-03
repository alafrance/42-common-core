#include <stdlib.h>

int     *ft_rrange(int start, int end){
    int *tab;
    int i;
    int range;

    i = 0;
    if(start == end){
        tab = malloc(sizeof(int) * 1);
        tab[i] = start;
        return tab;
    }
    if(start > end)
        range = start - end + 1;
    else
        range = end - start + 1;

    tab = malloc(sizeof(int) * range);
    while(i != range){
        if(end < 0)
            tab[i] = end + i;
        else
            tab[i] = end - i;
        i++;
    }
    return tab;

}
