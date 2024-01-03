#include <stdio.h>
#include <stdlib.h>
int is_prime(int nb){
    int i;

    i = 2;
    if(nb <= 1)
        return 0;
    while(i * i <= nb){
        if(nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int find_next_prime(int nb){
    while(!is_prime(nb))
            nb++;
    return nb;
}
void fprime(int nb){
    int i;
    int pass;

    pass = 0;
    i = 2;
    if(nb == 1)
        printf("1");
    else{
        while(nb > 1){
            if(nb % i == 0){
                if(pass != 0)
                    printf("*");
                nb /= i;
                printf("%d", i);
                pass = 1;
            }
            else
                i = find_next_prime(i + 1);
        }
    }

}

int main(int ac, char **av){
    if(ac == 2)
        fprime(atoi(av[1]));
    printf("\n");
}