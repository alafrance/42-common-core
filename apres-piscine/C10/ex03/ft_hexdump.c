#include "ft_h.h"
void  disp_void(void){
	char buffer;

	while(read(0, &buffer, 1) != 0);
}

void ft_display_error_filename(char *filename){
		ft_putstr("ft_hexdump: ");
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
}

int is_option_c(char **av, int ac){
	int i;

	i = 1;
	while(i != ac){
		if(av[i][0] == '-' && av[i][1] == 'C' && ft_strlen(av[i]) == 2)
			return 1;
		i++;
	}
	return 0;

}
int ft_count_size_file(char *filename){
	int count;
	int fd;
	char buf[1];
	fd = open(filename, O_RDONLY);
	count = 0;
	if(fd != -1){
		while(read(fd, buf, 1))
				count++;
	}
	close(fd);
	return count;

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
    if (nbr >= base){
        nbr = nbr / base;
        ft_print_nbr_in_base(nbr, base);
    }
    nb = nb % base + 48;
    
    if (nb > '9')
        ft_putchar('a' + nb - '9' - 1);
    else
        ft_putchar(nb);
}
void	ft_print_first_index(int index)
{
	char	index_c[8];
	long	index_l;
	int		i;

	index_l = (long)index;
	i = 0;
	while (index_l > 0)
	{
		index_c[i] = index_l % 16;
		if (index_c[i] < 10)
            index_c[i] += '0';
		else{
            index_c[i] += 'a' - 10;
        }
		index_l = index_l / 16;
		i++;
	}
	while (i < 8){
		index_c[i++] = '0';
	}
	while (--i >= 0){
		ft_putchar(index_c[i]);
	}
}
int malloc_result_hexa(int nb){
	int count;

	count = 0;
	while(nb != 0){
		nb /= 16;
		count++;
	}
	return count + 1;
}

void ft_print_content_hexa(char *filename, unsigned int i){
    int j;
    int k;
	int fd;
	char buf[1];
	fd = open(filename, O_RDONLY);
    k = 0;
    j = 0;
	if (fd == -1)
		ft_display_error_filename(filename);
	else{
		while(j != i){
			j++;
			read(fd, buf, 1);
		}
		j = 0;
		while(k != 16){
        	while (j != 2){
				if(read(fd, buf, 1)){
                	if(buf[0] <= 15)
						ft_putchar('0');
					ft_print_nbr_in_base(buf[0], 16);	
            	}else
                	ft_putstr("  ");
				i++;
            	j++;
            	k++;
				ft_putchar(' ');
        	}
			if(k == 8)
				ft_putchar(' ');
        	j = 0;
		}
    }
	close(fd);
}
void ft_display_file_with_index(char *filename, int index){
	int fd;
	int j;
	char buf[1];
	fd = open(filename, O_RDONLY);
	j = 0;
	while(j != index){
		j++;	
		read(fd, buf, 1);
	}
	if(read(fd, buf, 1)){
		(ft_char_is_printable(buf[0])) ? ft_putchar(buf[0]) : ft_putchar('.');
		j++;
	}
	while(read(fd,  buf, 1) && j % 16 != 0){
		(ft_char_is_printable(buf[0])) ? ft_putchar(buf[0]) : ft_putchar('.');
		j++;
	}
	close(fd);
}
void ft_hexdump(char **array_filename, int size_array){
	int i;
	int j;
	
	i = 1;
	j = 0;

	while(i != size_array){
		while(!is_a_file(array_filename[i])){
			i++;
		}	
		while(j <= ft_count_size_file(array_filename[i])){
			ft_print_first_index(j);
			ft_putstr("  ");
			ft_print_content_hexa(array_filename[i], j);
			ft_putchar('|');
			ft_display_file_with_index(array_filename[i], j);
			ft_putstr("|");
			ft_putchar('\n');
			j += 16;
		}
		ft_print_first_index(ft_count_size_file(array_filename[i]));
		ft_putchar('\n');
		i++;
	}
	
}


int main(int ac, char **av){
	errno = 0;
	if(ac < 2)
		disp_void();
	else
		ft_hexdump(av, ac);
	return 0;
}
