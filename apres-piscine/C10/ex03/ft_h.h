#ifndef _FT_H
#define _FT_H
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <stdlib.h>
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

int     ft_strlen(char *str){
    int i;
    
    i = 0;
    while(str[++i]);
    return i;
}

int is_a_file(char *filename){
	int fd;
	fd = open(filename, O_RDONLY);
	return (fd == -1) ? 0 : 1;
}
#endif
