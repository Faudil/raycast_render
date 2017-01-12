/*
** mini_map.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d/srcs
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 10 14:55:31 2017 Faudil Puttilli
** Last update Wed Jan 11 19:58:27 2017 Faudil Puttilli
*/

#include "myCsfml.h"

sfColor		set_color(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

void		print_case(t_my_framebuffer *fb, sfVector2i coord, char type)
{
  sfVector2f	pos;
  sfColor	color;

  pos.x = 0;
  pos.y = 0;
  color = get_color(pos, type);
  if (type != '0')
    draw_square(fb, set_square(coord, 10, 10), color);
  else
    draw_square(fb, set_square(coord, 10, 10), set_color(200, 200, 200, 255));
}

void		draw_map(t_main *m, sfVector2f pos)
{
  sfVector2i	inc;
  sfVector2i	coord;
  sfColor	color;

  inc.y = 0;
  coord.y = m->fb->height - 300;
  color = set_color(200, 100, 10, 255);
  while (m->map.map[inc.y] != NULL)
    {
      inc.x = my_strlen(m->map.map[inc.y]);
      coord.x = m->fb->width / 2 - 200;
      while (inc.x >= 0)
	{
	  if (inc.x == (int) (pos.y) && inc.y == (int) (pos.x))
	    draw_square(m->fb, set_square(coord, 10, 10), color);
	  else
	    print_case(m->fb, coord, m->map.map[inc.y][inc.x]);
	  inc.x--;
	  coord.x += 10;
	}
      coord.y += 10;
      inc.y++;
    }
}
