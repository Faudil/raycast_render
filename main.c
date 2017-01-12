/*
** main.c for bootstrap in /home/guacamole/Epitech/lib_Csfml
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.net>
**
** Started on  Wed Nov  9 14:13:14 2016 Faudil Puttilli
** Last update Wed Jan 11 21:52:00 2017 Faudil Puttilli
*/

#include "myCsfml.h"

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   istrue;

  i = 0;
  while (s1[i] != '\0' && i < n && s2[i] != '\0')
    {
      if (s1[i] == s2[i])
	istrue = 1;
      else
	return (0);
      i++;
    }
  return (istrue);
}

int	check_env(char **ae)
{
  int	i;

  i = 0;
  while (ae[i] != NULL)
    {
      if (my_strncmp(ae[i], "DISPLAY", 7) == 1)
	  return (1);
      i++;
    }
  return (0);
}

int	main(int ac, char **argv, char **ae)
{
  char	*str;
  char	*name;

  if (check_env(ae) == 0)
    return (put_err("Please don't delete any environement variables\n"));
  if (ac > 1)
    {
      if (ac > 3 && my_strncmp(argv[1], "-c", 2) == 1)
	{
	  str = creator_mode(my_getnbr(argv[3]), my_getnbr(argv[4]));
	  name = argv[2];
	}
      else
	{
	  name = NULL;
	  str = read_file_cat(argv[1]);
	}
      if (str == NULL)
	return (put_err("Cannot open the file\n"));
      create_map(str, name);
    }
  else
    return (put_err("Please enter argument\n"));
  return (EXIT_SUCCESS);
}
