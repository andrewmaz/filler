/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 08:54:36 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/07 09:34:04 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_data	*ft_new_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->msym = '\0';
	data->nsym = '\0';
	data->size_map[0] = 0;
	data->size_map[1] = 0;
	data->map = NULL;
	data->size_piece[0] = 0;
	data->size_piece[1] = 0;
	data->piece = NULL;
	data->fd = 0;
	data->xp[0] = 0;
	data->xp[1] = 0;
	data->yp[0] = 0;
	data->yp[1] = 0;
	return (data);
}