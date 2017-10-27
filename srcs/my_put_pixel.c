/*
** wireframe.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/include/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:41:34 2016 Faudil Puttilli
** Last update Fri Jan 20 14:36:47 2017 Faudil Puttilli
*/

#include "myCsfml.h"

t_my_framebuffer	*my_framebuffer_create(int x, int y)
{
  int			i;
  t_my_framebuffer	*fb;

  if ((fb = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  fb->pixels = malloc(x * y * 4 * sizeof(sfUint8));
  if (fb->pixels == NULL)
    return (NULL);
  if (fb == NULL || fb->pixels == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (i < x * y * 4)
    {
      fb->pixels[i] = 0;
      i++;
    }
  fb->width = x;
  fb->height = y;
  return (fb);
}

t_my_framebuffer	*my_put_pixel(t_my_framebuffer *fb, int x, int y,
				      sfColor color)
{
  if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT || x < 0 || y < 0)
    return (0);
  fb->pixels[(fb->width * y + x) * 4] = color.r;
  fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
  fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
  fb->pixels[(fb->width * y + x) *  4 + 3] = color.a;
  return (fb);
}
