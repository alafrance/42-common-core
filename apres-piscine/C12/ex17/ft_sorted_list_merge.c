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
void ft_list_merge(t_list **begin_list1, t_list *begin_list2){
    t_list *tmp;
    tmp = *begin_list1;
    if(!tmp){
        *begin_list1 = begin_list2;
        return ;
    }
    while(tmp->next){
        tmp = tmp->next;
    }
     tmp->next = begin_list2;
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()){
    t_list *tmp;
    t_list *begin;
    begin = *begin_list1;
    ft_list_merge(begin_list1, begin_list2);
    *begin_list1 = begin;
    ft_list_sort(begin_list1, cmp);
    *begin_list1 = begin;
}


