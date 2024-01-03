#include "ft_h.h"
#include "ft_option_c.h"

void  disp_void(void){
	char buffer;

	while(read(0, &buffer, 1) != 0);
}
void ft_display_error_filename(char *filename){
		ft_putstr("ft_tail: ");
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
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

void display_name_file(int size_array_filename, char *filemane){
	if(size_array_filename > 4){
			ft_putstr("==> ");
			ft_putstr(filemane);
			ft_putstr(" <==\n");
	}
}
void display_file_with_size(char *filemane, int size_display, int size_file){
	int fd;
	int i;
	char *buf;

	if (size_display < size_file)
		buf = malloc(sizeof(char*) * size_display);
	else
		buf = malloc(sizeof(char*) * size_file);
	i = 0;
	fd = open(filemane, O_RDONLY);
	if(size_display < size_file){
		while(i != size_file - size_display && read(fd, buf, 1))
		i++;
		read(fd, buf, size_display);
	}else
		read(fd, buf, size_file);
	(size_display != 0) ? ft_putstr(buf) : NULL;
	close(fd);
}

void ft_tail(char **array_filemane, int size_array_filename, int size_display){
	int i;
	int size_file;
	
	i = 1;
	size_file = 0;
	while(i != size_array_filename){
		if(is_a_file(array_filemane[i])){
			display_name_file(size_array_filename, array_filemane[i]);	
			size_file = ft_count_size_file(array_filemane[i]);
			display_file_with_size(array_filemane[i], size_display, size_file);
		}else if(!is_c_option(array_filemane[i]) && !is_c_option(array_filemane[i - 1]))
			ft_display_error_filename(array_filemane[i]);
		i++;
	}
}
#include <stdio.h>
int main(int ac, char **av){
	errno = 0;
	// if there are no option for -c
	if(isnt_a_option(av, ac)){
		ft_putstr("ft_tail: l'option requiert un argument -- c\n");	
	}
	// if there are no files but option	
	else if(ac == 1 || is_option(av, ac) && ac == 3 || ac == 2 && av[1][0] == '-' && ft_strlen(av[1]) == 1){
		disp_void();
	}
	// if the option for -c is false
	else if(!is_option(av, ac)){
		ft_putstr("ft_tail: nombre d'octets incorrect: « ");
		ft_putstr(option(av, ac));
		ft_putstr(" »\n");
	}
	// All is good
	else
		ft_tail(av, ac, ft_atoi(option(av, ac)));
	return 0;
}

