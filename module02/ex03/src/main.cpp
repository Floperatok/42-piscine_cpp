#include <iostream>
#include "Point.hpp"

extern "C" {
	#include "../minilibx-linux/mlx.h"
}

void	pixel_put(char *addr, int line_length, int bits_per_pixel, int x, int y, int color)
{
	char	*dst;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void) 
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 800, (char *)"bsp");
	void	*img = mlx_new_image(mlx, 800, 800);
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 800; j++)
		{
			if (bsp(Point(400, 100), Point(700, 400), Point(400, 700), Point(j, i)))
				pixel_put(addr, line_length, bits_per_pixel, j, i, 0xFF0000);
		}
		
	}
	

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return 0;
}