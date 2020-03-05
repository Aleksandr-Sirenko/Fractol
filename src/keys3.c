/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:56 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/30 16:59:15 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	movekeys2(t_mlx *e, int key)
{
	int i;

	i = -1;
	if (key == 125)
		while (++i < THREADS_MAX)
		{
			e->p[i].mouseim += 5 / e->p[i].zoom;
			e->p[i].movey += 0.1 / e->p[i].zoom;
		}
	if (key == 126)
		while (++i < THREADS_MAX)
		{
			e->p[i].mouseim -= 5 / e->p[i].zoom;
			e->p[i].movey -= 0.1 / e->p[i].zoom;
		}
}
