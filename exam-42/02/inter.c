#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
void inter(char *s1, char *s2){
    int i = 0, j = 0, ascii[256], letterascii = 0;
    while(i != 256){
        ascii[i] = 0;
        i++;
    }
    i = 0;
    while(s1[i]){
        letterascii = s1[i];
        if (s2[j] == '\0'){
            i++;
            j = 0;
        }
        if(s1[i] == s2[j]){
            if (ascii[letterascii] == 0){
                ascii[letterascii] = 1;
                ft_putchar(s1[i]);
            }
            j = 0;
            i++;
        }else{
            j++;
        }

    }

}

int main(int ac, char *av[])
{
    if (ac == 3){
        inter(av[1], av[2]);
    }
    ft_putchar('\n');
    return 0;
}