/*
** utils.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/include/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:20:37 2016 Faudil Puttilli
** Last update Wed Jan 11 20:36:45 2017 Faudil Puttilli
*/

#include "myCsfml.h"

int	my_getnbr(char *str)
{
  int	result;
  int	i;

  i = 0;
  result = 0;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      result *= 10;
      result += str[i] - 48;
      i++;
    }
  return (result);
}
