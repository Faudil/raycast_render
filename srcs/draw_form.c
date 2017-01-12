/*
** draw_form.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 10 12:02:13 2017 Faudil Puttilli
** Last update Thu Jan 12 16:14:19 2017 Faudil Puttilli
*/

#include "myCsfml.h"

void	draw_square(t_my_framebuffer *fb, t_square square, sfColor color)
{
  int	x;
  int	y;

  x = square.origin.x;
  while (x < square.len.x + square.origin.x)
    {
      y = square.origin.y;
      while (y < square.len.y + square.origin.y)
	{
	  my_put_pixel(fb, x, y, color);
	  y++;
	}
      x++;
    }
}

t_square	set_square(sfVector2i origin, int len_x, int len_y)
{
  t_square	square;

  square.origin.x = origin.x;
  square.origin.y = origin.y;
  square.len.x = len_x;
  square.len.y = len_y;
  return (square);
}

void	draw_disk(t_disk disk, t_my_framebuffer *fb)
{
  int	x;
  int	y;

  x = disk.origin.x - disk.ray;
  while (x < disk.origin.x + disk.ray)
    {
      y = disk.origin.y - disk.ray;
      while (y < disk.origin.y + disk.ray)
	{
	  if (pow(disk.origin.x - x, 2)
	      + pow(disk.origin.y - y, 2) <= disk.ray * disk.ray &&
	      sqrt(pow(disk.origin.x - x, 2)
	      + pow(disk.origin.y - y, 2)) >= disk.ray - 2)
	    {
	      my_put_pixel(fb, x, y, set_color(200, 230, 0, 255));
	    }
	  y += 1;
	}
      x += 1;
    }
}

t_disk		set_disk(sfVector2i origin, int ray)
{
  t_disk	disk;

  disk.origin.x = origin.x;
  disk.origin.y = origin.y;
  disk.ray = ray;
  return (disk);
}
