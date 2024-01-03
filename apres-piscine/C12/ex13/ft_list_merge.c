#include "ft_list.h"
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

