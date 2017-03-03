#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
**	Calcul du centre a partir de la taille d'une ligne du fichier
*/

/*
**	Bresenham Algorithm for tracing a line.
*/

void	draw_line(int coordx1, int coordx2, int coordy1, int coordy2, void *mlx, void *win)
{
	int dx;
	int dy;
	int p;
	int end;
	int x;
	int y;

	dx = abs(coordx1 - coordx2); //calc
	dy = abs(coordy1 - coordy2);
	p = 2 * dy - dx;
	x = (coordx1 < coordx2) ? (coordx1) : (coordx2);
	y = (x == coordx1) ? (coordy1) : (coordy2);
	end = (x == coordx1) ? (coordx2) : (coordx1);
	while(x < end)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		if(p < 0)
			p = p + 2 * dy;
		else
		{
			y++;
			p = p + 2 * (dy - dx);
		}
		x++;
	}
}


int main()
{
	void *mlx;
	void *win;

	int coordx1 = 450;
	int coordx2 = 50;
	int coordy1 = 799;
	int coordy2 = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "FdF");
	draw_line(coordx1, coordx2, coordy1, coordy2, mlx, win);
	mlx_loop(mlx);
}
