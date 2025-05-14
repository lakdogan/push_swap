/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:19:32 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:48:30 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Swaps the top two elements of stack A
 *
 * This function exchanges the positions of the first and second elements
 * at the top of stack A. If there are less than two elements on the stack,
 * the function does nothing.
 *
 * @param data Pointer to the main data structure
 *  containing stacks and operation info
 * 
 * @note Prints "sa" to the output if the print flag is set
 */
void	swap_a(t_data *data)
{
	if (data->a[data->top_a] == NULL || data->a[data->top_a + 1] == NULL)
		return ;
	data->temp_value = data->a[data->top_a][VALUE];
	data->a[data->top_a][VALUE] = data->a[data->top_a + 1][VALUE];
	data->a[data->top_a + 1][VALUE] = data->temp_value;
	data->temp_rank = data->a[data->top_a][RANK];
	data->a[data->top_a][RANK] = data->a[data->top_a + 1][RANK];
	data->a[data->top_a + 1][RANK] = data->temp_rank;
	check_flag_print_op(data, "sa");
}
