/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:08 by asirenko          #+#    #+#             */
/*   Updated: 2019/02/06 18:34:08 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init2(t_mlx *a)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i < THREADS_MAX)
	{
		a->p[i].y = y;
		y += SCREEN_H / THREADS_MAX;
		i++;
	}
}

void	init3(t_mlx *a, int i, int t)
{
	if (t == 1 || t == 4)
	{
		if (t == 4)
			a->p[i].movey = -0.5;
		a->p[i].movex = -0.5;
	}
}

void	initp(t_mlx *a, int t)
{
	int i;
	int y;

	y = SCREEN_H / THREADS_MAX;
	i = 0;
	while (i < THREADS_MAX)
	{
		a->p[i].movey = 0;
		a->p[i].movex = 0;
		init3(a, i, t);
		a->p[i].max = y;
		a->p[i].zoom = 1;
		a->p[i].mlx = a->mlx;
		a->p[i].win = a->win;
		a->p[i].set = 1;
		a->p[i].cre = -0.7;
		a->p[i].cim = 0.27015;
		a->p[i].iter = 100;
		a->p[i].fractal = t;
		y += SCREEN_H / THREADS_MAX;
		i++;
	}
}

void	initi(t_mlx *a, int i)
{
	a->mlx = mlx_init();
	if (i == 1)
		a->win = mlx_new_window(a->mlx, SCREEN_W, SCREEN_H, "Mandelbrot");
	if (i == 2)
		a->win = mlx_new_window(a->mlx, SCREEN_W, SCREEN_H, "Julia");
	if (i == 3)
		a->win = mlx_new_window(a->mlx, SCREEN_W, SCREEN_H, "Circle");
	if (i == 4)
		a->win = mlx_new_window(a->mlx, SCREEN_W, SCREEN_H, "Burning Ship");
	if (i == 5)
		a->win = mlx_new_window(a->mlx, SCREEN_W, SCREEN_H, "Thorn");
	a->maxre = 2;
	a->minre = -3.5;
	a->maxim = 1.3;
	a->minim = -1.8;
	a->counter = 1;
	a->interpolation = 1 / 1.03;
	initp(a, i);
}
