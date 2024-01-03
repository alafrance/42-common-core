#include "ft_list.h"
#include <stdlib.h>
void ft_list_clear(t_list *begin_list, void(*free_fct)(void*)){
	t_list *tmp;
	tmp = NULL;
	while(begin_list){
		tmp = begin_list;
		begin_list = begin_list->next;
		free_fct(tmp->data);
		free(tmp);
	}
}

