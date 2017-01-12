/*
** str.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/include/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 22:10:33 2016 Faudil Puttilli
** Last update Tue Jan 10 02:01:14 2017 Faudil Puttilli
*/

#include "myCsfml.h"

int	my_strlen(char *str)
{
  int   len;

  len = 0;
  if (!str)
  {
    return (0);
  }
  while (str[len] != '\0')
    len++;
  return (len);
}

int	put_err(char *str)
{
  int	len;
  int	i;

  len = my_strlen(str);
  i = write(2, str, len);
  i++;
  return (84);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
