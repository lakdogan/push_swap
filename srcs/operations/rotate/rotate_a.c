/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:33 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:48:13 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Rotates stack A upwards (shifts all elements up by one).
 *
 * @param data Pointer to the main data structure 
 * containing stacks and related information
 * 
 * @details This function takes the first element
 *  (at the top) of stack A and moves it
 * to the bottom of the stack, shifting all other elements up by one position.
 * The operation is performed by:
 * 1. Saving the value and rank of the top element
 * 2. Shifting all elements up by one position
 * 3. Placing the saved element at the bottom of the stack
 * 
 * If stack A is empty or contains only NULL elements, 
 * the function returns without
 * performing any operation.
 * 
 * @note After rotation, prints "ra" if the
 *  print flag is enabled in the data structure.
 */
void	rotate_a(t_data *data)
{
	if (data->a[data->top_a] != NULL)
	{
		data->temp_value = data->a[data->top_a][VALUE];
		data->temp_rank = data->a[data->top_a][RANK];
	}
	else
		return ;
	data->i.i = 0;
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i] != NULL && data->i.i < data->numcount - 1
			&& data->a[data->i.i + 1] != NULL)
		{
			ft_del_int_value(data->a, data->i.i);
			ft_set_int_value(data->a, data->i.i, data->a[data->i.i + 1][VALUE],
				data->a[data->i.i + 1][RANK]);
		}
		data->i.i++;
	}
	if (data->a[data->numcount - 1] != NULL)
	{
		data->a[data->numcount - 1][VALUE] = data->temp_value;
		data->a[data->numcount - 1][RANK] = data->temp_rank;
	}
	check_flag_print_op(data, "ra");
}
