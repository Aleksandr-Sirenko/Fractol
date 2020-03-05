/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:08:06 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/14 19:08:12 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_tr *a)
{
	a->newre = a->pr;
	a->newim = a->pi;
	a->i = 0;
	while (a->i < a->iter)
	{
		a->oldre = a->newre;
		a->oldim = a->newim;
		a->newre = a->oldre * a->oldre - a->oldim * a->oldim + a->cre;
		a->newim = 2 * a->oldre * a->oldim + a->cim;
		if ((a->newre * a->newre + a->newim * a->newim) > 4)
			break ;
		a->i++;
	}
}

void	mw(t_tr *a)
{
	int z;

	z = (int)(a->pr * a->pr + a->pi * a->pi) % 255;
	a->i = z;
}

void	carpet(t_tr *a)
{
	double temp;

	a->newre = a->pr;
	a->newim = a->pi;
	a->i = 0;
	while (a->i < a->iter)
	{
		temp = a->newre * a->newre - a->newim * a->newim + a->pr;
		a->newim = fabs(2 * a->newre * a->newim) + a->pi;
		a->newre = fabs(temp);
		if ((a->newre * a->newre + a->newim * a->newim) > 4)
			break ;
		a->i++;
	}
}

void	mande(t_tr *a)
{
	a->newre = 0;
	a->newim = 0;
	a->i = 0;
	while (a->i < a->iter)
	{
		a->oldre = a->newre;
		a->oldim = a->newim;
		a->newre = a->oldre * a->oldre - a->oldim * a->oldim + a->pr;
		a->newim = 2 * a->oldre * a->oldim + a->pi;
		if ((a->newre * a->newre + a->newim * a->newim) > 4)
			break ;
		a->i++;
	}
}

void	pixel_to_img(t_tr *a)
{
	double r;
	double g;
	double b;
	double t;

	t = (double)a->i / (double)a->iter;
	if (a->set == 1)
		blue(&r, &g, &b, t);
	if (a->set == 2)
		green(&r, &g, &b, t);
	if (a->set == 3)
		red(&r, &g, &b, t);
	a->data[a->y2 * a->sl + a->x2 * a->bpp / 8] = b;
	a->data[a->y2 * a->sl + a->x2 * a->bpp / 8 + 1] = g;
	a->data[a->y2 * a->sl + a->x2 * a->bpp / 8 + 2] = r;
}
