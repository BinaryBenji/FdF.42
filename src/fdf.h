/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:09:19 by bzmuda            #+#    #+#             */
/*   Updated: 2017/05/28 16:56:54 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"

typedef struct 		s_env
{
	void 			*mlx;
	void 			*win;
	int 			z;
	int	 			width;
	int	 			height;
	int  			decalx;
	int  			decaly;
	int  			linesizex;
	int  			linesizey;
	int 			southmax;
	int 			eastmax;
	unsigned long 	color;
}			   		t_env;

typedef struct 		s_coords
{
	int 			**tab;
}					t_coords;

void		draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);
int			error(void);
int			usage(void);
t_coords	work_coords(int fd, t_coords coords);
int			*assign_all_coords(char *line, t_coords coords);
int 		ft_tablen_str(char **tab);
void 		ft_map(t_env env);
int 		false_tab(char **tab);
t_env 		init_map(t_env env);
int 		key_pressed(int keycode, t_env env);
int 		exiterror(void);
void 		debugcoords(t_env env);
int 		tablen(char **tab);

#endif
