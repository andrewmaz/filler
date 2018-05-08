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

int ft_manh_len(int *a, int x, int y)
{
	int i;
	int j;

	i = a[0] - x;
	i = i < 0 ? -i : i;
	j = a[1] - y;
	j = j < 0 ? -j : j;
	return (i + j);
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
				xy[2] = xy[2] == -1 ? j : xy[2];
				xy[1] = i;
				xy[3] = j < xy[3] || xy[3] == -1 ? j : xy[3];
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

	i = 0;
	o = 0;
	while (i < data->size_piece[0] && x < data->size_map[0])
	{
		j = 0;
		ny = y;
		while (j < data->size_piece[1] && ny < data->size_map[1])
		{
			//ft_printf("%c\n", data->map[x][ny]);
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
		if (j < data->size_piece[1])
			return (0);
		i++;
		x++;
	}
	if (i < data->size_piece[0])
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
	ft_printf("%d %d\n", xy[0], xy[1]);
}

int ft_add_piece(t_data *data)
{
	int nxy[4];

	nxy[0] = -1;
	nxy[1] = -1;
	nxy[2] = -1;
	nxy[3] = -1;
	ft_ret_last_coo(data, nxy, data->nsym);
	//int t = ft_valid_build(data, 2, 2);
	ft_build(data, nxy);
	return (1);
}