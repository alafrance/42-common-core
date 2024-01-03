#include "ft_list.h"
#include <stdlib.h>
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()){
    t_list *curr;
    t_list *tmp;

    while(*begin_list && cmp((*begin_list)->data, data_ref) == 0){
        curr = *begin_list;
        *begin_list = curr->next;
        free(curr);
    }
    curr = *begin_list;
    while(curr && curr->next){
        if(cmp(curr->next->data, data_ref) == 0){
            tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        }
        curr = curr->next;
    }
}
/*
#include <string.h>
#include <stdio.h>
void print_list(t_list *lst){
    while(lst){
        printf("%s\n", lst->data);
        lst = lst->next;
    }
}
int main(){
    int i;
    t_list *begin;
    t_list *list;
    char *tab[5];

    tab[0] = "hola";
    tab[1] = "bonjour";
    tab[2] = "hello";
    tab[3] = "bonjourno";
    tab[4] = "como estas";
    tab[5] = "muy bien";
    i = 0;
    list = malloc(sizeof(t_list));
    begin = list;

    while(i != 4){
        list->data = tab[i];
        list->next = malloc(sizeof(t_list));
        list = list->next;
        i++;
    }
    list->data = tab[i];
    list->next = NULL;
    list = begin;
    print_list(list);
    printf("----\n");
    ft_list_remove_if(&list, "bonjour", strcmp);
    print_list(list);
}
*/