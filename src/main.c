/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:54:20 by klakbuic          #+#    #+#             */
/*   Updated: 2023/12/31 10:18:10 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol fractol;

	if (ac == 2 && !strncmp(av[1], "mandelbrot", 10) || ac == 4
		&& !strncmp(av[1], "julia", 5))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		// all good start the application
	}
	else
	{
		puts("please enter valid inputs");
		exit(EXIT_FAILURE);
	}
}