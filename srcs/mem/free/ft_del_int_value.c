/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_int_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:56 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/03 21:44:19 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Deletes an integer from an array of int pointers.
 *
 * Frees the memory allocated for the integer 
 * at the given index and sets that pointer
 * to NULL, marking the slot as empty.
 *
 * @param array The array of int pointers.
 * @param index The index of the element to delete.
 */
void	ft_del_int_value(int **array, int index)
{
	if (array && array[index] != NULL)
	{
		free(array[index]);
		array[index] = NULL;
	}
}
