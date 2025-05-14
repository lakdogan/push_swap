/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:43:15 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:09:07 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

/**
 * @brief Swaps the top elements of both stacks A and B simultaneously.
 *
 * This function sets a flag to prevent the individual swap
 * functions (swap_a and swap_b)
 * from printing their respective messages. It then calls
 * swap_a() and swap_b() to swap the
 * top elements of stack A and stack B. After the swaps,
 * the flag is reset and the function
 * prints "ss" to standard output to indicate a simultaneous swap.
 *
 * @param data Pointer to the t_data structure containing
 * stacks A and B along with their indices.
 */
void	swap_both(t_data *data)
{
	data->sa_sb_flag = 1;
	swap_a(data);
	swap_b(data);
	data->sa_sb_flag = 0;
	data->operation_count++;
	print(data, "ss");
}
