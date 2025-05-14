/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:19:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:33:58 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Swaps the top two elements of stack B.
 *
 * This function exchanges the positions of the two topmost elements
 * in stack B if at least two elements exist. It swaps both the value
 * and rank attributes of these elements. If stack B contains fewer than
 * two elements, the function returns without performing any operation.
 *
 * @param data Pointer to the data structure containing stack information.
 * 
 * @note After completing the swap, the function may print "sb" operation
 *       based on the printing flag settings in the data structure.
 */
void	swap_b(t_data *data)
{
	if (data->b[data->top_b + 1] == NULL || data->b[data->top_b + 2] == NULL)
		return ;
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->b[data->top_b + 1][VALUE] = data->b[data->top_b + 2][VALUE];
	data->b[data->top_b + 2][VALUE] = data->temp_value;
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->b[data->top_b + 1][RANK] = data->b[data->top_b + 2][RANK];
	data->b[data->top_b + 2][RANK] = data->temp_rank;
	check_flag_print_op(data, "sb");
}
