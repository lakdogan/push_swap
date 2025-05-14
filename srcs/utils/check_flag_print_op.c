/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_print_op.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:31:50 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:49:33 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Checks flags and conditionally prints an operation
 *
 * This function checks if specific operation 
 * flags in the data structure are all 0.
 * If they are, it increments the operation counter and prints the given
 * operation string to standard output.
 *
 * @param data Pointer to the t_data structure
 *  containing operation flags and counter
 * @param op String representing the operation to be printed
 */
void	check_flag_print_op(t_data *data, char *op)
{
	if (data->rra_rrb_flag == 0 && data->ra_rb_flag == 0
		&& data->sa_sb_flag == 0)
	{
		data->operation_count++;
		ft_putendl_fd(op, 1);
	}
}
