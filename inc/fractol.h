/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:11:32 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/11 17:56:58 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/types.h>
# include <errno.h>
# include <mlx.h>
# include "../lib/libft/libft.h"
# define SCREEN_W 1600
# define SCREEN_H 900
# define THREADS_MAX 20

typedef struct	s_tr
{
	int			y2;
	int			x2;
	int			y;
	int			x;
	int			i;
	int			max;
	char		*data;
	int			color;
	double		pr;
	double		pi;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	int			j;
	double		zoom;
	double		movex;
	double		movey;
	int			bpp;
	int			sl;
	void		*mlx;
	void		**win;
	void		*img;
	int			endian;
	double		mousere;
	double		mouseim;
	double		set;
	double		cre;
	double		cim;
	int			fractal;
	int			iter;
}				t_tr;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	double		mousex;
	double		mousey;
	double		interpolation;
	double		maxre;
	double		maxim;
	double		minre;
	double		minim;
	int			counter;
	t_tr		*p;
	pthread_t	threads[THREADS_MAX];
}				t_mlx;

typedef struct	s_point
{
	void		*mlx;
	void		*win;
}				t_point;

int				exit_x(void);
int				deal_key(int key, t_mlx *e);
int				mouse_move(int x, int y, t_mlx *a);
int				mouse_release(int button, int x, int y, t_mlx *a);
int				draw(t_mlx *a);
int				get_color(t_tr *a);
void			mande(t_tr *a);
void			julia(t_tr *a);
void			pixel_to_img(t_tr *a);
void			resetzoom(t_mlx *a);
void			zoomp(t_mlx *a);
void			zoomm(t_mlx *a);
void			mw(t_tr *a);
void			*tr1(void *param);
void			*tr2(void *param);
void			*tr3(void *param);
void			init2(t_mlx *a);
void			initp(t_mlx *a, int t);
void			initi(t_mlx *a, int i);
void			blue(double *r, double *g, double *b, double t);
void			red(double *r, double *g, double *b, double t);
void			green(double *r, double *g, double *b, double t);
void			carpet(t_tr *a);
void			*tr4(void *param);
void			*tr5(void *param);
void			torn(t_tr *a);
void			fern(t_tr *a);
void			biomorph(t_tr *a);
void			*tr6(void *param);
void			movekeys2(t_mlx *e, int key);
void			help(int i);
void			usage(void);
#endif
