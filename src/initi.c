/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:54:17 by klakbuic          #+#    #+#             */
/*   Updated: 2023/12/31 10:17:02 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void allocation_faild(void)
{
    perror("Problems with allocations !!!");
    exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (fractol->mlx_ptr == NULL)
	{
		allocation_faild();
	}
	fractol->mlx_wind = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			fractol->name);
	if (fractol->mlx_wind == NULL)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		allocation_faild();
	}
    
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_wind);
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		allocation_faild();
	}
    
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			                                    &fractol->img.bpp,
                                                &fractol->img.length, 
                                                &fractol->img.endian);
}
