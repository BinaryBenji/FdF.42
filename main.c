/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:34:47 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 17:34:50 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_env 	init_map(t_env env)
{
	env.height = 1200;
	env.width = 1200;
	env.colour = 0x00FFFFFF;
	env.decalx = 0;
	env.decaly = 0;
	env.linesizex = 0;
	env.linesizey = 0;
	return (env);
}
				
void 	ft_map(t_env env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "FdF");
	ft_mapdraw(env);
	mlx_key_hook(env->win, key_pressed, env);
	//mlx_hook(env->win, 17, (1L << 17), exit(0), env);
	mlx_loop(env->mlx);
}

int 	main(int argc, char **argv)
{
	t_env	env;
	int 	fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	if (work_coords(fd, env) == NULL)
		return (error());
	env = init_map(env);
	ft_map(env);
	return (0);
}