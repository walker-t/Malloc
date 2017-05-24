/*
** malloc.h for malloc in /home/walker/Taf/System_Unix_Mem/PSU_2016_malloc
** 
** Made by Walker
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sat Jan 28 16:22:26 2017 Walker
// Last update Mon Feb  6 15:16:38 2017 vandri_b
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_struct
{
  size_t	size;
  struct s_struct	*next;
  int		free;
  char		data[1];
}		t_struct;

#define BLOCK_SIZE sizeof(t_struct)
#endif /* !MALLOC_H_ */
