unsigned int ft_strlen(char *str){
    unsigned int i = 0;
    while(str[++i]);
    return i;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size){
    unsigned int dest_s;
    unsigned int src_s;
    unsigned int i;

    i = 0;
    dest_s = ft_strlen(dest);
    src_s = ft_strlen(src);
    if (size < ft_strlen(dest))
        return ft_strlen(src) + size;
    while(i <  size - dest_s - 1 && src[i]){
        dest[dest_s + i] = src[i];
        i++;
    }
    dest[dest_s + i] = '\0';
    return dest_s + src_s;

}

/*
#include <stdio.h>
#include <string.h>
int main(){
        char dest[70] = "Je suis la source bonjour"; // size 26 avec \0
        char src[32] = ", et bah moi enchante, la fin !"; // size 32 avec \0
        printf("ft : %d\n", ft_strlcat(dest, src, 35));
        //printf("strlcat : %ld\n", strlcat(dest, src, 35));
        printf("dest : %s\n", dest);
        printf("src : %s\n", src);
}
*/
