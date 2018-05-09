/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:22:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/07 12:54:32 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main(void)
{
	t_data	*data;
	int 	b;

	data = ft_new_data();
	//data->fd = open("../1", O_RDONLY);
	ft_read_name_size(data);
	b = 1;
	while (b)
	{
		ft_read_map_piece(data);
		b = ft_add_piece(data);
	}

}
