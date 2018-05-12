/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:22:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/10 15:49:59 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_data	*data;

	data = ft_new_data();
	ft_read_name_size(data);
	while (TRUE)
	{
		ft_read_map_piece(data);
		ft_add_piece(data);
	}
	ft_del_data(data);
}
