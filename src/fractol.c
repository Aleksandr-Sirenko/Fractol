/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:11:25 by asirenko          #+#    #+#             */
/*   Updated: 2019/02/06 18:38:50 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	chfract(t_mlx *a, int i)
{
	if (a->p[i].fractal == 1)
		pthread_create(&a->threads[i], NULL, tr1, (void *)&a->p[i]);
	if (a->p[i].fractal == 2)
		pthread_create(&a->threads[i], NULL, tr2, (void *)&a->p[i]);
	if (a->p[i].fractal == 3)
		pthread_create(&a->threads[i], NULL, tr3, (void *)&a->p[i]);
	if (a->p[i].fractal == 4)
		pthread_create(&a->threads[i], NULL, tr4, (void *)&a->p[i]);
	if (a->p[i].fractal == 5)
		pthread_create(&a->threads[i], NULL, tr5, (void *)&a->p[i]);
}

int		draw(t_mlx *a)
{
	int			i;
	int			y;

	y = 0;
	i = 0;
	init2(a);
	while (i < THREADS_MAX)
		chfract(a, i++);
	i = 0;
	while (i < THREADS_MAX)
		pthread_join(a->threads[i++], NULL);
	mlx_clear_window(a->mlx, a->win);
	i = 0;
	while (i < THREADS_MAX)
	{
		mlx_put_image_to_window(a->p[i].mlx, a->p[i].win, a->p[i].img, 0, y);
		free(a->p[i].data);
		free(a->p[i].img);
		y += SCREEN_H / THREADS_MAX;
		i++;
	}
	return (1);
}

void	fractal(int i)
{
	t_mlx		a;

	a.p = (t_tr *)malloc(sizeof(t_tr) * THREADS_MAX);
	initi(&a, i);
	help(i);
	mlx_loop_hook(a.mlx, draw, &a);
	mlx_hook(a.win, 4, 4, mouse_release, &a);
	mlx_hook(a.win, 6, 6, mouse_move, &a);
	mlx_hook(a.win, 17, 1L << 17, exit_x, (void *)0);
	mlx_hook(a.win, 2, 2, deal_key, &a);
	mlx_loop(a.mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	if (ft_strcmp(argv[1], "1") == 0)
		fractal(1);
	else if (ft_strcmp(argv[1], "2") == 0)
		fractal(2);
	else if (ft_strcmp(argv[1], "3") == 0)
		fractal(3);
	else if (ft_strcmp(argv[1], "4") == 0)
		fractal(4);
	else if (ft_strcmp(argv[1], "5") == 0)
		fractal(5);
	else
		usage();
	return (0);
}
