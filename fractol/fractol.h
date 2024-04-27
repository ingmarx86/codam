/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:06:26 by inoteboo          #+#    #+#             */
/*   Updated: 2023/05/29 13:41:32 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# define WIDTH 800
# define HEIGHT 800

int		color_picker(int n);
void	my_keyhook(mlx_key_data_t keydata, void *img);
void	my_scrollhook(double xdelta, double ydelta, void *img);
void	put_img(void *img);
int		fractol_itr(double x_axis, double y_axis, double size);
void	exit_message(void);
void	set_var(int count, char *var[]);
void	close_clean(void *mlx);

struct s_fractol
{
	double		zoom;
	double		pan_lr;
	double		pan_ud;
	double		real;
	double		imagine;
	int			fractol;
};
struct s_fractol	g_var;
#endif