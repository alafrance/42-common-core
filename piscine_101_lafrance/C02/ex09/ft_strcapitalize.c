/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 19:17:00 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/11 10:49:29 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

void	first_strupcase(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strupcase(str);
	first_strupcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] >= ' ' && str[i] <= '/') || (str[i] >= '[' && str[i] <= '`')
			|| (str[i] >= '{' && str[i] <= '~')
				|| (str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
					|| (str[i] == '\n' || str[i] == '\v'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
			}
			i++;
		}
		else
		{
			i++;
		}
	}
	return (str);
}
