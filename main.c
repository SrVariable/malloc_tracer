/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:17:04 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/08/24 22:07:56 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tracer.h"
#include <stdio.h>
#include <string.h>

void	foo(void)
{
	int	*d[2024];
	int	index;

	index = -1;
	while (++index < sizeof(d) / sizeof(d[0]))
		d[index] = ft_malloc(42 * index + 2024);
	d[25][0] = 25;
	d[0][1] = 1;
	d[2023][42] = 422024;
	printf("d[25][0] = %d\n", d[25][0]);
	printf("d[0][1] = %d\n", d[0][1]);
	printf("d[2023][42] = %d\n", d[2023][42]);
}

void	bar(void)
{
	float	*f[42];
	int		index;

	index = -1;
	while (++index < sizeof(f) / sizeof(f[0]))
		f[index] = ft_malloc(42 * index + 2024);
	f[3][14] = 3.1415;
	f[1][41] = 1.4142;
	printf("f[3][14] = %.4f\n", f[3][14]);
	printf("f[1][41] = %.4f\n", f[1][41]);
	index = -1;
	while (++index < sizeof(f) / sizeof(f[0]))
		ft_free(f[index]);
}

int	main(void)
{
	char	*s[3];
	int		index;

	index = -1;
	while (++index < sizeof(s) / sizeof(s[0]))
		s[index] = ft_malloc(42 * index + 2024);
	memcpy(s[0], "Hello world\0", 12);
	memcpy(s[1], "Lorem ipsum\0", 12);
	memcpy(s[2], "Does this work?\0", 16);
	index = -1;
	while (++index < sizeof(s) / sizeof(s[0]))
		printf("s[%d]: %s\n", index, s[index]);
	foo();
	bar();
	ft_cleanup();
	if (DEBUG)
		get_malloc_info();
	return (0);
}
