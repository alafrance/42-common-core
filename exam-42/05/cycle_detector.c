/*
typedef struct     s_list
    {
        int            data;
        struct s_list  *next;
    }                  t_list;
*/
int        cycle_detector(const t_list *list){
    t_list *hare1;
    t_list *hare2;
    t_list *tortoise;

    tortoise = list;
    hare1 = tortoise;

    while(tortoise && (hare2 = hare1->next) && (hare1 = hare2->next)){
        if(hare1 == tortoise || hare2 == tortoise)
            return 1;
        tortoise = tortoise->next;
    }
    return 0;
}
