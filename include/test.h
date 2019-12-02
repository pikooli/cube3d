/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:08:48 by paszhang          #+#    #+#             */
/*   Updated: 2019/12/02 13:27:45 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <mlx.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <math.h>
# include <stdlib.h>
# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926
# define PIOVER4 PI / 4
# define DEG2RAD PI / 180
# define RAD2DEG 180 / PI
# define BUFFER_SIZE 100
# define WALLSIZE 10
# define TEX 64
# define NORD 1
# define EAST 2
# define WEST 3
# define SUD 4
# define SPEED 0.5

typedef	struct	s_sprite
{
	double x;
	double y;
}				t_sprite;

typedef struct	s_rgb
{
	char r;
	char g;
	char b;
}				t_rgb;

typedef struct	s_image
{
	void*ptr;
	int *buff;
	int	w;
	int h;
	int put;
	int bpp;
	int sl;
	int end;
}				t_image;

typedef	struct	s_color
{
	int r;
	int b;
	int	g;
}				t_color;

typedef	struct	s_int
{
	int x;
	int y;
}				t_int;

typedef struct	s_ray
{
	double x;
	double y;
}				t_ray;

typedef	struct	s_wall
{
	int		wall_h;
	int		miniwallair;
	int		bas;
	int		haut;
	double	distance;
	int		mur_side;
}				t_wall;

typedef	struct	s_player
{
	t_ray	pl;
	t_ray	side;
	t_ray	raydir;
	t_ray	central;
	t_ray	dir;
	t_ray	plane;
	t_int	map;
	t_ray	delta;
	t_int	step;
}				t_player;

typedef	struct	s_win
{
	int		win_h;
	int		win_l;
	int		win_size;
	void	*ptr;
	void	*win;
	void	*image;
	int		*buff;
	int		ligne;
	int		bpp;
	int		sl;
	int		end;
}				t_win;

typedef struct	s_map
{
	char	*r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*f;
	char	*c;
	char	**mappy;
	int		n;
	int		px;
	int		len;
	int		py;
}				t_map;

typedef struct	s_csprite
{
	double	transfx;
	double	transfy;
	int		screenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
}				t_csprite;

typedef	struct	s_map2
{
	int			r_w;
	int			r_h;
	char		*no;
	char		*so;
	char		*we;
	char		*s;
	char		*ea;
	int			colorfloor;
	int			colorcelling;
	char		**mappy;
	int			n;
	int			mapw;
	int			maph;
	int			px;
	int			py;
	double		*zbuffer;
	int			nbr_sprite;
	int			*spriteorder;
	double		*spritedist;
	t_sprite	*sprite;
}				t_map2;

typedef struct	s_list
{
	t_player	player;
	t_win		win;
	t_wall		wall;
	t_map2		map;
	int			minimap;
	double		angle;
	int			key;
	int			hit;
	int			side;
	int			direction;
	int			orientation;
	t_image		nord;
	t_image		sud;
	t_image		west;
	t_image		east;
	t_image		sprite;
	t_image		sword;
	t_image		heart;
	t_csprite	sprite2;
	int			wild;
}				t_list;

void			ft_tire(t_list *data, int x, int y);
int				ft_quit(int key, t_list *data);
int				ft_freemain(t_list *data);
void			ft_raycentral(t_list *data);
void			ft_ray(t_list *data, int x);
void			ft_d_g_ray(t_list *data, double angle);
t_color			ft_get_color(char *str);
t_map			initmap(void);
char			**ft_split(char *str, char *charset, int i);
t_map2			ft_free(t_map map);
int				ft_checklenghtmap(t_map *map);
int				ft_check(char *str, t_map *map);
int				get_next_line(int fd, char **line);
char			*ft_allocdynamic(char *str1, char *str2);
t_map2			get_map(char *patchmap);
char			*ft_assigne(char *str);
int				ft_sprite(t_map2 *map, int mode);
int				ft_atoi(char *str, int *i);
int				ft_start(char *str, int *i);
int				ft_medium(char *str, int *i);
int				ft_mini_map(t_list *data);
int				ft_put_image(t_list *data);
int				ft_key(int key, t_list *data);
void			ft_detect_position(t_list *data);
int				ft_quit(int key, t_list *data);
void			screen(t_list *data);
void			ft_orientation(t_list *data);
void			ft_turn(t_list *data, int rotspeed);
int				ft_save_image(t_list data);
int				ft_error(int i);
int				ft_draw_screen(t_list *data);
void			ft_d(int pos, int size, int color, t_list *data);
void			ft_draw_central_ray(t_list *data);
void			ft_position_perso(t_list *data);
void			*ft_free_2(char *first, char *second);
t_map2			ft_erromap2(t_map *map);
t_map2			ft_map2map2(t_map map);
void			ft_freemap(t_map *map, int all);
int				ft_medium(char *str, int *i);
int				ft_start(char *str, int *i);
int				ft_atoi(char *str, int *i);
t_color			ft_get_color(char *str);
int				ft_len2cara(char *str, char c);
void			ft_init(t_list *data);
int				ft_image(t_list *data);
int				ft_init_sprite(t_list *data);
void			ft_sort_sprite(t_list *data, int i);
int				ft_cmp(char *str1, char *str2);

#endif
