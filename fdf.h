/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:09:19 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 18:09:21 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_coord
{
	int x;
	int y;
	int z;
}			   t_coord;

void		draw_line(int x1, int x2, int dy1, int dy2, void *mlx, void *win);
int			error(void);
int			usage(void);
t_coord		**work_coords(int fd, t_coord **coords);
t_coord		*assign_all_coords(char *line, int north);
int 	ft_tablen(char **tab);
void	print_coords(t_coord **coords);
//void	print_coords(t_coord **coords)

#endif
