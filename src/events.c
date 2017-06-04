/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:11:26 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/01 13:30:35 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Move view
*/

int		extension_1(int keycode, t_env *env)
{
	if (keycode == 126)
	{
		env->view_y -= 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 125)
	{
		env->view_y += 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 123)
	{
		env->view_x -= 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 124)
	{
		env->view_x += 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

/*
**	Colors
*/

int		extension_2(int keycode, t_env *env)
{
	if (keycode == 11)
	{
		env->color = 0x0000FF;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 15)
	{
		env->color = 0xFF0000;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 5)
	{
		env->color = 0x00FF00;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

/*
**	ZOOM
*/

int		extension_3(int keycode, t_env *env)
{
	if (keycode == 257)
	{
		if (env->linesizey > 1)
		{
			env->linesizex = env->linesizex / 2;
			env->linesizey = env->linesizey / 2;
		}
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 258)
	{
		env->linesizex = env->linesizex * 2;
		env->linesizey = env->linesizey * 2;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

/*
**	"Main" function for gestionning events, exit & Z variation
*/

int		key_pressed(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		env->z++;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 78)
	{
		env->z--;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 51)
	{
		init_map(env);
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	extension_1(keycode, env);
	extension_2(keycode, env);
	extension_3(keycode, env);
	return (0);
}
