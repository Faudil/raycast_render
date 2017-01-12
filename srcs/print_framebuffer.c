/*
** print_framebuffer.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d/srcs
** 
** Made by Faudil Puttilli
** Login <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 13:29:48 2016 Faudil Puttilli
** Last update Thu Jan 12 16:25:02 2017 Faudil Puttilli
*/

#include "myCsfml.h"

void		init_fb(t_main *m)
{
  int		modulo;
  int		i;

  i = 0;
  modulo = 1;
  while (i < (m->fb->width * m->fb->height * 4) / 2)
    {
      m->fb->pixels[i] = 0 + (modulo / 6000);
      m->fb->pixels[i + 1] = (100 + modulo / 17000);
      m->fb->pixels[i + 2] = 110 - (modulo / 70000);
      m->fb->pixels[i + 3] = 255;
      i += 4;
      modulo += 1;
    }
  while (i < m->fb->width * m->fb->height * 4)
    {
      m->fb->pixels[i] = 0;
      i++;
    }
}

void		draw_hud(t_main *m, sfVector2f pos, float dir)
{
  sfColor	color;
  t_disk	disk;

  disk.origin.x = m->fb->width / 2;
  disk.origin.y = m->fb->height / 2;
  disk.ray = 10;
  color = set_color(200, 230, 0, 255);
  draw_disk(disk, m->fb);
  my_put_pixel(m->fb, disk.origin.x, disk.origin.y, color);
  if (m->map_visible == 1)
    draw_map(m, pos);
  if (dir > 1000)
    return;
}

void		print_fb(t_main *m, sfVector2f pos, float dir)
{
  sfVector2f	a;
  sfVector2f	tmp;
  sfVector2i	from;
  sfVector2i	to;
  float		size;
  t_wall	wall;

  from.x = -1;
  to.x = 0;
  init_fb(m);
  while (++from.x < m->fb->width)
    {
      a.x = 1;
      a.y = (1.4 * ((float) (SCREEN_WIDTH / 2.f) - from.x)) /
	(float) SCREEN_WIDTH;
      tmp.x = a.x * cosf(dir) - a.y * sinf(dir);
      tmp.y = a.x * sinf(dir) + a.y * cosf(dir);
      wall = raycast(tmp, pos, m->map.map, m->map.map_size);
      size = get_size(wall.dist, dir, tmp);
      from.y = (int) (m->fb->height / 2 + size / 2);
      to.y = (int) (m->fb->height / 2 - size / 2);
      my_draw_line(m->fb, from, to, wall.color);
      to.x++;
    }
  draw_hud(m, pos, dir);
}