int ft_is_prime(int nb){
    long i;

    long nbr;

    nbr = nb;
    i = 2;
    if(nb < 0)
        return 0;
    if (nb == 0 || nb == 1)
        return 0;
    while(i * i <= nbr){
        if(nbr % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int ft_find_next_prime(int nb){
    if (nb <= 2)
        return 2;
    while(!ft_is_prime(nb))
        nb++;
    return nb;
}