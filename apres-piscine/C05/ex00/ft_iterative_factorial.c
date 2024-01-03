int ft_iterative_factorial(int nb){
    int i;
    int fac;

    fac = 1;
    i = 1;
    if(nb < 0){
        return 0;
    }
    while(i != nb + 1){
        fac *= i;
        i++;
    }
    return fac;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d", ft_iterative_factorial(0));
    return 0;
}
