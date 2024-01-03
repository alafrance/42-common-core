int	    is_power_of_2(unsigned int n){
    if (n <= 1)
        return 0;
    while (n > 2){
        if( n % 2 != 0)
            return 0;
        n /= 2;
    }
    return 1;
}

#include <stdlib.h>
#include <stdio.h>
int main(int ac, char *av[])
{
    if (ac == 2){
        printf("%d", is_power_of_2(atoi(av[1])));
    }
    return 0;
}