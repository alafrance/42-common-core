#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_char_is_printable(char c)
{
    return ((c >= ' ' && c <= '~')) ? 1 : 0;
}
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        ft_putchar(str[i++]);
}

void ft_print_nbr_in_base(int nb, int base)
{
    int nbr;
    if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    nbr = nb;
    if (nbr >= base)
    {
        nbr = nbr / base;
        ft_print_nbr_in_base(nbr, base);
    }
    nb = nb % base + 48;
    
    if (nb > '9')
        ft_putchar('a' + nb - '9' - 1);
    else
        ft_putchar(nb);
}


void	ft_putaddr(void *addr)
{
	char	addr_c[15];
	long	addr_l;
	int		i;

	addr_l = (long)addr;
	i = 0;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] < 10)
            addr_c[i] += '0';
		else{
            addr_c[i] += 'a' - 10;
        }
		addr_l = addr_l / 16;
		i++;
	}
	while (i < 15)
		addr_c[i++] = '0';
	while (--i >= 0)
		ft_putchar(addr_c[i]);
}

void ft_print_content_hexa(char *str, unsigned int i,  unsigned int size ){
    int j;
    int k;
    k = 0;
    j = 0;
    while(k != 16){
        while (j != 2){
            if(str[i] && i < size){
                if(str[i] < 16) ft_putchar('0');
                ft_print_nbr_in_base(str[i], 16);
            }else if (i == size - 1 && str[i] == '\0')
                ft_putstr("00");
            else
                ft_putstr("  ");
            i++;
            j++;
            k++;
        }
        j = 0;
        ft_putchar(' ');
    }
}

void ft_putstr_non_printable2(char *str, unsigned int i, unsigned int size){
    int k;
    k = 0;
    while(k != 16){
        if (str[i] && i < size){
            if (ft_char_is_printable(str[i]))
                ft_putchar(str[i]);
            else
                ft_putchar('.');
        }else if (i == size - 1 && str[i] == '\0')
            ft_putchar('.');
        k++;
        i++;

    }
}

void *ft_print_memory(void *addr, unsigned int size)
{
    char *str;
    unsigned int i;
    i = 0;
    str = addr;
    while (i < size)
    {
        ft_putaddr(addr + i);
        ft_putchar(':');
		ft_putchar(' ');
        ft_print_content_hexa(str, i, size);
        ft_putstr_non_printable2(str, i, size);
        i += 16;
        ft_putchar('\n');
    }
    return addr;
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[92] = "Bonjour les aminches...c  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol\n ";
    ft_print_memory(&str, strlen(str));
}
*/
// correction : https://git.42l.fr/frdescam/PISCINE/src/branch/master/C02/ex12/ft_print_memory.c
