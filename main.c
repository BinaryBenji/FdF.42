#include "mlx.h"

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "MLX");
	
	// no forget exit();
	y = 0;
	x = 0;
	while (x < 500 && y < 500)
	{
		mlx_pixel_put(mlx, win, x, y,0x00FFFFFF);
		x++;
		y++;
	}
	x = 500;
	y = 250;
	while (x > 0 && y > 0)
	{
		mlx_pixel_put(mlx, win, x, y,0x00FFFFFF);
		x--;
		y--;
	}
	mlx_loop(mlx);
}