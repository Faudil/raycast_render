/*
** event.c for wireframe in /home/guacamole/Epitech/delivery/wireframe
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Sat Dec 10 17:30:50 2016 Faudil Puttilli
** Last update Sun Jan 15 23:15:31 2017 Faudil Puttilli
*/

#include "myCsfml.h"

void	key_manager_rot(t_main *m, float *dir)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    *dir += M_PI / 96;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    *dir -= M_PI / 96;
  if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
    m->speed = SPEED * 2.5;
  else
    m->speed = SPEED;
}

int	collision(t_main m, float dir, sfVector2f pos, char key)
{
  dir += (key == 'Q' || key == 'D') ? M_PI / 2 : 0;
  m.speed *= (key == 'S' || key == 'D') ? -1 : 1;
  if (m.map.map[(int) (pos.x + m.speed * cosf(dir))]
      [(int) (pos.y + m.speed * sinf(dir))] == '0' &&
      pos.x + m.speed * cosf(dir) <= m.map.map_size.y &&
      pos.x + m.speed * cosf(dir) > m.speed
      && pos.y + m.speed * sinf(dir) <= m.map.map_size.x &&
      pos.y + m.speed * sinf(dir) > m.speed)
    return (0);
  return (1);
}

void	key_manager_event(t_main *m, float *dir, sfVector2f *pos)
{
  if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyTab)
    m->map_visible = (m->map_visible == 1) ? 0 : 1;
  else if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyR)
    m->reflect = (m->reflect == 1) ? 0 : 1;
  else if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyN)
    m->night = (m->night == 1) ? 0 : 1;
  else if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyC)
    m->creator = (m->creator == 1) ? 0 : 1;
  else if (m->event.type == sfEvtKeyPressed && m->event.key.code == sfKeyReturn)
    save_map(m->file, m->map);
  if (m->event.key.code > '0' && m->event.key.code < '7')
    m->cube = m->event.key.code;
  else if (m->event.key.code == sfKeyV)
    m->cube = 'V';
  interact(m, dir, pos);
}

void	key_manager(t_main *m, float *dir, sfVector2f *pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue  &&
      collision(*m, *dir, *pos, 'Z') == 0)
    {
      pos->x = pos->x + m->speed * cosf(*dir);
      pos->y = pos->y + m->speed * sinf(*dir);
    }
  if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue  &&
      collision(*m, *dir, *pos, 'S') == 0)
    {
      pos->x -= m->speed * cosf(*dir);
      pos->y -= m->speed * sinf(*dir);
    }
  if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
      collision(*m, *dir, *pos, 'Q') == 0)
    {
      pos->x += m->speed * cosf(*dir + M_PI / 2);
      pos->y += m->speed * sinf(*dir + M_PI / 2);
    }
  if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
      collision(*m, *dir, *pos, 'D') == 0)
    {
      pos->x -= m->speed * cosf(*dir + M_PI / 2);
      pos->y -= m->speed * sinf(*dir + M_PI / 2);
    }
  key_manager_rot(m, dir);
}

void	event_manager(t_main *m, sfVector2f pos, float dir)
{
  while (sfRenderWindow_isOpen(m->window) && m->win == 0)
    {
      while (sfRenderWindow_pollEvent(m->window, &m->event))
	{
	  if (m->event.type == sfEvtClosed || m->event.key.code == sfKeyEscape)
	    sfRenderWindow_close(m->window);
	  key_manager_event(m, &dir, &pos);
	}
      key_manager(m, &dir, &pos);
      print_fb(m, pos, dir);
      sfTexture_updateFromPixels(m->texture, m->fb->pixels, m->fb->width,
				 m->fb->height, 0, 0);
      sfRenderWindow_clear(m->window, sfBlack);
      sfRenderWindow_drawSprite(m->window, m->sprite, NULL);
      sfRenderWindow_display(m->window);
    }
}
