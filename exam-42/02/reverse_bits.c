#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
unsigned char	reverse_bits(unsigned char octet){
    octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
    octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
    octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
    return octet;
}
void	print_bits(unsigned char octet){
    int bin = 128;
    while (bin != 0){
        if (bin == 8){
            ft_putchar(' ');
        }
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
    char a = 'a';
    print_bits(a);
    ft_putchar('\n');
    a = reverse_bits(a);
    print_bits(a);
    return 0;
}