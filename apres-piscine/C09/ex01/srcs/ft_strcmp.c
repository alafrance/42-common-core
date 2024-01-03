int ft_strcmp(char *s1, char *s2){
    int i;
    i = 0;
    while (s1[i]){
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

/*
#include <stdio.h>
#include <string.h>
int main(){
    char s1[100] = "Bonjour l'allocation dynamique...";
    char s2[100] = "Bonjour l'allocation dinamique... et la faute lol..";
    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", ft_strcmp(s1, s2));
}
*/