/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:39:51 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/18 20:39:59 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_mlx *a)
{
	int i;

	i = 0;
	a->mousex = x;
	a->mousey = y;
	if (a->counter % 2 == 1 && a->p[i].fractal == 2)
	{
		while (i < THREADS_MAX)
		{
			a->p[i].cre = 1 - x * 0.00125;
			a->p[i].cim = 1 - y * 0.0022;
			i++;
		}
	}
	mlx_loop_hook(a->mlx, draw, a);
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	resetzoom(t_mlx *a)
{
	int i;

	i = 0;
	a->maxre = 2;
	a->minre = -3.5;
	a->maxim = 1.3;
	a->minim = -1.8;
	while (i < THREADS_MAX)
	{
		a->p[i].movex = 0;
		a->p[i].movey = 0;
		a->p[i].zoom = 1;
		if (a->p[i].fractal == 1 || a->p[i].fractal == 4)
		{
			if (a->p[i].fractal == 4)
				a->p[i].movey = -0.5;
			a->p[i].movex = -0.5;
		}
		a->p[i].iter = 100;
		a->p[i].cre = -0.7;
		a->p[i].cim = 0.27015;
		i++;
	}
	mlx_loop_hook(a->mlx, draw, a);
}

void	zoomp(t_mlx *a)
{
	int		i;
	double	k;

	i = 0;
	k = 1 / 1.02;
	a->minre = interpolate(a->p[i].mousere, a->minre, k);
	a->maxre = interpolate(a->p[i].mousere, a->maxre, k);
	a->minim = interpolate(a->p[i].mouseim, a->minim, k);
	a->maxim = interpolate(a->p[i].mouseim, a->maxim, k);
	while (i < THREADS_MAX)
	{
		a->p[i].zoom *= 1.02;
		a->p[i].mousere = (double)(a->mousex /
		(SCREEN_W / (a->maxre - a->minre))) + a->minre;
		a->p[i].mouseim = (double)(a->mousey /
		(SCREEN_H / (a->maxim - a->minim))) + a->minim;
		a->p[i].movex = interpolate(a->p[i].mousere, a->p[i].movex, k);
		a->p[i].movey = interpolate(a->p[i].mouseim, a->p[i].movey, k);
		i++;
	}
	mlx_loop_hook(a->mlx, draw, a);
}

void	zoomm(t_mlx *a)
{
	int		i;
	double	k;

	i = 0;
	k = 1 / 0.98;
	a->minre = interpolate(a->p[i].mousere, a->minre, k);
	a->maxre = interpolate(a->p[i].mousere, a->maxre, k);
	a->minim = interpolate(a->p[i].mouseim, a->minim, k);
	a->maxim = interpolate(a->p[i].mouseim, a->maxim, k);
	while (i < THREADS_MAX)
	{
		a->p[i].zoom /= 1.02;
		a->p[i].mousere = (double)(a->mousex /
		(SCREEN_W / (a->maxre - a->minre))) + a->minre;
		a->p[i].mouseim = (double)(a->mousey /
		(SCREEN_H / (a->maxim - a->minim))) + a->minim;
		a->p[i].movex = interpolate(a->p[i].mousere, a->p[i].movex, k);
		a->p[i].movey = interpolate(a->p[i].mouseim, a->p[i].movey, k);
		i++;
	}
	mlx_loop_hook(a->mlx, draw, a);
}
