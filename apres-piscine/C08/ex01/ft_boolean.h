#ifndef _FT_BOOLEAN_H

#include <unistd.h>
#define _FT_BOOLEAN_H 
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 1
#define TRUE 1 
#define FALSE 0
#define EVEN(nbr) nbr % 2 == 0
typedef int t_bool;

#endif
