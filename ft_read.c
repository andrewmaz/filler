/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 09:10:01 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/07 12:42:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char 	**ft_dstrnew(int size)
{
	char	**new;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	return (new);
}

void	ft_read_name_size(t_data *data)
{
	char	*str;
	char	**dstr;

	while (!data->msym && get_next_line(data->fd, &str))
	{
		if (ft_strstr(str, "amazurok.filler"))
		{
			data->msym = (ft_atoi(ft_strstr(str, "p") + 1) == 1 ? 'o' : 'x');
			data->nsym = (data->msym == 'x' ? 'o' : 'x');
		}
		ft_strdel(&str);
	}
	while (!data->size_map[0] && get_next_line(data->fd, &str))
	{
		if (ft_strstr(str, "Plateau"))
		{
			dstr = ft_strsplit(str, ' ');
			data->size_map[0] = (int)ft_atoi(dstr[1]);
			data->size_map[1] = (int)ft_atoi(dstr[2]);
			ft_dstrdel(&dstr);
		}
		ft_strdel(&str);
	}
}

void	ft_read_map_piece(t_data *data)
{
	int i;
	char *str;
	char **dstr;

	i = 0;
	if (data->map && *data->map)
		ft_dstrdel(&data->map);
	data->map = ft_dstrnew(data->size_map[0]);
	while (i < data->size_map[0] && get_next_line(data->fd, &str))
	{
		if (ft_isdigit(str[0]))
			data->map[i++] = ft_strdup(str + 4);
		ft_strdel(&str);
	}
	get_next_line(data->fd, &str);
	dstr = ft_strsplit(str, ' ');
	data->size_piece[0] = str ? (int)ft_atoi(dstr[1]) : 0;
	data->size_piece[1] = str ? (int)ft_atoi(dstr[2]) : 0;
	ft_strdel(&str);
	ft_dstrdel(&dstr);
	i = 0;
	if (data->piece && *data->piece)
		ft_dstrdel(&data->piece);
	data->piece = ft_dstrnew(data->size_piece[0]);
	while (i < data->size_piece[0])
		get_next_line(data->fd, &data->piece[i++]);
	//ft_mod_piece(data);
}