/*
** creator.c for wolf3d in /home/guacamole/Epitech/delivery/wolf3d
** 
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 11 20:22:08 2017 Faudil Puttilli
** Last update Sun Jan 15 21:42:59 2017 Faudil Puttilli
*/

#include "myCsfml.h"

void	write_file(char *str, int fd)
{
  if (write(fd, str, my_strlen(str)) < 0)
    return ;
}

void	save_map(char *file, t_map map)
{
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(file,  O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH)) == -1)
    return ;
  while (map.map[i] != NULL)
    {
      write_file(map.map[i], fd);
      if (map.map[i + 1] != NULL)
	write_file("\n", fd);
      i++;
    }
  if (write(1, "Saved\n", 6) < -1)
    close(fd);
  else
    close(fd);
}

char	*creator_mode(int len_x, int len_y)
{
  char	*map;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(map = malloc(sizeof(char) * ((len_x + 1) * len_y + 1))))
    return (NULL);
  while (j < len_y)
    {
      i = 0;
      while (i < len_x)
	{
	  map[i + j * (len_x + 1)] = '0';
	  i++;
	}
      map[i + j * (len_x + 1)] = '\n';
      j++;
    }
  map[(len_x + 1) * len_y - 1] = '\0';
  return (map);
}
