/*
** mylist.h for mylist.h in /home/faudil.puttilli/delivery/CPool_Day09/CPool_Day09/task02
** 
** Made by Faudil PUTTILLI
** Login   <faudil.puttilli@epitech.net>
** 
** Started on  Thu Oct 13 08:18:52 2016 Faudil PUTTILLI
** Last update Mon Oct 17 14:41:12 2016 Faudil PUTTILLI
*/
#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  void	*data;
  struct	s_list	*next;
}	t_list;

#endif
