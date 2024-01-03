#include <stdio.h>
#include <stdlib.h>
int is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '%' || c == '/') ? 1 : 0;
}
int is_number(char c){
    return (c >= '0' && c <= '9') ? 1 : 0;
}
int is_space(char c){
    return (c == ' ') ? 1 : 0;
}
int do_op(int a, int b, char op){
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a * b;
    if(op == '/')
        return a / b;
    if(op == '%')
        return a % b;
    return 0;
}
int check_rpn(char *str){
    int i;
    int count;

    count = 0;
    i = 0;
    while(str[i]){
        if(is_number(str[i])){
            if(!is_space(str[i - 1]) && i != 0)
                return 0;
            count++;
            while(is_number(str[i]))
                i++;
        }else if(is_space(str[i])){
            while(is_space(str[i]))
                i++;
        }else if(is_operator(str[i])){
            if(count <= 1 || is_operator(str[i + 1]) || !is_space(str[i - 1]))
                return 0;
            count--;
            i++;
        }else
            return 0;
    }
    if(count == 1)
        return 1;
    else
        return 0;
}
int count_size_numbers(char *str){
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i]){
        if(is_number(str[i])){
            count++;
            while(is_number(str[i]))
                i++;
        }else if(is_space(str[i])){
            while(is_space(str[i]))
                i++;
        }else if(is_operator(str[i]))
            i++;
        else
            return 0;
    }
    return count;
}
int count_size_operators(char *str){
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i]){
        if(is_number(str[i])){
            while(is_number(str[i]))
                i++;
        }else if(is_space(str[i])){
            while(is_space(str[i]))
                i++;
        }else if(is_operator(str[i])){
            count++;
            i++;
        }else
            return 0;
    }
    return count;
}
int number_before_operator(char *str, int i){
    int count;

    count = 0;
    while(str[i]){
        if(is_number(str[i])){
            count++;
            while(is_number(str[i]))
                i++;
        }else if(is_space(str[i])){
            while(is_space(str[i]))
                i++;
        }else if(is_operator(str[i])){
            return count;
        }
    }
    return count;
}
int number_in_begin(char *str, int i){
    char *c_numbers;
    int tmp;
    int j;
    tmp = 0;
    j = 0;

    tmp = i;
    while(is_number(str[i]))
        i++;
    c_numbers = malloc(sizeof(char) * (i - tmp + 1));
    i = tmp;

    while(is_number(str[i]))
        c_numbers[j++] = str[i++];
    return atoi(c_numbers);
}
int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[++i]);
    return i;
}
int calculator(int *numbers, char *operators, char *str){
    int result;
    int i;

    i = 0;
    result = do_op(numbers[i], numbers[i + 1], operators[i]);
    i++;
    while(i != count_size_operators(str)){
        result = do_op(result, numbers[i + 1], operators[i]);
        i++;
    }
    return result;
}
void rpn_calc(char *str){
    int *numbers;
    char *operators;
    int i;
    int j;
    int k;
    int tmp;
    int tmp2;
    if(!check_rpn(str) || count_size_operators(str) == 0){
        printf("Error");
        return ;
    }
    tmp = 0;
    tmp2 = 0;
    i = 0;
    j = 0;
    k = 0;
    numbers = malloc(sizeof(int) * count_size_numbers(str));
    operators = malloc(sizeof(char) * count_size_operators(str) + 1);
    while(str[i]){
        if(is_number(str[i]) && number_before_operator(str, i) == 3){
            tmp = i;
            while(is_number(str[i]))
                i++;
            while(tmp2 != 2){
                while(is_space(str[i]))
                    i++;
                numbers[j++] = number_in_begin(str, i);
                while(is_number(str[i]))
                    i++;
                tmp2++;
            }
            numbers[j++] = number_in_begin(str, tmp);
        }else if(is_number(str[i])){
            numbers[j++] = number_in_begin(str, i);
            while(is_number(str[i]))
                i++;
        }else if(is_space(str[i])){
            while(is_space(str[i]))
                i++;
        }else if(is_operator(str[i]))
            operators[k++] = str[i++];
        else
            i++;
    }
    operators[k++] = '\0';
    printf("%d", calculator(numbers, operators, str));
}

int main(int ac, char **av){
    if(ac == 1)
        printf("Error");
    if(ac == 2)
        rpn_calc(av[1]);
    printf("\n");
}