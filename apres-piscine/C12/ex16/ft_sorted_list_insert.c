#include "ft_list.h"
void ft_list_sort(t_list **begin_list, int (*cmp)()){
    t_list *curr;
    int swapped;
    void *tmp;
    
    curr = *begin_list;
    swapped = 1;
    while(swapped != 0){
        swapped = 0;
        curr  = *begin_list;
        while(curr->next){
            if((*cmp)(curr->data, curr->next->data) > 0){
                swapped = 1;
                tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
            }
            curr = curr->next;
        }
    }
}
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()){
    t_list *begin;

    begin = (*begin_list);
    while((*begin_list)->next){
        *begin_list = (*begin_list)->next;
    }
    (*begin_list)->next = ft_create_elem(data);
    *begin_list = begin;
    ft_list_sort(begin_list, cmp);
    *begin_list = begin;
}

