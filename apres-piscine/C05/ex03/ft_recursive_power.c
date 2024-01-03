int ft_recursive_power(int nb, int power){
    if(power < 0)
        return 0;
    else if(power == 0)
        return 1;
    if(power > 1){
        return nb * ft_recursive_power(nb, power - 1);
    }
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    if(argc == 3){
        printf("%d", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
    }
    return 0;
}