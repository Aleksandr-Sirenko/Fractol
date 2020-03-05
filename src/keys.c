/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:41:47 by asirenko          #+#    #+#             */
/*   Updated: 2019/02/06 18:38:31 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_release(int button, int x, int y, t_mlx *a)
{
	a->mousex = x;
	a->mousey = y;
	if (button == 3)
		resetzoom(a);
	if (button == 5)
		zoomp(a);
	if (button == 4)
		zoomm(a);
	return (0);
}

int		exit_x(void)
{
	exit(1);
	return (0);
}

void	movekeys(t_mlx *e, int key)
{
	int i;

	i = -1;
	if (key == 123)
		while (++i < THREADS_MAX)
		{
			e->p[i].mousere -= 5 / e->p[i].zoom;
			e->p[i].movex -= 0.1 / e->p[i].zoom;
		}
	if (key == 124)
		while (++i < THREADS_MAX)
		{
			e->p[i].mousere += 5 / e->p[i].zoom;
			e->p[i].movex += 0.1 / e->p[i].zoom;
		}
	movekeys2(e, key);
}

void	keys(t_mlx *e, int key)
{
	int i;

	i = -1;
	if (key == 24 || key == 69)
		while (++i < THREADS_MAX)
			e->p[i].iter++;
	if (key == 27 || key == 78)
		while (++i < THREADS_MAX)
			e->p[i].iter--;
	if (key == 49)
		e->counter++;
	if (key == 18)
		while (++i < THREADS_MAX)
			e->p[i].set = 1;
	if (key == 19)
		while (++i < THREADS_MAX)
			e->p[i].set = 2;
	if (key == 20)
		while (++i < THREADS_MAX)
			e->p[i].set = 3;
	movekeys(e, key);
	mlx_loop_hook(e->mlx, draw, e);
}

int		deal_key(int key, t_mlx *e)
{
	keys(e, key);
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
		return (0);
	}
	return (0);
}
