/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:05:22 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/21 19:05:33 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*tr1(void *param)
{
	t_tr *p;

	p = param;
	p->img = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H / THREADS_MAX);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	p->y2 = 0;
	while (p->y < p->max)
	{
		p->x2 = 0;
		p->x = 0;
		while (p->x < SCREEN_W)
		{
			p->pr = 1.5 * (p->x - SCREEN_W / 2) /
				(0.5 * p->zoom * SCREEN_W) + p->movex;
			p->pi = (p->y - SCREEN_H / 2) /
			(0.5 * p->zoom * SCREEN_H) + p->movey;
			mande(p);
			pixel_to_img(p);
			p->x++;
			p->x2++;
		}
		p->y2++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	*tr2(void *param)
{
	t_tr *p;

	p = param;
	p->img = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H / THREADS_MAX);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	p->y2 = 0;
	while (p->y < p->max)
	{
		p->x2 = 0;
		p->x = 0;
		while (p->x < SCREEN_W)
		{
			p->pr = 1.5 * (p->x - SCREEN_W / 2) /
				(0.5 * p->zoom * SCREEN_W) + p->movex;
			p->pi = (p->y - SCREEN_H / 2) /
			(0.5 * p->zoom * SCREEN_H) + p->movey;
			julia(p);
			pixel_to_img(p);
			p->x++;
			p->x2++;
		}
		p->y2++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	*tr3(void *param)
{
	t_tr *p;

	p = param;
	p->img = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H / THREADS_MAX);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	p->y2 = 0;
	while (p->y < p->max)
	{
		p->x2 = 0;
		p->x = 0;
		while (p->x < SCREEN_W)
		{
			p->pr = 1.5 * (p->x - SCREEN_W / 2) /
				(0.5 * p->zoom * SCREEN_W) + p->movex;
			p->pi = (p->y - SCREEN_H / 2) /
			(0.5 * p->zoom * SCREEN_H) + p->movey;
			mw(p);
			pixel_to_img(p);
			p->x++;
			p->x2++;
		}
		p->y2++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	*tr4(void *param)
{
	t_tr *p;

	p = param;
	p->img = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H / THREADS_MAX);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	p->y2 = 0;
	while (p->y < p->max)
	{
		p->x2 = 0;
		p->x = 0;
		while (p->x < SCREEN_W)
		{
			p->pr = 1.5 * (p->x - SCREEN_W / 2) /
				(0.5 * p->zoom * SCREEN_W) + p->movex;
			p->pi = (p->y - SCREEN_H / 2) /
			(0.5 * p->zoom * SCREEN_H) + p->movey;
			carpet(p);
			pixel_to_img(p);
			p->x++;
			p->x2++;
		}
		p->y2++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	*tr5(void *param)
{
	t_tr *p;

	p = param;
	p->img = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H / THREADS_MAX);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	p->y2 = 0;
	while (p->y < p->max)
	{
		p->x2 = 0;
		p->x = 0;
		while (p->x < SCREEN_W)
		{
			p->pr = 1.5 * (p->x - SCREEN_W / 2) /
				(0.5 * p->zoom * SCREEN_W) + p->movex;
			p->pi = (p->y - SCREEN_H / 2) /
			(0.5 * p->zoom * SCREEN_H) + p->movey;
			torn(p);
			pixel_to_img(p);
			p->x++;
			p->x2++;
		}
		p->y2++;
		p->y++;
	}
	pthread_exit(NULL);
}
