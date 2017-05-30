/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:07:08 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 18:07:10 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Error case
*/

int 	exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

/*
**	Usage	
*/

int		usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
	return (-1);
}

/*
**	Gives number of elements in a table of string.
*/

int 	tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
