#include <unistd.h>
void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    int i;

    i = 0;
    while(str[i])
        ft_putchar(str[i++]);
}
void ft_print_hex(int nb){
    if (nb >= 16)
		ft_print_hex(nb / 16);
	ft_putchar(nb % 16 + (nb % 16 < 10 ? '0' : 'a' - 10));
}
void	print_memory(const void *addr, size_t size){
    unsigned char *str = (unsigned char*)addr;
    size_t i;
    int col;
    size_t tmp;

    col = 0;
    i = 0;
    while(i < size){
        col = 0;
        tmp = i;
        while(col < 16){
            if(i < size){
                if (str[i] < 16)
                    ft_putchar('0');
                ft_print_hex(str[i]);
            }
            else
                ft_putstr("  ");
            i++;
            col++;
            if(i % 2 == 0)
                ft_putchar(' ');
        }
        col = 0;
        i = tmp;
        while(col < 16 && i < size){
            if(str[i] >= 32 && str[i] <= 127)
                ft_putchar(str[i]);
            else
                ft_putchar('.');
            i++;
            col++;
        }
        ft_putchar('\n');
    }
}
/*
int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
*/