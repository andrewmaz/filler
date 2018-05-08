/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:46:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/07 12:41:10 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdio.h>
#include <fcntl.h>
#include "libftprintf/libft/libft.h"

#define ABS(x) (x < 0)?-x:x;

typedef struct	s_data
{
  int	fd;
  char	msym;
  char	nsym;
  int	size_map[2];
  char	**map;
  int 	size_piece[2];
  char	**piece;
}				t_data;

t_data			*ft_new_data(void);

void			ft_read_name_size(t_data *data);
void			ft_read_map_piece(t_data *data);
int ft_add_piece(t_data *data);

#endif
