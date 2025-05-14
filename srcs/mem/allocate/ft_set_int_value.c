/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_int_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:46:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 08:34:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Sets an integer value in an array of int pointers.
 *
 * Allocates memory for an int, assigns it
 * the given value, and stores its pointer
 * at the specified index in the array.
 *
 * @param array The array of int pointers.
 * @param index The index at which to store the value.
 * @param value The integer value to store.
 * @return 0 on success, or -1 if memory allocation fails.
 */
int	ft_set_int_value(int **array, int index, int value, int rank)
{
	array[index] = ft_calloc(4, sizeof(int));
	if (!array[index])
		return (-1);
	array[index][VALUE] = value;
	array[index][RANK] = rank;
	return (0);
}
