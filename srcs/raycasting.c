/*
** raycasting.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 11:28:32 2016 Faudil Puttilli
** Last update Thu Jan 12 16:13:10 2017 Faudil Puttilli
*/

#include "myCsfml.h"

float		get_size(float distance, float angle, sfVector2f m)
{
  float		size;

  if (distance == 0)
    distance++;
  distance *= cosf(atan2f(m.y, m.x) - angle);
  size = 1.f / distance * (float) SCREEN_HEIGHT;
  if (size > 2000)
    size = 2000;
  return (size);
}

sfColor		get_color(sfVector2f pos, char type)
{
  sfColor	color;

  pos.x = fmod(pos.x, 1.00);
  pos.y = fmod(pos.y, 1.00);
  if (type == '1')
    color = set_color(50, 150, 20, 255);
  if (type == '2')
    color = set_color(200, 50, 20, 255);
  if (type == '3')
    color = set_color(50, 20, 150, 255);
  if (type == '4')
    color = set_color(40, 40, 55, 255);
  if (pos.x < pos.y && 1 - pos.x > pos.y)
    color = set_color(color.r, color.g, color.b, 255);
  else if (pos.x > pos.y && 1 - pos.x < pos.y)
    color = set_color(color.r, color.g, color.b, 255);
  else if (pos.x < pos.y)
    color = set_color(color.r - 20, color.g - 20, color.b - 20, 255);
  else if (pos.x > pos.y)
    color = set_color(color.r - 20, color.g - 20, color.b - 20, 255);
  return (color);
}

t_wall		raycast(sfVector2f m, sfVector2f pos, char **map,
			sfVector2i map_size)
{
  t_wall	wall;
  sfVector2f	tmp;

  tmp.x = pos.x;
  tmp.y = pos.y;
  while (tmp.x >= 0 && tmp.y >= 0 && tmp.y < map_size.x && tmp.x < map_size.y
	 && map[(int) (tmp.x + (m.x / 100))][(int) (tmp.y + m.y / 100)] == '0')
    {
      tmp.x += m.x / 150.f;
      tmp.y += m.y / 150.f;
    }
  wall.dist = sqrt(pow(pos.x - tmp.x, 2) + pow(pos.y - tmp.y, 2));
  wall.color = get_color(tmp, map[(int) (tmp.x + (m.x / 100))]
  [(int) (tmp.y + m.y / 100)]);
  return (wall);
}
