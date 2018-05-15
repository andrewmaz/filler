/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:17:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/15 09:58:06 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_print_map(char *str, t_kkey *key)
{
	int i;

	i = 3;
	while (str[i])
	{
		if (str[i] == 'O')
			key->c ? ft_printf("{green}%lc{eoc}", key->p1) : \
					ft_printf("%lc", key->p1);
		else if (str[i] == 'o')
			key->c ? ft_printf("{blue}%lc{eoc}", key->p1) : \
					ft_printf("%lc", key->p1);
		else if (str[i] == 'x')
			key->c ? ft_printf("{blue}%lc{eoc}", key->p2) : \
					ft_printf("%lc", key->p2);
		else if (str[i] == 'X')
			key->c ? ft_printf("{red}%lc{eoc}", key->p2) : \
					ft_printf("%lc", key->p2);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_players(char *str, t_kkey *key)
{
	char	**dstr;
	int		i;
	int		p;

	i = 0;
	if (!str)
		return ;
	dstr = ft_strsplit(str, ' ');
	p = (int)ft_atoi(dstr[2] + 1);
	while (dstr[i])
	{
		if (dstr[i][0] != '[')
			ft_printf("%s ", dstr[i]);
		else
		{
			if (p == 1)
				key->c ? ft_printf("{green}%s{eoc}\n", dstr[i]) : 0;
			else
				key->c ? ft_printf("{red}%s{eoc}\n", dstr[i]) : 0;
			!key->c ? ft_printf("%s\n", dstr[i]) : 0;
		}
		i++;
	}
	ft_dstrdel(&dstr);
}

void	ft_print_result(char *str, t_kkey *key)
{
	int p1;
	int p2;

	p1 = str ? (int)ft_atoi(str + 9) : 0;
	key->c ? ft_printf("{green}") : 0;
	ft_printf("Player %lc set %d blocks\n", key->p1, p1);
	ft_strdel(&str);
	get_next_line(0, &str);
	p2 = str ? (int)ft_atoi(str + 9) : 0;
	key->c ? ft_printf("{red}") : 0;
	ft_printf("Player %lc set %d blocks\n", key->p2, p2);
	if (p1 != p2)
	{
		key->c ? ft_printf("{green}") : 0;
		ft_printf("\nThe %s player(%lc) has won!!!\n", p1 > p2 ? "first" : \
		"second", p1 > p2 ? key->p1 : key->p2);
	}
	else
	{
		key->c ? ft_printf("{red}") : 0;
		ft_printf("\nNobody has won :(\n");
	}
	ft_printf("{eoc}");
	ft_strdel(&str);
}

char	*ft_print_piece(char *str)
{
	int size;
	int i;

	i = 0;
	ft_printf("%s\n", str);
	size = ft_atoi(str + 5);
	ft_strdel(&str);
	while (i < size && get_next_line(0, &str))
	{
		ft_printf("%s\n", str);
		ft_strdel(&str);
		i++;
	}
	return (NULL);
}
