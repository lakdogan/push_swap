/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:49:18 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 19:47:48 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Allocates an array of integer pointers.
 *
 * Allocates memory for an array with 'size'
 * elements, where each element is a pointer
 * to an int. All pointers are initialized to NULL,
 * so an index with a NULL value
 * indicates that it is empty.
 *
 * @param size The number of elements (pointers) to allocate.
 * @return A pointer to the allocated array of int pointers,
 * or NULL on failure.
 */
int	**ft_allocate_int_array(int size)
{
	int	**array;
	int	i;

	array = malloc(size * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
	return (array);
}
