/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:21:12 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:59:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Handles memory allocation failure for integer arrays.
 *
 * Prints an error message indicating the failure to 
 * allocate memory for the arrays.
 * If memory has been allocated for either array 'a' or 'b' 
 * within the t_data structure,
 * the function frees the allocated memory to prevent memory leaks.
 *
 * @param data Pointer to the t_data structure containing 
 * the arrays and related metadata.
 */
void	error_memory_allocation(t_data *data)
{
	ft_putendl_fd("Failled to allocate memory for the array", 1);
	if (data->a != NULL)
		ft_free_int_array(data->a, data->numcount);
	if (data->b != NULL)
		ft_free_int_array(data->b, data->numcount);
}
