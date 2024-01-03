#include "ft_list.h"
void ft_list_sort(t_list **begin_list, int (*cmp)()){
    t_list *curr;
    int swapped;
    void *tmp;

    curr = *begin_list;
    swapped = 1;
    // la boucle s'arrete s'il n'y a eu aucun swap entre toutes les valeurs(Si tout est bien trié.)
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

