/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:57:24 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/20 11:57:27 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Bresenham Algorithm for tracing a line.
*/

// void 	bresenham(t_env env)
// {
// 	int delta_x;
// 	int delta_y;
// 	int incrx;
// 	int incry;
// 	incrx = (x2 - x1) ? 1 : -1;
// 	incry = (y2 - y1) ? 1 : -1;


// 	delta_x = abs(x2 - x1);
// 	delta_y = abs(y2 - y1);


// }

void	draw(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->southmax)
	{
		while (j < env->eastmax[i])
		{
			mlx_pixel_put(env->mlx, env->win, (350 +(j - i) * env->linesizey), (350 +(j + i) * env->linesizex) , env->color);
			j++;
		}
		i++;
		j = 0;
	}
}

// void 	pixels(t_env env, int decider)
// {
// 	if (decider == 0)
// 	{

// 	}
// 	else
// 	{

// 	}
// 	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
// }


/*
**	Events
*/

int 	key_pressed(int keycode, t_env *env)
{
	if (keycode == 53) // quit
		exit(0);
	if (keycode == 126) // up
	{ 
		//mlx_clear_window(env->mlx, env->win);
		env->z++;
		printf("UP key : Zoom in. || Z new value : %d\n", env->z);
	}
	if (keycode == 125) // down
	{
		//mlx_clear_window(env.mlx, env.win);
		env->z--;
		printf("DOWN key : Zoom out. || Z new value : %d\n", env->z);
	}
	if (keycode == 11)
	{
		env->color = 0x0000FF;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
		printf("New color : BLUE");
	}
	if (keycode == 15)
	{
		env->color = 0xFF0000;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
		printf("New color : RED");
	}
	printf("keycode : %d\n", keycode);
	return (0);
}
