/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:20 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:47:35 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Performs a reverse rotation on stack B
 *
 * This function rotates all elements of stack B downwards by one position.
 * The last element (at the bottom) becomes the first one (at the top).
 * If stack B is empty (contains 0 elements), no operation is performed.
 *
 * @param data Pointer to the program's 
 * data structure containing stacks and counters
 *
 * @note After performing the operation, it calls check_flag_print_op() to 
 *       potentially print "rrb" based on the program's verbosity settings
 */
void	reverse_rotate_b(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->b,
			data->numcount);
	if (data->data_current_numcount == 0)
		return ;
	data->temp_value = data->b[data->top_b
		+ data->data_current_numcount][VALUE];
	data->temp_rank = data->b[data->top_b + data->data_current_numcount][RANK];
	data->i.i = 0;
	while (data->i.i < data->data_current_numcount - 1)
	{
		data->b[data->top_b + data->data_current_numcount
			- data->i.i][VALUE] = data->b[data->top_b
			+ data->data_current_numcount - data->i.i - 1][VALUE];
		data->b[data->top_b + data->data_current_numcount
			- data->i.i][RANK] = data->b[data->top_b
			+ data->data_current_numcount - data->i.i - 1][RANK];
		data->i.i++;
	}
	data->b[data->top_b + 1][VALUE] = data->temp_value;
	data->b[data->top_b + 1][RANK] = data->temp_rank;
	check_flag_print_op(data, "rrb");
}
