/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:08 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:47:23 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Performs a reverse rotation operation on stack A
 *
 * This function rotates all elements of stack A downwards, making the bottom
 * element become the top element. The operation shifts all elements down by
 * one position, with the last element moving to the first position.
 * 
 * If stack A is empty (current_numcount is 0), the function does nothing.
 * After completing the operation, it calls check_flag_print_op to
 * potentially print "rra" based on the display settings.
 *
 * @param data Pointer to the main data 
 * structure containing stacks and program state
 */
void	reverse_rotate_a(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->a,
			data->numcount);
	if (data->data_current_numcount == 0)
		return ;
	data->temp_value = data->a[data->top_a + data->data_current_numcount
		- 1][VALUE];
	data->temp_rank = data->a[data->top_a + data->data_current_numcount
		- 1][RANK];
	data->i.i = 1;
	while (data->i.i < data->data_current_numcount)
	{
		data->a[data->top_a + data->data_current_numcount
			- data->i.i][VALUE] = data->a[data->top_a
			+ data->data_current_numcount - data->i.i - 1][VALUE];
		data->a[data->top_a + data->data_current_numcount
			- data->i.i][RANK] = data->a[data->top_a
			+ data->data_current_numcount - data->i.i - 1][RANK];
		data->i.i++;
	}
	data->a[data->top_a][VALUE] = data->temp_value;
	data->a[data->top_a][RANK] = data->temp_rank;
	check_flag_print_op(data, "rra");
}
