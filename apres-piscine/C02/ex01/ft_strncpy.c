char *ft_strncpy(char *dest, char *src, unsigned int n){
    int i;
    i = 0;
    while (i != n && src[i])
        dest[i] = src[i++];
    while (dest[i])
        dest[i++] = '\0';
    return dest;
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char src[30] = "coucou lee lee";
    char dest[30]  = "jean jean";
    printf("src : %s, dest: %s\n", src, dest);
    ft_strncpy(dest, src, 10);
    printf("src : %s, dest: %s\n", src, dest);
    return 0;
}
*/