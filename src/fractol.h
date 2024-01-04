#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		length;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_wind;
	t_img	img;
}			t_fractol;

# define ERR_MESS "please enter valide input"

void		fractol_init(t_fractol *fractol);

/* Math */
double		scale_map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);

#endif