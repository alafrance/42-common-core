#include "ft_list.h"
#include <stdlib.h>
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)){
    t_list *next;
    t_list *current;
    
    next = NULL;
    current = *begin_list;
    while(*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0){
        next = (*begin_list)->next;
        (*free_fct)((*begin_list)->data);
        free(*begin_list);
        *begin_list = next;
    }
    while(current && current->next){
        if((*cmp)(current->next->data, data_ref) == 0){
                next = current->next->next;
                (*free_fct)(current->next->data);
                free(current->next);
                current->next = next;
        }else
            current = current->next;
    }
}

