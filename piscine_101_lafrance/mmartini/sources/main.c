/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 20:54:44 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 18:42:13 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"


void ft_error()
{
	write(1, "map error", 1);
}
int		main()
{
	t_information  *tab;
	if (ft_open() == NULL)
	{
		ft_error();
		return(1);
	}
//	if (ft_verif_one_case())
//	{
//		ft_error();
//		return(1);
//	}
	tab = ft_open_to_struct(ft_open());
	ft_show_tab(tab);
	return (0);
}
