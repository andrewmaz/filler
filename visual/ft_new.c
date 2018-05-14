/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:46:38 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/12 15:22:28 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_kkey	*ft_new_c_key(void)
{
	t_kkey *key;

	key = (t_kkey*)malloc(sizeof(t_kkey));
	key->p1 = L'➊';
	key->p2 = L'➋';
	key->c = 0;
	key->t = 0;
	key->h = 0;
	key->p = 0;
	key->cl = 0;
	return (key);
}
