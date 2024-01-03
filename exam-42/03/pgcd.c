#include <stdlib.h>
#include <stdio.h>

int pgcd(int a, int b){
    int nb_pgcd;
    int i;
    int highest;
    if(a == 0 || b == 0)
        return 0;
    if(a > b)
        highest = a;
    else 
        highest = b;
    nb_pgcd = 1;
    i = 2;
    while(i <= highest){
        if(a % i == 0 && b % i == 0)
            nb_pgcd = i;
        i++;
    }
    return nb_pgcd;
}
int main(int ac, char **av){
    if(ac == 3)
        printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
    printf("\n");
}