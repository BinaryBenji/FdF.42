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
#include <mlx.h>

typedef struct 		s_env
{
	void 			*mlx;
	void 			*win;
	int	 			width;
	int	 			height;
	int  			decalx;
	int  			decaly;
	int  			linesizex;
	int  			linesizey;
	int  			**tab;
	int 			southmax;
	int 			eastmax;
	unsigned long 	color;
}			   		t_env;

void		draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);
int			error(void);
int			usage(void);
t_env		work_coords(int fd, t_env env);
int 		*assign_all_coords(char *line, t_env env);
int 		ft_tablen_str(char **tab);
//void		print_coords(t_env **coords);
void		ft_map(t_env env);
int 		false_tab(char **tab);
t_env 		init_map(t_env env);
int 		key_pressed(int keycode, t_env env);
int 		exiterror(void);

#endif
