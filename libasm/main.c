/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:14:16 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/27 08:32:36 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_header(char *filename)
{
	int	count;
	int i;
	int j;

	j = 0;
	count = 20 - ft_strlen(filename) - 2;

	printf("|*----------------*|\n|");
	while (j != 2)
	{
		i = 0;
		while (i != count / 2)
		{
			printf("-");
			i++;
		}
		if (j == 0)
			printf("%s", filename);
		j++;
	}
	printf("|\n|*----------------*|\n\n");
}

void	ft_test_read(char *filename, int nbytes)
{
	int		errno;
	char	str[nbytes];
	int	fd;

	errno = 0;
	ft_header("read");
	fd = open(filename, O_RDONLY);
	ft_read(fd, str, nbytes);
	dprintf(1, "read without error: %s\n", str);
	ft_read(-1, str, nbytes);
	dprintf(1, "fd: -1, errno = %s\n", strerror(errno));
	ft_read(fd, str, -1);
	dprintf(1, "nbytes: -1, errno = %s\n", strerror(errno));
	close(fd);
}

void	ft_test_write(char *filename,int nbytes)
{
	int		errno;
	char	str[100] = "coucou hello\n";
	int		fd;
	int		r_wr;


	ft_header("write-");
	if	(nbytes > 100)
		return ;
	errno = 0;
	fd = open(filename, O_WRONLY);
	r_wr = ft_write(-1, "test", -1);
	if (r_wr == -1)
		dprintf(1, "We write nothing, error errno: %s\n", strerror(errno));
	else
		dprintf(1, "Not a error. We write: %d, good !\n", r_wr);
	r_wr = ft_write(fd, str, 10);
	if (r_wr == -1)
		dprintf(1, "We write nothing, error errno: %s\n", strerror(errno));
	else
		dprintf(1, "Not a error. We write: %d, good !\n", r_wr);
}

void	ft_test_strcmp()
{
	char	str_1[100] = "Qui fait du zele? brice !";
	char	str_2[100] = "Qui fait du zele? alexis !";
	ft_header("strcmp");
	dprintf(1, "my strcmp return : %d\n", ft_strcmp(str_1, str_2));
	dprintf(1, "the strcmp return : %d\n", strcmp(str_1, str_2));
	
}

void	ft_test_strcpy()
{
	char str_1[100] = "Coucou les amis c david";
	char str_2[100] = "Salut les amis c'est jo";

	ft_header("strcpy");	
	dprintf(1, "Before cpy : str_1: %s, str_2: %s\n", str_1, str_2);
	dprintf(1, "return cpy: %s\n", ft_strcpy(str_1, str_2));
	dprintf(1, "After cpy : str_1: %s, str_2: %s\n", str_1, str_2);
}

void	ft_test_strdup()
{
	char *str;

	ft_header("strdup");
	str = ft_strdup("je vais etre duplique OUEEEEE");
	dprintf(1, "the string is : %s NOT NULL GOOD !", str);
	free(str);
}

void	ft_test_strlen()
{
	char str[100] = "Coucou c'est david ! Oui la reponse est oui";

	ft_header("strlen");
	dprintf(1, "my ft_strlen return : %lu, the real function : %lu\n", ft_strlen(str), strlen(str));

}

int main()
{
	int errno;
	int choice;
	char c = 'y';

	choice = 0;
	while (c == 'y')
	{
		system("clear");
		dprintf(1, "What do you want ?\n");
		dprintf(1, "1 - Read\n");
		dprintf(1, "2 - Write\n");
		dprintf(1, "3 - Strcmp\n");
		dprintf(1, "4 - Strcpy\n");
		dprintf(1, "5 - Strdup\n");
		dprintf(1, "6 - Strlen\n");
		scanf("%d", &choice);
		system("clear");
		switch (choice)
		{
			case 1:
				ft_test_read("test.txt", 20);
				break;
			case 2:
				ft_test_write("empty.txt", 12);
				break;
			case 3:
				ft_test_strcmp();
				break;
			case 4:
				ft_test_strcpy();
				break;
			case 5:
				ft_test_strdup();
				break;
			case 6:
				ft_test_strlen();
				break;
			default:
				dprintf(1, "Error sorry dude :\n");
				break;
		}
		dprintf(1, "\nTry again ? y / n : ");
		scanf("%s", &c);
	}
}