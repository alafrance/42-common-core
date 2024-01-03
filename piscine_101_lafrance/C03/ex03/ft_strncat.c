/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 15:25:23 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 21:53:24 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int i;
	int o;

	i = 0;
	o = 0;
	while (dest[o] != '\0')
	{
		o++;
	}
	while (i < n)
	{
		dest[o] = src[i];
		o++;
		i++;
	}
	return (dest);
}

int main()
{
	char dest[] = "salut";
	char src[] = "mec ";
	printf("%s", ft_strncat(dest, src, 2));
	printf("%s", strncat(dest, src, 2));

}
