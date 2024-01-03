#include "ft_list.h"
t_list *ft_list_last(t_list *begin_list){
	t_list *actual;
	if(begin_list == NULL)
		return NULL;
	while(begin_list->next)
		begin_list = begin_list->next;
	return begin_list;
}
