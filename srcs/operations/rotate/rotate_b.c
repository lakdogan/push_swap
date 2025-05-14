/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:32:55 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Swaps the first and last elements of stack B
 *
 * This function exchanges the top and bottom elements of stack B
 * and prints the operation "rb" if required.
 *
 * @param data Pointer to the data structure containing stacks and variables
 */
void	switch_both_numbers(t_data *data)
{
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->b[data->top_b + 1][VALUE] = data->b[data->top_b
		+ data->data_current_numcount][VALUE];
	data->b[data->top_b
		+ data->data_current_numcount][VALUE] = data->temp_value;
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->b[data->top_b + 1][RANK] = data->b[data->top_b
		+ data->data_current_numcount][RANK];
	data->b[data->top_b + data->data_current_numcount][RANK] = data->temp_rank;
	check_flag_print_op(data, "rb");
}

/**
 * @brief Moves value and rank from j+1 to j position in stack B
 *
 * This helper function copies data from the j+1 position to the j position
 * in stack B as part of the rotation operation.
 *
 * @param data Pointer to the data structure containing stacks and variables
 */
void	pass_value_and_rank(t_data *data)
{
	data->b[data->top_b + data->i.j][VALUE] = data->b[data->top_b + data->i.j
		+ 1][VALUE];
	data->b[data->top_b + data->i.j][RANK] = data->b[data->top_b + data->i.j
		+ 1][RANK];
}

/**
 * @brief Rotates the stack B upward
 *
 * This function shifts all elements of stack B up by one position.
 * The first element becomes the last one.
 * If stack B has 2 or fewer elements, special handling is applied.
 * Prints "rb" operation if required.
 *
 * @param data Pointer to the data structure containing stacks and variables
 */
void	rotate_b(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->b,
			data->numcount);
	if (data->data_current_numcount <= 1)
		return ;
	if (data->data_current_numcount == 2)
	{
		switch_both_numbers(data);
		return ;
	}
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->i.j = 1;
	while (data->i.j < data->data_current_numcount)
	{
		if (data->b[data->top_b + data->i.j + 1] != NULL)
		{
			pass_value_and_rank(data);
		}
		data->i.j++;
	}
	data->b[data->numcount - 1][VALUE] = data->temp_value;
	data->b[data->numcount - 1][RANK] = data->temp_rank;
	check_flag_print_op(data, "rb");
}
