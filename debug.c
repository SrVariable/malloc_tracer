/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:44:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/08/24 22:14:57 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tracer.h"
#include <stdio.h>

void	get_malloc_info(void)
{
	t_malloc	*m;
	t_block		*current;

	m = get_malloc_struct();
	current = m->block;
	printf("\n================ MALLOC INFO ================\n");
	while (current)
	{
		printf("Ptr address: %p    |", current->ptr);
		printf("    Ptr size: %zu\n", current->size);
		current = current->next;
	}
	printf("Total malloc calls: %d\n", m->calls);
	printf("Total free calls: %d\n", m->free_calls);
	printf("Total bytes allocated: %zu\n", m->total_size_alloc);
	printf("=============================================\n");
}
