#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>

void ft_putchar(char c){
	write(1, &c, 1);
}
   
void ft_putstr(char *str){
	int i;

    i = 0;
    while(str[i])
    	ft_putchar(str[i++]);
}
void ft_display_file(char *filename){
	int fd;
	char buf[1];

	fd = open(filename, O_RDONLY);

	if(fd == -1){
		ft_putstr("ft_cat: ");
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
	}
	else{
		while(read(fd, buf, 1))
			ft_putstr(buf);
		close(fd);
	}
}


void  disp_stdin(void){
	char buffer;

	while(read(0, &buffer, 1) != 0)
		write(1, &buffer, 1);
}
void ft_cat(char **array_filemane, int size){
	int i;

	i = 1;

	while(i != size)
		ft_display_file(array_filemane[i++]);
}


int main(int ac, char **av){
	errno = 0;
	if(ac < 2 || av[1][0] == '-')
		disp_stdin();
	ft_cat(av, ac) ;
	return 0;
}

