char    *ft_strstr(char *str, char *to_find){
    int i;
    int j;
    i = 0;
    j = 0;
    char *find;
    while (str[i]){
        if(to_find[j] == '\0'){
            return str + i - j;
        }else if(str[i] == to_find[j]){
            j++;
        }else{
            j = 0;
        }
        i++;
    }
    return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(){
    char to_find[3] = "sa";
    char str[30] = "coucou salut salut la famimi";
    //printf("%s\n", strstr(str, to_find));
    printf("%s\n", ft_strstr(str,to_find));
}
*/
