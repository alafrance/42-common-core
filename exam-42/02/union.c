#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_union(char *s1, char *s2){
    int i = 0, ascii[256], letter;
    while (i != 256){
        ascii[i] = 0;
        i++;
    }
    i = 0;
    while (s1[i]){
        letter = s1[i];
        if(ascii[letter] == 0){
            ascii[letter] = 1;
            ft_putchar(s1[i]);
        }
        i++;
    }
    i = 0;
    while (s2[i]){
        letter = s2[i];
        if(ascii[letter] == 0){
            ascii[letter] = 1;
            ft_putchar(s2[i]);
        }
        i++;
    }

}


int main(int ac, char *av[])
{
    if (ac == 3){
        ft_union(av[1], av[2]);
    }
    ft_putchar('\n');
    return 0;
}