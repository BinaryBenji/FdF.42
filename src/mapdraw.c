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

void	draw(t_env *env)
{
	draw_all_x(env);
	draw_all_y(env);
	/*int i = 0;
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
	}*/
}

/*
**	Positive case (dx > dy)
*/

void	positive(t_env *env)
{
	int err;
	int i;

	i = 0;
	err = env->dx/2;
	while (i < env->dx)
	{
		env->x1 += incrx;
		if (err > dx)
		{
			err -= env->dx;
			env->y1 += incry;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1 , env->color);
		i++;
	}
}

/*
**	Negative case (dx < dy)
*/

void	negative(t_env *env)
{
	int err;
	int i;

	i = 0;
	err = env->dy/2;
	while (i < env->dy)
	{
		env->y1 += incry;
		if (err > dy)
		{
			err -= env->dy;
			env->x1 += incrx;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1 , env->color);
		i++;
	}
}


/*
**	Bresenham Algorithm
**	Define values of incr, in order to obtain direction coefficients.
**	Then draw in function of results.
*/

void 	pixels(t_env *env)
{
	env->incrx = (env->x2 > env->x1) ? 1 : -1;
	env->incry = (env->y2 > env->y1) ? 1 : -1;
	env->dx = abs(env->x2 - env->x1);
	env->dy = abs(env->y2 - env->y1);
	if (env->dx > env->dy)
	{
		positive(env);
	}
	else
	{
		negative(env);
	}
	mlx_pixel_put(env->mlx, env->win, env->x1, env->y1 , env->color);
}


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
