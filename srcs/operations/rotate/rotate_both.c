/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 05:29:46 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/02 08:36:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Rotates both stacks 'a' and 'b' simultaneously.
 *
 * This function sets a flag to indicate
 * a simultaneous rotation, then calls
 * `rotate_a` and `rotate_b` to perform the
 * rotation on both stacks.
 * After the rotation, the flag is reset,
 * and the operation "rr" is printed.
 *
 * @param data A pointer to the t_data structure
 * containing both stacks.
 */
void	rotate_both(t_data *data)
{
	data->ra_rb_flag = 1;
	rotate_a(data);
	rotate_b(data);
	data->ra_rb_flag = 0;
	data->operation_count++;
	ft_putendl_fd("rr", 1);
}
