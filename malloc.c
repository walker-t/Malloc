/*
** malloc.c for malloc in /home/walker/Taf/System_Unix_Mem/PSU_2016_malloc
** 
** Made by Walker
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sat Jan 28 16:21:50 2017 Walker
** Last update Thu Feb  9 15:14:29 2017 Walker
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

void	*base = NULL;

t_struct	*check_free_block(t_struct **last, size_t size)
{
  t_struct	*current;

  current = base;
  while (current != NULL && ((current->free && current->size >= size) == 0))
    {
      *last = current;
      current = current->next;
    }
  return (current);
}

t_struct	*add_block(t_struct *last, size_t size)
{
  t_struct	*block;
  void		*space_need;

  block = sbrk(0);
  space_need = sbrk(size + BLOCK_SIZE);
  if (space_need == (void *) -1)
    return (NULL);
  if (last != NULL)
    last->next = block;
  block->size = size;
  block->next = NULL;
  block->free = 0;
  return (block);
}

void		*malloc(size_t size)
{
  t_struct	*block;
  t_struct	*last;

  if (size <= 0)
    return (NULL);
  if (base == NULL)
    {
      if ((block = add_block(NULL, size)) == NULL)
	return (NULL);
      base = block;
    }
  else
    {
      last = base;
      block = check_free_block(&last, size);
      if (block == NULL)
	{
	  block = add_block(last, size);
	  if (!block)
	    return (NULL);
	}
      else
	block->free = 0;
    }
  return (block->data);
}

t_struct	*get_ptr_block(void *ptr)
{
  return ((t_struct*)ptr - 1);
}

void		free(void *ptr)
{
  t_struct	*ptr_block;
  t_struct	init;

  ptr_block = &init;
  if (ptr == NULL)
    return;
   ptr_block->free = 1;
}

void		*realloc(void *ptr, size_t size)
{
  t_struct	*ptr_block;
  void		*ptr2;

  if (ptr == NULL)
    return (malloc(size));
  ptr_block = get_ptr_block(ptr);
  if (ptr_block->size >= size)
    return (ptr);
  ptr2 = malloc(size);
  if (ptr2 == NULL)
    return (NULL);
  memcpy(ptr2, ptr, ptr_block->size);
  free(ptr);
  return (ptr2);
}
