int ft_iterative_power(int nb, int power){
    int i;
    int result;

    result = nb;
    i = 0;
    if(power < 0)
        return 0;
    else if(power == 0)
        return 1;
    while(i != power - 1){
        result *= nb;
        i++;
    }
    return result;
}
