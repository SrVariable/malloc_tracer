/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:22:53 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/08/24 19:23:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tracer.h"
#include <stdlib.h>

#ifdef DEBUG
# include <stdio.h>
#endif

t_malloc	*get_malloc_struct(void)
{
	static t_malloc	m = {0};

	return (&m);
}

static t_block	*set_block(t_block *block, void *ptr, size_t size)
{
	t_block	*temp;
	t_block	*new_block;

	temp = block;
	new_block = malloc(sizeof(*new_block));
	if (!new_block)
		return (NULL);
	new_block->ptr = ptr;
	new_block->size = size;
	new_block->next = NULL;
	if (!temp)
		return (new_block);
	while (temp->next)
		temp = temp->next;
	temp->next = new_block;
	return (block);
}

static int	add_block(void *ptr, size_t size)
{
	t_malloc	*m;

	m = get_malloc_struct();
	if (!m)
		return (1);
	m->block = set_block(m->block, ptr, size);
	m->calls++;
	m->total_size_alloc += size;
	return (0);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (add_block(ptr, size) != 0)
		return (NULL);
	return (ptr);
}
