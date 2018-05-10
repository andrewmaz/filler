/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:23:34 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/10 14:29:41 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_delmap(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_strdel(&str[i++]);
	free(str);
}

void	ft_del_data(t_data *data)
{
	ft_delmap(data->map, data->size_map[0]);
	ft_delmap(data->piece, data->size_piece[0]);
	free(data);
}