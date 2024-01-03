/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 16:37:59 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 20:26:54 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int o;
	int j;

	o = 0;
	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[o] != '\0')
	{
		if (to_find[i] == str[o])
			i++;
		if (to_find[i] == '\0')
			return(&str[i]);
		else
			i = 0;	
		o++;	
	}
}

int main()
{
	char src[] = "
}
