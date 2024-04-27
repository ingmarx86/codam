/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:24:44 by inoteboo          #+#    #+#             */
/*   Updated: 2023/05/29 15:04:33 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *img)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		g_var.pan_lr = g_var.pan_lr - (2 * g_var.zoom) / 10;
		put_img(img);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		g_var.pan_lr = g_var.pan_lr + (2 * g_var.zoom) / 10;
		put_img(img);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		g_var.pan_ud = g_var.pan_ud - (2 * g_var.zoom) / 10;
		put_img(img);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		g_var.pan_ud = g_var.pan_ud + (2 * g_var.zoom) / 10;
		put_img(img);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *img)
{
	xdelta = 0;
	if (ydelta > 0)
	{
		g_var.zoom = g_var.zoom * 0.95;
		put_img(img);
	}
	else if (ydelta < 0)
	{
		g_var.zoom = g_var.zoom * 1.05;
		put_img(img);
	}
}

void	exit_message(void)
{
	ft_printf("Incorrect arguments\nPlease enter mandle or julia for the ");
	ft_printf("type of fractol you want to see, julia should be followed ");
	ft_printf("by a 1, 2 or 3 depending on which juliaset you want to see.");
	exit(1);
}

void	close_clean(void *mlx)
{
	mlx_close_window(mlx);
}

int32_t	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	set_var(argc, argv);
	put_img(img);
	mlx_scroll_hook(mlx, &my_scrollhook, img);
	mlx_key_hook(mlx, &my_keyhook, img);
	mlx_close_hook(mlx, &close_clean, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
