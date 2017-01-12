/*
** parse_map.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 13:36:20 2016 Faudil Puttilli
** Last update Wed Jan 11 22:05:57 2017 Faudil Puttilli
*/

#include "myCsfml.h"

int	**parse_map(char *str)
{
  int	**map;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((map = malloc(sizeof(int) * my_stren(str) + 4)))
    return (NULL);
  while (str[i] != '\0')
    {
      k = 0;
      i = 0;
      if ((map = malloc(sizeof(int) * my_stren(str) + 4)))
	return (NULL);
      while (str[i] != '\n' && str[i] != '\0')
	map[j][k++] = (int)str[i++];
      map[j][k] = '\0';
      j++;
    }
  map[j] = NULL;
  return (map);
}
