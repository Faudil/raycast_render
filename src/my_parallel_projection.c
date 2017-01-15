/*
** my_parallel_projection.c for wireframe in /home/guacamole/Epitech/delivery/wireframe
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Fri Dec  9 14:13:23 2016 Faudil Puttilli
** Last update Sat Dec 10 15:36:54 2016 Faudil Puttilli
*/

#include "myCsfml.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i    res;

  res.x = (int)(pos3d.x - pos3d.y * sin(angle));
  res.y = (int)(pos3d.y * cos(angle) - pos3d.z);
  return (res);
}
