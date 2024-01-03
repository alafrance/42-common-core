int ft_strlen(char *str){
    int i = 0;
    while(str[i++]);
    return i;
}

char *ft_strcat(char *dest, char *src){
    int i;
    int j;
    j = ft_strlen(dest) - 1;
    i = 0;
    while (src[i]){
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}

/*
#include <stdio.h>
#include <string.h>
int main(){
    char src[45] =  "et moi la fin du...mooonde";
    char dest[125] = "Moi je suis le debut mouah ah ah,";
    //printf("%s\n", strcat(dest, src));
    printf("%s\n", ft_strcat(dest, src));
}
*/