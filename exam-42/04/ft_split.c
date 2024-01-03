#include <stdlib.h>

int is_blank(char c){
    return (c == ' ' || c == '\t') ? 1 : 0;
}
int count_words(char *str){
    int count;
    int i;

    i = 0;
    count = 0;
    while(str[i]){
        while(is_blank(str[i]) && str[i])
            i++;
        if(str[i] != '\0')
            count++;
        while(!is_blank(str[i]) && str[i])
            i++;
    }
    return count;
}
int size_word(char *str, int begin){
    int count;

    count = 0;
    while(str[begin] && !is_blank(str[begin])){
        count++;
        begin++;
    }
    return count;
}
char **ft_split(char *str){
    char **split;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    split = malloc(sizeof(char*) * count_words(str));
    while(str[i]){
        while(is_blank(str[i]) && str[i])
            i++;
        split[j] = malloc(sizeof(char) * size_word(str, i) + 1);
        while(!is_blank(str[i]) && str[i]){
            split[j][k] = str[i];
            k++;
            i++;
        }
        split[j][k] = '\0';
        j++;
        k = 0;
    }
    return split;
}

