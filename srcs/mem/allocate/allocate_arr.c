/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:03:21 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:55:13 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Allocates memory for stacks 'a' and 'b'.
 *
 * This function allocates memory for two integer arrays, 
 * 'a' and 'b', using the number count stored in
 * 'data->numcount'. If memory allocation fails for either stack, 
 * the function 'error_memory_allocation' is invoked.
 *
 * @param data Pointer to the t_data structure containing 
 * the stack pointers and number count.
 */

void	allocate_a_and_b(t_data *data)
{
	data->a = ft_allocate_int_array(data->numcount);
	if (!data->a)
		error_memory_allocation(data);
	data->b = ft_allocate_int_array(data->numcount);
	if (!data->b)
		error_memory_allocation(data);
}
