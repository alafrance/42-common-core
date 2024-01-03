#include "ft_list.h"
t_list	*sort_list(t_list* lst, int (*cmp)(int, int)){
    t_list *curr;
    t_list *begin;
    int tmp;

    tmp = 0;
    curr = lst;
    begin = lst;
    while(lst){
        curr = lst->next;
        while(curr){
            if(!cmp(lst->data, curr->data)){
                tmp = lst->data;
                lst->data = curr->data;
                curr->data = tmp;
            }
            curr = curr->next;
        }
        lst = lst->next;
    }
    return begin;
}