/*
** utils.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/include/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:20:37 2016 Faudil Puttilli
** Last update Sun Jan 15 21:52:21 2017 Faudil Puttilli
*/

#include "myCsfml.h"

char	*choose_music(char m)
{
  char	*music;

  if (m == 'D')
    music = my_strdup("music/Doom.ogg");
  else if (m == 'S')
    music = my_strdup("music/Sonic.ogg");
  else if (m == 'E')
    music = my_strdup("music/it_end.ogg");
  else if (m == 'M')
    music = my_strdup("music/mega_man.ogg");
  else
    music = my_strdup("music/guild_theme.ogg");
  return (music);
}

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
