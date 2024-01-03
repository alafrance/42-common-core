#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    int i;

    i = 0;
    while(str[i])
        ft_putchar(str[i++]);
}
int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}
void display_options(int *array){
    int i;

    i = 0;
    while(i != 32){
        ft_putchar(array[i++] + '0');
        if(i % 8 == 0 && i != 0 && i != 32)
            ft_putchar(' ');
    }
}
int is_option_h(char **av, int ac){
    int i;
    int j;

    i = 0;
    j = 0;
    while(i != ac){
        while(av[i][j]){
            if(av[i][j]  == 'h' && av[i][0] == '-')
                return 1;
            j++;
        }
        i++;
        j = 0;
    }
    return 0;
}
void options(char **av, int ac){
    int i;
    int j;
    int a_options[32];

    i = 0;
    j = 1;
    while(i != 32)
        a_options[i++] = 0;
    i = 0;
    while(i != ac){
        while(av[i][j]){
            a_options[31 - av[i][j] + 'a'] = 1;
            j++;
        }
        i++;
        j = 1;
    }
    display_options(a_options);
}

int is_invalid_options(char **av, int ac){
    int i;
    int j;

    i = 0;
    j = 1;
    while(i != ac){
        if(av[i][0] != '-' || ft_strlen(av[i]) == 1){
            return 1;
        }
        while(av[i][j]){
            if(!(av[i][j] >= 'a' && av[i][j] <= 'z'))
                return 1;
            j++;
        }
        j = 1;
        i++;
    }
    return 0;
}
int main(int ac, char **av){
    if(is_invalid_options(av + 1, ac - 1))
        ft_putstr("Invalid Option");
    else if(ac == 1 || is_option_h(av, ac))
        ft_putstr("options: abcdefghijklmnopqrstuvwxyz");
    else
        options(av + 1, ac - 1);
    ft_putchar('\n');
    return 0;
}