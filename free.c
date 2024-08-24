/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:35:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/08/24 21:35:24 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tracer.h"

static void	free_null(void *ptr)
{
	char	**temp;

	temp = ptr;
	free(*temp);
	*temp = NULL;
}

void	ft_cleanup(void)
{
	t_malloc	*m;
	t_block		*next;

	m = get_malloc_struct();
	while (m->block)
	{
		next = m->block->next;
		m->free_calls++;
		free_null(&m->block->ptr);
		free_null(&m->block);
		m->block = next;
	}
}

void	ft_free(void *ptr)
{
	t_malloc	*m;
	t_block		*current;
	t_block		*previous;

	m = get_malloc_struct();
	current = m->block;
	previous = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (previous)
				previous->next = current->next;
			else
				m->block = current->next;
			m->free_calls++;
			free_null(&ptr);
			free_null(&current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
