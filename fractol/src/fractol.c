/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:41:21 by inoteboo          #+#    #+#             */
/*   Updated: 2023/06/28 10:03:19 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././fractol.h"

int	color_picker(int n)
{
	if (n < 10)
		return (0x900FF080 + (n * 10));
	else if (n < 20)
		return (0x00FF0080 + (n * 10000));
	else
		return (n * 10000);
}

void	put_img(void *img)
{
	double		x_axis;
	double		y_axis;
	double		size;
	int			iterations;

	x_axis = WIDTH - 1;
	y_axis = HEIGHT - 1;
	size = HEIGHT - 1;
	while (y_axis >= 0)
	{
		iterations = fractol_itr(x_axis, y_axis, size);
		mlx_put_pixel(img, x_axis, y_axis, 0x00FF0080 + iterations * 100000);
		x_axis--;
		if (x_axis < 0)
		{
			x_axis = WIDTH - 1;
			y_axis--;
		}
	}
}

int	fractol_itr(double real, double imagine, double size)
{
	int		iterations;
	double	real_temp;

	iterations = 1;
	real = (4 / size) * (real - size / 2) * g_var.zoom + g_var.pan_lr;
	imagine = (4 / size) * (imagine - (size / 2)) * g_var.zoom + g_var.pan_ud;
	if (g_var.fractol == 4)
	{
		g_var.real = real;
		g_var.imagine = imagine;
	}
	while ((real + imagine <= 4 && real + imagine >= -4 && iterations < 100))
	{
		real_temp = ((real * real) + ((imagine * imagine) * -1)) + g_var.real;
		imagine = (real * imagine) + (real * imagine) + g_var.imagine;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}

void	set_var(int count, char *var[])
{
	g_var.zoom = 1;
	g_var.pan_lr = 0;
	g_var.real = 0;
	g_var.imagine = 0;
	if (var[1] == NULL)
		exit_message();
	else if (ft_strncmp(var[1], "mandle", 7) == 0 && count == 2)
		g_var.fractol = 4;
	else if (ft_strncmp(var[1], "julia", 6) == 0
		&& count == 3 && ft_atoi(var[2]) < 4)
	{
		g_var.fractol = ft_atoi(var[2]);
		if (g_var.fractol == 1)
			g_var.imagine = -0.8;
		if (g_var.fractol == 2)
			g_var.real = -1.63;
	}
	if (g_var.fractol < 1 || g_var.fractol > 4)
		exit_message();
}
