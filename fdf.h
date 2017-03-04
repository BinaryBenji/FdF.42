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

typedef struct s_coord
{
	int x;
	int y;
	int value;
	int index;
}			   t_coord;

void		draw_line(int x1, int x2, int dy1, int dy2, void *mlx, void *win);
void		error(void);
void		usage(void);
t_coord		**work_coords(char *path, t_coord **coords);
t_coord		*assign_all_coords(char **line, t_coord **coords, int north);
t_coord		assign_one_coord(char *tmp, t_coord coord, int east, int i);

#endif
