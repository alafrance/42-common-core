#include <unistd.h>
#include <fcntl.h>

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

	if(fd == -1)
		ft_putstr("Cannot read file.\n");
	else{
		while(read(fd, buf, 1))
			ft_putstr(buf);
		close(fd);
	}
}

int main(int ac, char **av){
	if(ac == 1)
		ft_putstr("File name missing.\n");
	else if(ac > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(av[1]);
}
