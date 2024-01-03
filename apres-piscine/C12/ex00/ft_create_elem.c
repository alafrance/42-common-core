#include "ft_list.h"
#include <stdlib.h>
t_list *ft_create_elem(void *data){
	t_list *elem;
	elem = NULL;
	elem = malloc(sizeof(*elem));
	if(elem){
		elem->data = data;
		elem->next = NULL;
	}
	return elem;
}

