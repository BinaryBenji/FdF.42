#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void 	draw_line() // 
{


}

t_coord		*assign_coord()

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;
	int i = 0;
	char donnees[20] = "01111111111111111110";
	int turn = 0;
	// 
	// algo de bresenham pour tracer une ligne
	// calcul du centre a partir de la taille d'une ligne du fichier
	y = 200;
	x = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "MLX");

	while (donnees[i])
	{	
		if (donnees[i] == '0')
		{	
			mlx_pixel_put(mlx,win,x,y,0x00FFFFFF);
		}
		else if(donnees[i] == '1')
		{
			x+=5;
			x+=5;
			mlx_pixel_put(mlx,win,x,y,0x00FFFFFF);
		}
		// else
		// {
		// 	exit(0);
		// }
		x+=20;
		y+=20;
		turn++;
		if(turn == 5)
		{
			x=220;

			turn = 0;
		}
		i++;
	}
		//x+=20;
		//y +=20;
	// no forget exit();

	// while (x < 500 && y < 500)
	// {
	// 	mlx_pixel_put(mlx, win, x++, y,0x00FFFFFF);
	// 	if (x == 500)
	// 	{
	// 		x = 0;
	// 		y++;
	// 	}
	// }	
	mlx_loop(mlx);
}