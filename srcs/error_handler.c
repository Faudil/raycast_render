/*
** error_handler.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Tue Dec  6 12:36:48 2016 Faudil Puttilli
** Last update Tue Dec 13 16:31:07 2016 Faudil Puttilli
*/

#include "myCsfml.h"

int	char_valid(char *str)
{
  int	i;
  int	j;
  int	k;
  int	n;

  i = 0;
  j = 0;
  k = 0;
  n = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	n++;
      else if (str[i] == ',')
	j++;
      else if (str[i] == '\n')
	k++;
      else
	return (84);
      i++;
    }
  if (n < 3 || j < n / 10 || k < 2)
    return (84);
  return (0);
}

int	line_verification(char *str)
{
  int	i;
  int	nb_col;
  int	tmp;
  int	nb_l;

  i = 1;
  nb_col = count_sep(str);
  nb_l = nbr_line(str);
  while (i != nb_l)
    {
      tmp = count_sep(str);
      if (tmp == nb_col - 1 && i  == nb_l)
	i += 0;
      else if (tmp != nb_col)
	return (84);
      str = skip_line(str);
      i++;
    }
  return (0);
}

int	file_verification(char *str)
{
  char	errors;

  errors = 0;
  if (my_strlen(str) < 6)
    return (put_err("File too short\n"));
  errors += char_valid(str);
  errors += line_verification(str);
  if (errors > 0)
    return (put_err("invalid file\n"));
  return (0);
}
