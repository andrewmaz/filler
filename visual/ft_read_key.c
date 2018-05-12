/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/12 15:22:28 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		ft_set_key(t_kkey *key, int i, char **v, int c)
{
	if (v[i][1] == 'p' && v[i][2] == '1' && i + 1 < c)
		key->p1 = (wchar_t)v[++i][0];
	else if (v[i][1] == 'p' && v[i][2] == '2' && i + 1 < c)
		key->p2 = v[++i][0];
	else if (v[i][1] == 't' && i + 1 < c)
		key->t = (int)ft_atoi(v[++i]);
	else if (v[i][1] == 'c' && v[i][2] != 'l')
		key->c = 1;
	else if (v[i][1] == 'h')
		key->h = 1;
	else if (v[i][1] == 'c' && v[i][2] == 'l')
		key->cl = 1;
	else
	{
		free(key);
		ft_help();
		exit(6);
	}
	return (i);
}

int		ft_read_key(int c, char **v, t_kkey *key)
{
	int i;

	i = 1;
	while (v[i])
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			i = ft_set_key(key, i, v, c);
		else
			break ;
		i++;
	}
	return (i - 1);
}
