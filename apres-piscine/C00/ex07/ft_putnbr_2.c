#include <unistd.h>

int sizeInt(int nbr)
{
    int nb = nbr;
    int size = 1;
    while (nb >= 10)
    {
        nb = nb / 10;
        size++;
    }
    return size;
}

int taille_10_Int(int size)
{
    int i = 0;
    int taille = 1;
    while (i != size - 1)
    {
        taille = taille * 10;
        i++;
    }
    return taille;
}

int reverse_number(int nbr, int taille)
{
    int nb = 0;
    while (nbr > 10)
    {
        nb = nb + (nbr % 10) * taille ;
        nbr = nbr / 10;
        if (taille >= 10)
            taille = taille / 10;
    }
    nb = nb + (nbr % 10);
    return nb;
}
void ft_putnbr(int nbr)
{
    int nb;
    int size;
    char i;
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr = nbr * -1;
    }
    size = sizeInt(nbr);
    nb = reverse_number(nbr, taille_10_Int(size));
    while (nb > 10)
    {
        i = nb % 10 + 48;
        write(1, &i, 1);
        nb = nb / 10;
    }
    i = nb % 10 + 48;
    write(1, &i, 1);
}