/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_best_coor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:19:44 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/10 15:49:19 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_around(int x, int y, int r, t_data *data)
{
	int i;
	int j;

	i = -r;
	while (i <= r)
	{
		j = -r;
		while (j <= r)
		{
			if (x + i > 0 && x + i < data->size_map[0] && \
				y + j > 0 && y + j < data->size_map[1] && \
				(data->map[x + i][y + j] == data->nsym || \
				data->map[x + i][y + j] == ft_toupper(data->nsym)))
				return (r);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_first_op(int i, int j, t_data *data)
{
	int res;
	int r;

	r = 1;
	while (!(res = ft_around(i, j, r, data)))
		r++;
	return (res);
}
