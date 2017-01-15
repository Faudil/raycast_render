/*
** event_env.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d/srcs
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 10 18:32:58 2017 Faudil Puttilli
** Last update Sun Jan 15 21:22:57 2017 Faudil Puttilli
*/

#include "myCsfml.h"

sfVector2f	get_before_wall(float dir, sfVector2f pos, char **map,
				sfVector2i map_size)
{
  sfVector2f	m;
  sfVector2f	tmp;

  tmp.x = pos.x;
  tmp.y = pos.y;
  dir -= M_PI / 4;
  m.x = cosf(dir) - sinf(dir);
  m.y = sinf(dir) + cosf(dir);
  while (tmp.x >= 0 && tmp.y >= 0 && tmp.y < map_size.x
	 && tmp.x < map_size.y && map[(int) (tmp.x + (m.x / 100))]
	 [(int) (tmp.y + m.y / 100)] == '0')
    {
      tmp.x += m.x / 100.f;
      tmp.y += m.y / 100.f;
    }
  return (tmp);
}

sfVector2f	get_wall(float dir, sfVector2f pos, char **map,
			 sfVector2i map_size)
{
  sfVector2f	m;
  sfVector2f	tmp;

  tmp.x = pos.x;
  tmp.y = pos.y;
  dir -= M_PI / 4;
  m.x = cosf(dir) - sinf(dir);
  m.y = sinf(dir) + cosf(dir);
  while (tmp.x >= 0 && tmp.y >= 0 && tmp.y < map_size.x - 1
	 && tmp.x < map_size.y - 1 && map[(int) (tmp.x + (m.x / 100))]
	 [(int) (tmp.y + m.y / 100)] == '0')
    {
      tmp.x += m.x / 100.f;
      tmp.y += m.y / 100.f;
    }
  tmp.x += m.x / 100.f;
  tmp.y += m.y / 100.f;
  return (tmp);
}

void		interact(t_main *m, float *dir, sfVector2f *pos)
{
  sfVector2f	wall;

  if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeySpace)
    {
      wall = get_wall(*dir, *pos, m->map.map, m->map.map_size);
      if (m->map.map[(int) (wall.x)][(int) (wall.y)] != '0' &&
	   m->creator == 1)
	m->map.map[(int) (wall.x)][(int) (wall.y)] = '0';
      else if ( m->map.map[(int) (wall.x)][(int) (wall.y)] == 'V')
	m->win = 1;
    }
  else if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyE
	   && m->creator == 1)
    {
      wall = get_before_wall(*dir, *pos, m->map.map, m->map.map_size);
      if ( m->map.map[(int) (wall.x)][(int) (wall.y)] == '0')
	m->map.map[(int) (wall.x)][(int) (wall.y)] = m->cube;
    }
}
