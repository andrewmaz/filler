/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 10:11:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/10 15:49:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_src_in_col(char **arr, int size, int col)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i][col] == '*')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_valid_build(t_data *data, int x, int y)
{
	int i;
	int j;
	int ny;
	int o;

	ft_set_val(&i, &o, data->xp[0], 0);
	while (i <= data->xp[1] && x < data->size_map[0])
	{
		ft_set_val(&j, &ny, data->yp[0], y);
		while (j <= data->yp[1] && ny < data->size_map[1])
			if (data->map[x][ny++] == '.' || data->piece[i][j] == '.')
				j++;
			else
			{
				if (o || (data->map[x][ny - 1] != data->msym && \
					data->map[x][ny - 1] != ft_toupper(data->msym)))
					return (0);
				ft_set_val(&o, &j, o + 1, j + 1);
			}
		if (j <= data->yp[1])
			return (0);
		ft_set_val(&i, &x, i + 1, x + 1);
	}
	return (i <= data->xp[1] ? 0 : o);
}

static void	ft_build(t_data *data, int len2, int i)
{
	int j;
	int xy[2];
	int len1;

	ft_set_val(&xy[0], &xy[1], -1, -1);
	while (i < data->size_map[0])
	{
		j = 0;
		while (j < data->size_map[1])
		{
			if (ft_valid_build(data, i, j))
			{
				len1 = ft_first_op(i, j, data);
				if (len2 == -1 || len1 < len2)
				{
					ft_set_val(&xy[0], &xy[1], i, j);
					len2 = len1;
				}
			}
			j++;
		}
		i++;
	}
	(xy[0] == -1) ? ft_error(data) : \
				ft_printf("%d %d\n", xy[0] - data->xp[0], xy[1] - data->yp[0]);
}

static void	ft_add_piece_coor(t_data *data)
{
	while (!ft_strstr(data->piece[data->xp[0]], "*"))
		data->xp[0]++;
	data->xp[1] = data->size_piece[0] - 1;
	while (!ft_strstr(data->piece[data->xp[1]], "*"))
		data->xp[1]--;
	while (!ft_src_in_col(data->piece, data->size_piece[0], data->yp[0]))
		data->yp[0]++;
	data->yp[1] = data->size_piece[1] - 1;
	while (!ft_src_in_col(data->piece, data->size_piece[0], data->yp[1]))
		data->yp[1]--;
}

int			ft_add_piece(t_data *data)
{
	data->xp[0] = 0;
	data->xp[1] = 0;
	data->yp[0] = 0;
	data->yp[1] = 0;
	ft_add_piece_coor(data);
	ft_build(data, -1, 0);
	return (1);
}
