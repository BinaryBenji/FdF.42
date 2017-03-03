#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

/*
**	Algo de bresenham pour tracer une ligne
**	Calcul du centre a partir de la taille d'une ligne du fichier
*/

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "MLX");
	mlx_loop(mlx);
}
