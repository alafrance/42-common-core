
int is_whitespace(char c){
    if(c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

int is_valid(char c, int base){
    char valid[17] = "0123456789abcdef";
    char valid_maj[17] = "0123456789ABCDEF";
    while (base--){
        if (valid[base] == c || valid_maj[base] == c)
            return 1;
    }
    return 0;
}

int convert_char_to_int(char c){
    if (c >= '0' && c <= '9')
        return c - 48;
    else if(c >= 'a' && c <= 'f')
        return c - 'a' - 10;
    else if(c >= 'A' && c <= 'F')
        return c - 'A' - 10;
    return 0;
}


int ft_atoi_base(char *str, int base){
    int i = 0;
    int sign = 1;
    int atoi = 0;
    while(is_whitespace(str[i++]));
    i--;
    if (str[i] == '+' || str[i] == '-'){
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i]){
        if (is_valid(str[i], base))
            atoi = atoi * base + convert_char_to_int(str[i]);
        i++;
    }
    return atoi * sign;
}
