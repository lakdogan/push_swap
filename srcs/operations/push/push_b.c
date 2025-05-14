/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:37 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:46:31 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Pushes the top element from stack A to stack B
 *
 * This function takes the top element 
 * from stack A and puts it at the top of stack B.
 * It updates the corresponding 
 * stack pointers (top_a and top_b), increments
 * the operation counter, and outputs "pb"
 *  to standard output to indicate the operation.
 *
 * @param data Pointer to the data structure 
 * containing both stacks and their metadata
 *
 * @note The function will return without performing any operation if:
 *       - Stack A is empty (top_a == numcount)
 *       - There is no space in stack B (top_b == -1)
 */
void	push_b(t_data *data)
{
	if (data->top_a == data->numcount || data->top_b == -1)
		return ;
	ft_set_int_value(data->b, data->top_b, data->a[data->top_a][VALUE],
		data->a[data->top_a][RANK]);
	ft_del_int_value(data->a, data->top_a);
	data->top_a++;
	data->top_b--;
	data->operation_count++;
	ft_putendl_fd("pb", 1);
}
