/*
** wireframe.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/include/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:41:34 2016 Faudil Puttilli
** Last update Thu Jan 12 16:14:42 2017 Faudil Puttilli
*/

#include "myCsfml.h"

sfRenderWindow* 	create_window(char* name, int width, int height)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int x, int y)
{
  int			i;
  t_my_framebuffer	*fb;

  if ((fb = malloc(sizeof(t_my_framebuffer) + 4)) == NULL)
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
  fb->width = x - 2;
  fb->height = y - 2;
  return (fb);
}

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

int		create_map(char *str, char *name)
{
  t_main	m;

  m.map = parse_map(str, 1);
  if (name != NULL)
    save_map(name, m.map);
  m.file = name;
  m.speed = SPEED;
  m.map_visible = 0;
  m.cube = '1';
  wolf3d(m);
  free_tab(m.map.map);
  free(str);
  return (0);
}

int     	wolf3d(t_main m)
{
  sfVector2f	pos;
  float		dir;

  dir = M_PI / 2;
  pos.x = 2;
  pos.y = 2;
  if ((m.window = create_window("Faudil", SCREEN_WIDTH, SCREEN_HEIGHT)))
    return (84);
  m.sprite = sfSprite_create();
  m.texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  m.fb = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(m.sprite, m.texture, sfTrue);
  print_fb(&m, pos, dir);
  sfTexture_updateFromPixels(m.texture, m.fb->pixels, m.fb->width,
			     m.fb->height, 0, 0);
  event_manager(&m, pos, 0);
  sfRenderWindow_destroy(m.window);
  free(m.fb);
  sfTexture_destroy(m.texture);
  return (0);
}
