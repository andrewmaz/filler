/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:10:28 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/12 16:21:59 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "visual.h"

int		main(int argc, char **argv)
{
	t_kkey *key;
	setlocale(LC_ALL, "");

	key = ft_new_c_key();
	ft_read_key(argc, argv, key);
	if (key->h)
	{
		ft_help();
		free(key);
		return (0);
	}
	key->t = !key->t && key->cl ? 150 : key->t;
	ft_visual(key);
	free(key);
}