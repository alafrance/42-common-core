#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void hidenp(char *s1, char *s2){
    int i;
    int j;

    i = 0;
    j = 0;
    while(s2[j]){
        if(s2[j] == s1[i])
            i++;
        j++;
    }
    (s1[i] == '\0') ? ft_putchar('1') : ft_putchar('0');
}

int main(int ac, char **av){
    if(ac == 3)
        hidenp(av[1], av[2]);
    ft_putchar('\n');
    return 0;

}