/*
** draw_line.c for lib_Csfml in /home/guacamole/Epitech/lib_Csfml/Draw_form/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Wed Nov 16 14:23:24 2016 Faudil Puttilli
** Last update Sun Dec 11 20:18:46 2016 Faudil Puttilli
*/

#include "myCsfml.h"

void	print_line_y(t_my_framebuffer *fb, sfVector2i from, sfVector2i to,
		     sfColor color)
{
  float	a;
  float	b;
  float	x;
  float	y;

  y = from.y;
  x = 0;
  a = (float)(to.x - from.x) / (float)(to.y - from.y);
  b = from.x - a * from.y;
  x = a * y + b;
  while (y < to.y)
    {
      x += a;
      my_put_pixel(fb, (int) x, (int) y, color);
      y++;
    }
}

void	print_line_x(t_my_framebuffer *fb, sfVector2i from, sfVector2i to,
						        sfColor color)
{
  float	a;
  float	b;
  float	x;
  float	y;

  x = from.x;
  y = 0;
  a = (float) (to.y - from.y) / (float)(to.x - from.x);
  b = from.y - a * from.x;
  y = a * x + b;
  while (x < to.x)
  {
    y += a;
    my_put_pixel(fb, (int) x, (int) y, color);
    x++;
  }
}

void	print_horizontal(t_my_framebuffer *fb, sfVector2i from, sfVector2i to,
			 sfColor color)
{
  int	x;
  int	y;
  int	max_y;

  x = to.x;
  max_y = (from.y > to.y) ? from.y : to.y;
  y = (from.y < to.y) ? from.y : to.y;
  if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT)
    return ;
  while (y < max_y)
    {
      my_put_pixel(fb, x, y, color);
      y++;
    }
}

void	print_vertical(t_my_framebuffer *fb, sfVector2i from, sfVector2i to,
		       sfColor color)
{
  int	x;
  int	y;
  int	max_x;

  y = to.y;
  max_x = (from.x > to.x) ? from.x : to.x;
  x = (from.x < to.x) ? from.x : to.x;
  if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT)
    return ;
  while (x < max_x)
    {
      my_put_pixel(fb, x, y, color);
      x++;
    }
}

void		my_draw_line(t_my_framebuffer *fb, sfVector2i from, sfVector2i to,
			     sfColor color)
{
  if (from.x == to.x)
    print_horizontal(fb, from, to, color);
  else if (from.y == to.y)
    print_vertical(fb, from, to, color);
  else if (abs(from.x - to.x) > abs(from.y - to.y))
    {
      if (from.x < to.x)
	print_line_x(fb, from, to, color);
      else
	print_line_x(fb, to, from, color);
    }
  else
    {
      if (from.y < to.y)
	print_line_y(fb, from, to, color);
      else
	print_line_y(fb, to, from, color);
    }
}
