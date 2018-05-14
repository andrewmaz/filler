/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:34:32 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/12 17:02:01 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_help(void)
{
	ft_printf("______________________HELP_______________________\n");
	ft_printf("|     usage: ./my_visual_am [keys] < input      |\n");
	ft_printf("|                      Keys:                    |\n");
	ft_printf("| %-26s %-19s|\n", "-h", "<help>");
	ft_printf("| %-26s %-19s|\n", "-p", "<show piece>");
	ft_printf("| %-26s %-19s|\n", "-cl", "<clear console>");
	ft_printf("| %-26s %-19s|\n", "-p1 [char sym]", "<set symbol for p1>");
	ft_printf("| %-26s %-19s|\n", "-p2 [char sym]", "<set symbol for p2>");
	ft_printf("| %-26s %-19s|\n", "-t  [time in milliseconds]", "<pause time>");
	ft_printf("| %-26s %-19s|\n", "-c", "<colour mod>");
	ft_printf("| %-26s {green}%-19s{eoc}|\n", "", "<The first player>");
	ft_printf("| %-26s {red}%-19s{eoc}|\n", "", "<The second player>");
	ft_printf("| %-26s {blue}%-19s{eoc}|\n", "", "<Last change>");
	ft_printf("|_______________________________________________|\n");
}
