#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

void	print_bits(unsigned char octet){
    int bin = 128;
    while (bin != 0){
        if (bin <= octet){
            ft_putchar('1');
            octet = octet - bin;
        }else{
            ft_putchar('0');
        }
        bin = bin / 2;
    } 
}
int main()
{
	int n = 3;
    print_bits(n);
    return 0;
}