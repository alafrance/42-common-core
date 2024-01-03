#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    while(*str){
        ft_putchar(*str++);
    }
}
int main(){
    ft_putstr("9876543210");
    ft_putchar('\n');
}