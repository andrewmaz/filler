/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:46:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/10 14:33:45 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdio.h>
#include <fcntl.h>
#include "libftprintf/libft/libft.h"

typedef struct	s_data
{
  int	fd;
  char	msym;
  char	nsym;
  int	size_map[2];
  char	**map;
  int 	size_piece[2];
  char	**piece;
  int 	xp[2];
  int   yp[2];
}				t_data;

t_data			*ft_new_data(void);
void			ft_read_name_size(t_data *data);
void			ft_read_map_piece(t_data *data);
int 			ft_add_piece(t_data *data);
int 			ft_src_in_col(char **arr, int size, int col);
int				ft_first_op(int i, int j, t_data *data);
void			ft_set_val(int *a, int *b, int an, int bn);
void			ft_delmap(char **str, int size);
void			ft_del_data(t_data *data);
void 			ft_error(t_data *data);

#endif
