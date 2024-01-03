int ft_str_is_printable(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!(str[i] >= ' ' && str[i] <= '~'))
            return 0;
        i++;
    }
    return 1;
}