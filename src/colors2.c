/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:45:48 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/24 15:45:55 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	blue(double *r, double *g, double *b, double t)
{
	*r = (int)(9 * (1 - t) * t * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void	green(double *r, double *g, double *b, double t)
{
	*r = (int)(9 * (1 - t) * (1 - t) * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * t * t * 255);
}

void	red(double *r, double *g, double *b, double t)
{
	*r = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * t * t * t * 255);
}

void	torn(t_tr *a)
{
	int		max;
	double	x;
	double	y;
	double	x2;
	double	y2;

	max = 1000;
	a->i = 0;
	x = a->pr;
	y = a->pi;
	while (((x * x) + (y * y) < max) && (a->i < a->iter))
	{
		x2 = x;
		y2 = y;
		x = x2 / cos(y2) + 1;
		y = y2 / cos(x2) + 1;
		a->i++;
	}
}
