/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:10:03 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 23:19:34 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_space(char *buf);
int				ft_check_number(char *str);
char			*ft_dictionnaire(char *dict);
typedef struct	s_dict
{
	char		*nb_in_alpha;
	int			nb_in_int;
}				t_dict;
#endif
