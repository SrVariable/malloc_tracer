/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tracer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:23:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/08/24 23:27:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_TRACER_H
# define MALLOC_TRACER_H

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <stdlib.h>

# ifndef DEBUG
#  define DEBUG 0
# endif // DEBUG

/* @------------------------------------------------------------------------@ */
/* |                            Typedef Section                             | */
/* @------------------------------------------------------------------------@ */

typedef struct s_block	t_block;
typedef struct s_malloc	t_malloc;

/* @------------------------------------------------------------------------@ */
/* |                            Struct Section                              | */
/* @------------------------------------------------------------------------@ */

struct s_block
{
	void			*ptr;
	size_t			size;
	struct s_block	*next;
};

struct s_malloc
{
	t_block	*block;
	size_t	total_size_alloc;
	int		calls;
	int		free_calls;
};

/* @------------------------------------------------------------------------@ */
/* |                           Function Section                             | */
/* @------------------------------------------------------------------------@ */

/*
 * @brief Allocates `size` bytes.
 * @param size The size of the pointer.
 * @note Remember to use ft_free or ft_cleanup!
 */
void		*ft_malloc(size_t size);
/*
 * @brief Free a pointer `ptr` allocated by ft_malloc
 * @param ptr The pointer to be freed.
 * @warning This should only be used with pointers allocated by ft_malloc.
 */
void		ft_free(void *ptr);
/*
 * @brief Free every pointer allocated by ft_malloc
 * @note Overpowered function, you shouldn't get used to this.
 */
void		ft_cleanup(void);

/*
 * @brief Get some information about the allocations and frees.
 */
void		get_malloc_info(void);

/*
 * @brief Get the 'instance' of the malloc struct.
 * @note This is an internal function, you are not supposed to use it.
 */
t_malloc	*get_malloc_struct(void);

#endif // MALLOC_TRACER_H
