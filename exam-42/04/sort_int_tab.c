void sort_int_tab(int *tab, unsigned int size){
    int i;
    int j;
    int tmp;

    tmp = 0;
    j = 0;
    i = 0;
    if(size == 0)
        return ;
    while(j + 1 != size){
        while(i + 1 != size){
            if(tab[i] > tab[i + 1]){
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
            }
            i++;
        }
        i = 0;
        j++;
    }
}