/*
** myCsfml.h for myCdfml.h in /home/guacamole/Epitech/delivery/CPool_Day13/CPool_Day13
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
**
** Started on  Sun Oct 23 17:52:37 2016 Faudil Puttilli
** Last update Sun Jan 15 21:15:40 2017 Faudil Puttilli
*/

#ifndef MY_CSFML

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define BUFFER_SIZE 8128
#define D 1
#define SPEED 0.03

typedef struct 		s_coord
{
  int			x;
  int			y;
}			t_coord;

typedef struct		s_square
{
  sfVector2i		origin;
  sfVector2i		len;
}			t_square;

typedef struct		s_disk
{
  sfVector2i		origin;
  int			ray;
}			t_disk;

typedef struct		s_my_framebuffer
{
  int			width;
  int			height;
  sfUint8		*pixels;
}			t_my_framebuffer;

typedef struct		s_wall
{
  float			dist;
  char			type;
  sfColor		color;
  float			size;
  int			side;
}			t_wall;

typedef struct		s_map
{
  char			**map;
  sfVector2i		map_size;
  float			square_size;
  char			music;
}			t_map;

typedef struct		s_raycast
{
  sfVector2f		box;
  t_wall		wall;
  sfVector2f		delta;
  sfVector2f		side_dist;
  sfVector2i		step;
  char			hit;
  char			side;
}			t_raycast;

typedef struct 		s_main
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
  t_my_framebuffer	*fb;
  sfVector2f		pos;
  t_map			map;
  char			map_visible;
  float			speed;
  char			cube;
  char			reflect;
  char			*file;
  char			creator;
  char			win;
}             		t_main;

int			create_map(char *, char *);
int			wolf3d(t_main);
int			put_err(char *);
t_wall			raycast(sfVector2f, sfVector2f, char **, sfVector2i);
float			get_size(float);
char			*read_file_cat(char *);
char			*creator_mode(int, int);
char			*choose_music(char);

t_my_framebuffer	*my_put_pixel(t_my_framebuffer *, int, int,
				      sfColor);

void			print_line_y(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
void			print_line_x(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
void			print_line_vertical(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
void			print_line_horizontal(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
void			my_draw_line(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);

void			draw_square(t_my_framebuffer *, t_square, sfColor);
void			draw_disk(t_disk, t_my_framebuffer *);
t_square		set_square(sfVector2i, int, int);
t_disk			set_disk(sfVector2i, int);

void			print_fb(t_main *, sfVector2f, float);
void			init_fb(t_main *);
void			free_tab(char **);
void			save_map(char *, t_map);

sfColor			set_color(int, int, int, int);
sfColor			get_color(char, char);
void			event_manager(t_main *, sfVector2f, float);
void			interact(t_main *, float *, sfVector2f *);

t_map			parse_map(char *, float);
char			**str_to_map(char *);

void			draw_map(t_main *, sfVector2f);
# endif
/*! MY_CSFML */
