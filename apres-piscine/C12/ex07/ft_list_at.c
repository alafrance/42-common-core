#include "ft_list.h"

int ft_list_size(t_list *begin_list){
	int count;

	count = 0;
	while(begin_list){
		begin_list = begin_list->next;
		count++;
	}
	return count;
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr){
    int i;

    i = 0;
    if(nbr >= ft_list_size(begin_list))
        return (void*)0;

    while(begin_list && i != nbr){
        begin_list = begin_list->next;
        i++;
    }
    return begin_list;
}


