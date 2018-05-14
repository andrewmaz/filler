/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:12:25 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/14 09:44:37 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_VISUAL_H
# define VISU_VISUAL_H

# include "../libftprintf/libft/libft.h"

typedef struct	s_kkey
{
	int		t;
	wchar_t	p1;
	wchar_t	p2;
	int		c;
	int		h;
	int		p;
	int		cl;
}				t_kkey;

void			ft_help(void);
t_kkey			*ft_new_c_key(void);
int				ft_read_key(int c, char **v, t_kkey *key);
void			ft_print_result(char *str, t_kkey *key);
void			ft_print_players(char *str, t_kkey *key);
void			ft_print_map(char *str, t_kkey *key);
void			ft_visual(t_kkey *key);
char			*ft_print_piece(char *str);

#endif
