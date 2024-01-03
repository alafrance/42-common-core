#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void initialize_board(char *board){
    int i;
    i = 0;
    while(i != 100){
        board[i] = '0';
        i++;
    }
    board[i] = '\0';
}

int ft_ten_queens_puzzle(void){
    int number_queens;
    char board[100];
    int possibility;

    possibility = 0;
    number_queens = 10;

    initialize_board(board);

    printf("%ld", strlen(board));
    return possibility;
}
int main(int argc, char const *argv[])
{
    ft_ten_queens_puzzle();
    return 0;
}
