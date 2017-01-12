/*
** my.h for my.h in /home/faudil.puttilli/delivery/CPool_Day09/CPool_Day09/task02
** 
** Made by Faudil PUTTILLI
** Login   <faudil.puttilli@epitech.net>
** 
** Started on  Thu Oct 13 08:18:52 2016 Faudil PUTTILLI
** Last update Tue Oct 18 12:44:58 2016 Faudil PUTTILLI
*/
#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);

void	my_putstr(char *str);

int	my_getnbr(char *str);

int	my_isneg(int n);

int	my_swap(int *a, int *b);

int	my_strlen(char *str);

int	my_power_rec(int nb, int p);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

char	*my_strcpy(char *dest, char *src);

char	*my_strcat(char *dest, char *src);

char	*my_revstr(char *str);

void	my_sort_int_tab(int *tab, int size);

int	my_find_prime_sup(int nb);

char	*my_strncpy(char *dest, char *src, int n);

int	my_put_nbr(int nb);

char	*my_strstr(char *str, char *to_find);

int	my_strcmp(char *s1, char s2);

int	my_strncmp(char *s1, char *s2, int n);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char *str);

int	my_str_inum(char *str);

int	my_str_islower(char *str);

int	my_str_isupper(char *str);

int	my_str_isprintable(char *str);

int	my_showstr(char *str);

int	my_showmem(char *str, int size);

char	*my_strncat(char *dest, char *src, int n);

char	**my_str_to_wordtab(char *str);

char	*my_strdup(char *str);

int	my_show_wordtab(char **tab);	

int	my_str_isnum(char *str);

int	my_str_isnumalpha(char *str);

int	my_strcmp2(char *s1, char *s2);

int	my_strlen2(char *str);

int	match(char *s1, char *s2);

int	nmatch(char *s1, char *s2);

#endif
