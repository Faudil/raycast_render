/*
** my_isometric_projection.c for wireframe in /home/guacamole/Epitech/delivery/wireframe
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Fri Dec  9 14:14:19 2016 Faudil Puttilli
** Last update Sun Dec 11 19:24:26 2016 Faudil Puttilli
*/

#include "myCsfml.h"

sfVector2i	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i    res;

  res.x = (int)((pos3d.x * cos(M_PI / 6) + pos3d.y * cos(M_PI / 6
							 + 2 * M_PI / 3)));
		 res.y = (int)(pos3d.x * sin(M_PI / 6)
			       + pos3d.y * sin(M_PI / 6 + 2 * M_PI / 3) -
			       pos3d.z * sin(M_PI / 6));
  return (res);
}
