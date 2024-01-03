#include <unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}
void ft_putstr(char *str){
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
}

int is_whitespace(char c){
    return (c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0;
}
int ft_strlen(char *str){
	int i;

	i = 0;
	while(str[++i]);
	return i;
}
int ft_atoi(char *str){
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	while(is_whitespace(str[i]))
		i++;
	while(str[i] == '-' || str[i] == '+'){
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9'){
		nb = nb * 10 + str[i] - 48; 
		i++;
	}
	return nb * sign;
}
void ft_putnbr(int nb)
{
    long nbr;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb *= -1;
    }
    nbr = nb;
    if (nbr >= 10)
    {
        nbr = nbr / 10;
        ft_putnbr(nbr);
    }
    nb = nb % 10 + 48;
    write(1, &nb, 1);
}
int is_valid_operator(char *op){
	return ((ft_strlen(op) == 1) &&
		(op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/' || op[0] == '%')) ? 1 : 0;
}

void do_op(int nb, int nb2, char *operator){
	int nbr;
	nbr = 0;
	if(is_valid_operator(operator)){
		switch(operator[0]){
			case '+':
				nbr = nb + nb2;
				break;
			case '-':
				nbr = nb - nb2;
				break;
			case '*':
				nbr = nb * nb2;
				break;
			case '/':
				if(nb2 == 0)
					ft_putstr("Stop : division by zero");
				else
					nbr = nb - nb2;
				break;
			case '%':
				if(nb2 == 0)
					ft_putstr("Stop : modulo by zero");
				else
					nbr = nb - nb2;
				break;
		}
	}
	(nb2 == 0 && (operator[0] == '/' || operator[0] == '%')) ? 0 : ft_putnbr(nbr) ;
	ft_putchar('\n');
}
int main(int ac, char **av){
	if(ac == 4)
		do_op(ft_atoi(av[1]), ft_atoi(av[3]), av[2]);
}
