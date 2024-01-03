#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
int check_rook(int size, char **arg, int *position){
    int i;

    i = 0;
    //check if the king is on the same index
    while(i != size){
        if(arg[i][position[1]] == 'K'){
            return 1;
        }
        i++;
    }
    i = 0;
    //check if the king is on the same array
    while(arg[position[0]][i]){
        if(arg[position[0]][i] == 'K')
            return 1; 
        i++;
    }
    return 0;
}
int check_paw(int size, char **arg, int *position){
    if(position[0]  == 0)
        return 0;
    if(arg[position[0] - 1][position[1] - 1] == 'K' 
        || arg[position[0] - 1][position[1] + 1] == 'K')
        return 1;
    return 0;
}
int check_bishop(int size, char **arg, int *position){
    int i;
    int size_array;

    size_array = ft_strlen(arg[0]);
    i = 0;
    while(i != size){
        if(position[1] - position[0] + i == 'K'
            || size_array - position[1] - position[0] - i)
            return 1;
        i++;
    }
    return 0;
}
int test_check_mate(int size, char **arg, int i, int j, char name_of_pieces, int check(int size, char **arg, int *position)){
    int *position;
    position = malloc(sizeof(int) * 2);
    if(arg[i][j] == name_of_pieces){
        position[0] = i;
        position[1] = j;
        if(check(size, arg, position))
            return 1;
    }
    return 0;
}
int is_check(int size, char **arg){
    int i;
    int j;

    j = 0;
    i = 0;
    while(i != size){
        while(arg[i][j]){
             if(test_check_mate(size, arg, i, j, 'R', check_rook)
                || test_check_mate(size, arg, i, j, 'P', check_paw)
                || test_check_mate(size, arg, i, j, 'B', check_bishop)
                || test_check_mate(size, arg, i, j, 'Q', check_rook)
                || test_check_mate(size, arg, i, j, 'Q', check_bishop))
                return 1;
            j++;
        }
        i++;
        j = 0;
    }
    return 0;
}
int main(int ac, char **av){
    if(ac >= 2){
        if(is_check(ac - 1, av + 1))
            ft_putstr("Success");
        else
            ft_putstr("Fail");
    }
    ft_putchar('\n');
    return 1;
}

