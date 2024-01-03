#include <unistd.h>
typedef struct s_point{
    int x;
    int y;
}   t_point;

void  flood_fill(char **tab, t_point size, t_point begin){
    char paint;
    t_point coord;

    paint = tab[begin.x][begin.y];
    tab[begin.x][begin.y] = 'F';
    if(begin.x - 1 < size.x && begin.y < size.y && tab[begin.x - 1][begin.y] == paint) {
        coord.x = begin.x - 1;
        coord.y = begin.y;
        flood_fill(tab, size, coord);
    }
    if(begin.x  + 1 < size.x && begin.y < size.y && tab[begin.x + 1][begin.y] == paint) {
        coord.x = begin.x + 1;
        coord.y = begin.y;
        flood_fill(tab, size, coord);
    }

    if(begin.x< size.x && begin.y - 1 < size.y && tab[begin.x][begin.y - 1] == paint) {
        coord.x = begin.x;
        coord.y = begin.y - 1;
        flood_fill(tab, size, coord);
    }
    if(begin.x < size.x && begin.y - 1 < size.y && tab[begin.x][begin.y + 1] == paint) {
        coord.x = begin.x;
        coord.y = begin.y + 1;
        flood_fill(tab, size, coord);
    }
}

