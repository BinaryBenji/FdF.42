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
	env.color = 0x00FFFFFF;
	env.decalx = 0;
	env.decaly = 0;
	env.linesizex = 0;
	env.linesizey = 0;
	return (env);
}
				
void 	ft_map(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "FdF");
	//drawing(env);
	//mlx_key_hook(env.win, key_pressed, &env);
	mlx_loop(env.mlx);
}

// void	drawing(t_env env)
// {
	

// }

int 	main(int argc, char **argv)
{
	t_env	env;
	int 	fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	env = work_coords(fd, env);
	env = init_map(env);
	ft_map(env);
	return (0);
}