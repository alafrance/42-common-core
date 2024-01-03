#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs){
	int i;
	t_list *list;
	t_list *tmp;
	tmp = NULL;
	i = -1;
	while(++i != size){
		tmp = list;
		list = ft_create_elem(strs[i]);
		list->next = tmp;
	}
	return list;
}
