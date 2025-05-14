/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:28:50 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Pushes the top element from stack B to stack A
 *
 * This function performs the "push a" operation, taking the top element
 * from stack B and pushing it onto stack A. If either stack A is full
 * (top_a == 0) or stack B is empty (top_b == numcount - 1), the operation
 * is aborted. After a successful push, the function increments the operation
 * counter and outputs "pa" to file descriptor 1 (stdout).
 *
 * @param data Pointer to the data structure containing stacks and counters
 * @return void
 */
void	push_a(t_data *data)
{
	if (data->top_a == 0 || data->top_b == data->numcount - 1)
		return ;
	ft_set_int_value(data->a, data->top_a - 1, data->b[data->top_b + 1][VALUE],
		data->b[data->top_b + 1][RANK]);
	ft_del_int_value(data->b, data->top_b + 1);
	data->top_a--;
	data->top_b++;
	data->operation_count++;
	ft_putendl_fd("pa", 1);
}
