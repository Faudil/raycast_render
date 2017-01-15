/*
** raycasting.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 11:28:32 2016 Faudil Puttilli
** Last update Sun Jan 15 21:09:43 2017 Faudil Puttilli
*/

#include "myCsfml.h"

float		get_size(float distance)
{
  float		size;

  if (distance == 0)
    distance++;
  size = 1.f / distance * (float) SCREEN_HEIGHT;
  if (size > 2000)
    size = 2000;
  return (size);
}

sfColor		get_color(char side, char type)
{
  sfColor	color;

  if (type == '1')
    color = set_color(50, 150, 20, 255);
  else if (type == '2')
    color = set_color(200, 50, 20, 255);
  else if (type == '3')
    color = set_color(50, 20, 150, 255);
  else if (type == '4')
    color = set_color(40, 40, 55, 255);
  else if (type == '5')
    color = set_color(200, 200, 150, 255);
  else if (type == '6')
    color = set_color(60, 168, 168, 1);
  else if (type == 'V')
    color = set_color(170, 168, 40, 1);
  else
    color = set_color(20, 20, 20, 255);
  if (side == 0)
    color = set_color(color.r, color.g, color.b, 255);
  else
    color = set_color(color.r - 20, color.g - 20, color.b - 20, 255);
  return (color);
}

void	assign_vector(t_raycast *r, sfVector2f pos, sfVector2f m)
{
  r->box.x = (int) (pos.x);
  r->box.y = (int) (pos.y);
  r->delta.x = sqrt(1 + (m.y * m.y) / (m.x * m.x));
  r->delta.y = sqrt(1 + (m.x * m.x) / (m.y * m.y));
  r->hit = 0;
  r->side = 0;
  if (m.x < 0 && (r->step.x = -1) != -4)
    r->side_dist.x = (pos.x - r->box.x) * r->delta.x;
  else if ((r->step.x = 1) > -42)
    r->side_dist.x = (r->box.x + 1.0 - pos.x) * r->delta.x;
  if (m.y < 0 && (r->step.y = -1) != -4)
    r->side_dist.y = (pos.y - r->box.y) * r->delta.y;
  else if ((r->step.y = 1) > -42)
    r->side_dist.y = (r->box.y + 1.0 - pos.y) * r->delta.y;
}

t_wall		raycast(sfVector2f m, sfVector2f pos, char **map,
			sfVector2i map_size)
{
  t_raycast	r;

  assign_vector(&r, pos, m);
  while (r.hit == 0 && r.box.x + r.step.x >= 0 && r.box.y + r.step.y >= 0 &&
	 r.box.x + r.step.x <= map_size.y && r.box.y + r.step.y <= map_size.x)
    {
      if (r.side_dist.x < r.side_dist.y && (r.side = 0) > -4 &&
	  (r.box.x += r.step.x) > -1)
	r.side_dist.x += r.delta.x;
      else if ((r.side = 1) > -4 && (r.box.y += r.step.y) > -1)
	r.side_dist.y += r.delta.y;
      r.hit = (map[(int) (r.box.x)][(int) (r.box.y)] != '0') ? 1 : 0;
    }
  if (r.side == 0)
    r.wall.dist = (r.box.x - pos.x + (1 - r.step.x) / 2) / m.x;
  else
    r.wall.dist = (r.box.y - pos.y + (1 - r.step.y) / 2) / m.y;
  r.wall.type = map[(int) (r.box.x)][(int) (r.box.y)];
  r.wall.color = get_color(r.side, map[(int) (r.box.x)][(int) (r.box.y)]);
  r.wall.side = r.side;
  return (r.wall);
}
