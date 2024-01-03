#include "ft_list.h"
t_list *ft_list_last(t_list *begin_list){
	t_list *actual;
	if(begin_list == NULL)
		return NULL;
	while(begin_list->next)
		begin_list = begin_list->next;
	return begin_list;
}
void ft_list_push_back(t_list **begin_list, void *data){
	t_list *new_elem;
	t_list *last;
	new_elem = ft_create_elem(data);
	last = ft_list_last(*begin_list);
	last->next = new_elem;
}

