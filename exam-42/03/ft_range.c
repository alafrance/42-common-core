int *ft_range(int start, int end){
    int *range;
    int i;
    i = 0;
    if (!(range = malloc(sizeof(int) * ((end - start) + 1)))){
        return (void*)0;
    }
    while(i != end - start + 1){
        range[i] = start + i;
        i++;
    }
    return range;
}
