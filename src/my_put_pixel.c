/*
** my_put_pixel.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/src
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Fri Dec  9 14:09:14 2016 Faudil Puttilli
** Last update Mon Dec 12 10:05:45 2016 Faudil Puttilli
*/

#include "myCsfml.h"

t_my_framebuffer	*my_put_pixel(t_my_framebuffer *fb, int x, int y,
				      sfColor color)
{
  if (x > fb->width || y > fb->height || x < 0 || y < 0)
    return (0);
  fb->pixels[(fb->width * y + x) * 4] = color.r;
  fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
  fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
  fb->pixels[(fb->width * y + x) *  4 + 3] = color.a;
  return (fb);
}
