#include "ft_list.h"
void ft_list_reverse(t_list **begin_list){
    t_list *prev;
    t_list *curr;
    t_list *next;
    prev = NULL;
    curr = *begin_list;
    next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *begin_list = prev;
}
