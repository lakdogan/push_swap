/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:30:14 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 08:36:18 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees a dynamically allocated array of integer pointers.
 *
 * Iterates over the array, freeing each element using
 * ft_del_int_value and then frees the array itself.
 *
 * @param array Pointer to the array of integer pointers to free.
 * @param size The number of elements in the array.
 */
void	ft_free_int_array(int **array, int size)
{
	int	index;

	if (!array)
		return ;
	index = 0;
	while (index < size)
	{
		if (array[index] != NULL)
		{
			free(array[index]);
			array[index] = NULL;
		}
		index++;
	}
	free(array);
	array = NULL;
}
