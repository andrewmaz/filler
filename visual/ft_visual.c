/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:22:01 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/14 09:26:55 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_set_players(char **p1, char **p2)
{
	char *str;

	*p1 = NULL;
	*p2 = NULL;
	while ((!*p1 || !*p2) && get_next_line(0, &str))
	{
		if (str[0] == '$')
		{
			if (str[10] == '1')
				*p1 = str;
			else
				*p2 = str;
		}
		else
			ft_strdel(&str);
	}
}

char	*ft_map(t_kkey *key, char *p1, char *p2)
{
	int		k;
	char	*str;

	k = 0;
	while (get_next_line(0, &str) && str[0] != '=')
	{
		if (!k++)
		{
			ft_print_players(p1, key);
			ft_print_players(p2, key);
		}
		if (ft_isdigit(str[0]))
			ft_print_map(str, key);
		else if (str[0] == '<')
		{
			usleep((useconds_t)key->t * 1000);
			key->cl ? system("clear") : 0;
			k = 0;
		}
		else if (ft_strstr(str, "Piece"))
			str = key->p ? ft_print_piece(str) : str;
		ft_strdel(&str);
	}
	return (str);
}

void	ft_visual(t_kkey *key)
{
	char *p1;
	char *p2;
	char *str;

	key->cl ? system("clear") : 0;
	ft_set_players(&p1, &p2);
	str = ft_map(key, p1, p2);
	ft_print_result(str, key);
	ft_strdel(&p1);
	ft_strdel(&p2);
}
