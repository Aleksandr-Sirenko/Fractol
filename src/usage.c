/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:18:57 by asirenko          #+#    #+#             */
/*   Updated: 2019/02/06 18:35:32 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(int i)
{
	ft_putendl("\x1b[32;1mMove: Up, Down, Right, Left arrows\x1b[0m");
	ft_putendl("\x1b[32;1mZoom: Wheel Up, Wheel Down\x1b[0m");
	ft_putendl("\x1b[32;1mReset: Wheel Button\x1b[0m");
	ft_putendl("\x1b[32;1mColor sets: 1, 2, 3\x1b[0m");
	ft_putendl("\x1b[32;1mIterations: +, -\x1b[0m");
	if (i == 2)
		ft_putendl("\x1b[32;1mLock Picture: Space\x1b[0m");
	ft_putendl("\x1b[32;1mExit: Escape\x1b[0m");
}

void	usage(void)
{
	ft_putendl("\x1b[32;1musage: ./fractol option\x1b[0m");
	ft_putendl("\x1b[32;1moptions: \x1b[0m");
	ft_putendl("\x1b[32;1m1 - Mandelbrot\x1b[0m");
	ft_putendl("\x1b[32;1m2 - Julia\x1b[0m");
	ft_putendl("\x1b[32;1m3 - Circle\x1b[0m");
	ft_putendl("\x1b[32;1m4 - Burning Ship\x1b[0m");
	ft_putendl("\x1b[32;1m5 - Thorn\x1b[0m");
	exit(0);
}
