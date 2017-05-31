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
	int  			linesizex;
	int  			linesizey;
	int 			southmax;
	int 			*eastmax;
	unsigned long 	color;
	int 			**tab;
	int 			x1;
	int 			x2;
	int 			y1;
	int 			y2;
	int 			dx;
	int 			dy;
	int 			incrx;
	int 			incry;
}			   		t_env;

int			error(void);
int			usage(void);
t_env		work_coords(int fd, t_env *env);
int			*assign_all_coords(char *line);
void 		ft_map(t_env *env);
void		draw(t_env *env);
int 		false_tab(char **tab);
t_env 		init_map(t_env *env);
int 		key_pressed(int keycode, t_env *env);
int 		exiterror(void);
void 		debugcoords(t_env env);
int 		tablen(char **tab);

#endif
