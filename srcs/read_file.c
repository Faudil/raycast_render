/*
** read_file.c for wireframe in /home/guacamole/Epitech/delivery/wireframe/src/
**
** Made by Faudil Puttilli
** Login   <faudil.puttilli@epitech.eu@epitech.eu>
**
** Started on  Tue Dec  6 12:28:37 2016 Faudil Puttilli
** Last update Wed Jan 11 21:19:04 2017 Faudil Puttilli
*/

#include "myCsfml.h"

char  *set_buffer(char *buffer)
{
  int	max;
  int	i;

  i = -1;
  max = BUFFER_SIZE;
  while (++i < max)
	buffer[i] = '\0';
  return (buffer);
}

char	*my_strcat(char *s1, char *s2)
{
  char	*final;
  int	i;
  int	j;
  int	len_max;

  i = 0;
  j = 0;
  len_max = my_strlen(s1) + my_strlen(s2) + 1;
  if ((final = malloc(sizeof(char) * len_max)) == NULL)
    return (NULL);
  while (s1 && s1[i] != '\0')
    {
      final[i] = s1[i];
      i++;
    }
  while (s2 && s2[j] != '\0')
    {
      final[i + j] = s2[j];
      j++;
    }
  final[i + j] = '\0';
  free(s1);
  return (final);
}

char	*read_file_cat(char *file)
{
  int	fd;
  char	*buffer;
  char	*str;

  if ((buffer = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
    return (NULL);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  set_buffer(buffer);
  str = NULL;
  while (read(fd, buffer, BUFFER_SIZE - 1) > 0)
    {
      str = my_strcat(str, buffer);
      set_buffer(buffer);
    }
  free(buffer);
  close(fd);
  return (str);
}
