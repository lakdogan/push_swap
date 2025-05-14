/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 07:59:03 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 21:35:36 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Performs a reverse rotation on both stacks 'a' and 'b' simultaneously.
 *
 * This function sets a flag to indicate simultaneous reverse rotation,
 * then calls `reverse_rotate_a` and `reverse_rotate_b` to perform the
 * reverse rotation on both stacks. Afterward, the flag is reset, and
 * the operation "rrr" is printed.
 *
 * @param data A pointer to the t_data structure containing both stacks.
 */
void	reverse_rotate_both(t_data *data)
{
	data->rra_rrb_flag = 1;
	reverse_rotate_a(data);
	reverse_rotate_b(data);
	data->rra_rrb_flag = 0;
	data->operation_count++;
	ft_putendl_fd("rrr", 1);
}
