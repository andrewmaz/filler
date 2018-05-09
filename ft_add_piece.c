/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 10:11:15 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/07 12:50:35 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	ft_src_in_col(char **arr, int size, int col)
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

int ft_manh_len(int *a, int x, int y)
{
	return (ABS(a[0] - x) + ABS(a[1] - y));
}

void ft_ret_last_coo(t_data *data, int *xy, char n)
{
	int i;
	int j;

	i = 0;
	while (i < data->size_map[0])
	{
		j = 0;
		while (j < data->size_map[1])
		{
			if (data->map[i][j] == n || data->map[i][j] == ft_toupper(n))
			{
				xy[0] = xy[0] == -1 ? i : xy[0];
				xy[2] = j < xy[2] || xy[2] == -1 ? j : xy[2];
				xy[1] = i;
				xy[3] = j > xy[3] ? j : xy[3];
			}
			j++;
		}
		i++;
	}
}

int ft_valid_build(t_data *data, int x, int y)
{
	int i;
	int j;
	int ny;
	int o;

	i = data->xp[0];
	o = 0;
	while (i <= data->xp[1] && x < data->size_map[0])
	{
		j = data->yp[0];
		ny = y;
		while (j <= data->yp[1] && ny < data->size_map[1])
		{
			if (data->map[x][ny++] == '.' || data->piece[i][j] == '.')
				j++;
			else
			{
				if(o || (data->map[x][ny - 1] != data->msym && \
					data->map[x][ny - 1] != ft_toupper(data->msym)))
					return (0);
				o++;
				j++;
			}
		}
		if (j <= data->yp[1])
			return (0);
		i++;
		x++;
	}
	if (i <= data->xp[1])
		return (0);
	return (o);
}

int ft_min_len(int *a, int *nxy)
{
	int len;
	int tmp;
	int i;
	int j;

	i = 0;
	len = -1;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			tmp = ft_manh_len(a, nxy[i], nxy[j]);
			len = (len == -1 || tmp < len ? tmp : len);
			j++;
		}
		i++;
	}
	return (len);
}

void ft_build(t_data *data, int *nxy)
{
	int i;
	int j;
	int xy[2];
	int len1;
	int len2;

	i = 0;
	xy[0] = -1;
	xy[1] = -1;
	len2 = -1;
	while (i < data->size_map[0])
	{
		j = 0;
		while (j < data->size_map[1])
		{
			if(ft_valid_build(data, i, j))
			{
				len1 = ft_min_len(xy, nxy);
				if (len2 == -1 || len2 > len1)
				{
					xy[0] = i;
					xy[1] = j;
				}
				len2 = len1;
			}
			j++;
		}
		i++;
	}
	if (xy[0] == -1)
		exit(1);
	else
		ft_printf("%d %d\n", xy[0] - data->xp[0], xy[1] - data->yp[0]);
}

void ft_add_piece_coor(t_data *data)
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

int ft_add_piece(t_data *data)
{
	int nxy[4];

	nxy[0] = -1;
	nxy[1] = -1;
	nxy[2] = -1;
	nxy[3] = -1;
	data->xp[0] = 0;
	data->xp[1] = 0;
	data->yp[0] = 0;
	data->yp[1] = 0;
	ft_ret_last_coo(data, nxy, data->nsym);
	ft_add_piece_coor(data);
	//int t = ft_valid_build(data, 2, 2);
	ft_build(data, nxy);
	return (1);
}