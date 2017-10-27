/*
** map_handler.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d/srcs
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Fri Dec 30 22:06:31 2016 Faudil Puttilli
** Last update Fri Jan 20 14:09:49 2017 Faudil Puttilli
*/

#include "myCsfml.h"

int	nb_c(char *str)
{
  int	i;
  int	j;
  int	tmp;

  j = 0;
  tmp = 0;
  while (str[j] != '\0')
    {
      i = 0;
      while (str[j] != '\0' && str[j] != '\n')
	{
	  i++;
	  j++;
	}
      i++;
      tmp = (tmp > i) ? tmp : i;
      j += (str[j] != '\0') ? 1 : 0;
    }
  return (tmp);
}

int	nb_line(char *str)
{
  int	nbr;
  int	i;

  nbr = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	nbr++;
      i++;
    }
  return (nbr);
}

char		**str_to_map(char *str)
{
  char		**map;
  int		nb_col;
  int		i;
  int		j;
  int		k;

  nb_col = nb_c(str);
  i = 0;
  j = 0;
  if ((map = malloc(sizeof(char *) * (nb_line(str) + 2))) == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    {
      k = 0;
      if ((map[j] = malloc(sizeof(char) * nb_col + 2)) == NULL)
	return (NULL);
      while (str[i] != '\n' && str[i] != '\0')
	map[j][k++] = str[i++];
      map[j++][k] = '\0';
      i += (str[i] != '\0') ? 1 : 0;
    }
  map[j] = NULL;
  return (map);
}

t_map		parse_map(char *str, float square_size)
{
  t_map		map;

  if (*str >= 'A' && *str <= 'Z')
    {
      map.music = *str;
      str++;
    }
  else
    map.music = 'G';
  if (nb_c(str) < 6 || nb_line(str) < 6)
    str = creator_mode(15, 15);
  map.map = str_to_map(str);
  map.square_size = square_size;
  map.map_size.x = nb_c(str) - 1;
  map.map_size.y = nb_line(str);
  return (map);
}
