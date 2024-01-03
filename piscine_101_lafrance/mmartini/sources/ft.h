/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 20:55:01 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 20:58:56 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_H
#define _FT_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct s_information
{
	int hauteur;
	int largeur;
	char emptycase;
	char obstacle;
	char fill;
	int end;
}		t_information;
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int n);
void ft_show_tab(struct s_information *tab);
struct s_information *ft_open_to_struct(char *buf);
int ft_verif_one_case(char *str);
char *ft_open(void);

#endif

