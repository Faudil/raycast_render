/*
** raycasting.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 11:28:32 2016 Faudil Puttilli
** Last update Fri Jan  6 10:14:00 2017 Faudil Puttilli
*/

#include "myCsfml.h"

float		get_size(float distance)
{
  float		size;

  if (distance == 0)
    distance++;
  size = 1.f / distance * (float) SCREEN_HEIGHT;
  return (size);
}

float		raycast(sfVector2f m, sfVector2f pos, char **map,
			sfVector2i mapSize)
{
  float		ray;
  sfVector2f	tmp;

  tmp.x = pos.x;
  tmp.y = pos.y;
  while (tmp.x > 0 && tmp.y > 0 && tmp.x < mapSize.x && tmp.y < mapSize.y &&
	 map[(int) (tmp.x + (m.x / 100))][(int) (tmp.y + m.y / 100)] == '0')
    {
      tmp.x += m.x / 100.f;
      tmp.y += m.y / 100.f;
    }
  ray = sqrt(pow(pos.x - tmp.x, 2) + pow(pos.y - tmp.y, 2));
  return (ray);
}
