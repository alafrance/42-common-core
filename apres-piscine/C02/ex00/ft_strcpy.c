char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
        dest[i] = src[i++];
    while (dest[i])
        dest[i++] = '\0';
    return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char src[30] = "coucou lee lee";
    char dest[30]  = "jean jean";
    printf("src : %s, dest: %s\n", src, dest);
    ft_strcpy(dest, src);
    printf("src : %s, dest: %s\n", src, dest);
    return 0;
}
*/