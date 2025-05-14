/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_reverse_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:26:36 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/02 20:54:48 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Rotates the reverse-sorted stack 'a' to
 * align the maximum element at the top.
 *
 * This function calculates the optimal number of
 * rotations needed to bring the maximum
 * element to the top of stack 'a'. Depending on
 * whether forward or reverse rotation
 * requires fewer moves, it calls either `rotate_a()`
 * or `reverse_rotate_a()`.
 *
 * @param data A pointer to the t_data structure
 * containing the stack 'a' and its metadata.
 */
void	rotate_reverse_sorted_stack(t_data *data)
{
	printf("moves: %i\n", data->moves);
	data->i.m = 0;
	if (data->moves < data->numcount / 2)
	{
		while (data->i.m < data->moves)
		{
			rotate_a(data);
			data->i.m++;
		}
	}
	else
	{
		data->moves = data->numcount - data->moves;
		while (data->i.m < data->moves)
		{
			reverse_rotate_a(data);
			data->i.m++;
		}
	}
}

/**
 * @brief Checks if stack 'a' is sorted in
 * descending order and performs necessary rotations.
 *
 * This function iterates through stack 'a'
 * to check if it is sorted in descending order.
 * It identifies the maximum element and calculates
 * the moves needed to bring it to the top.
 * If the stack is not sorted, it either rotates or
 * returns 0 if sorting is not feasible.
 *
 * @param data A pointer to the t_data structure
 * containing the stack 'a' and its metadata.
 * @return 1 if the stack is reverse-sorted or
 * successfully rotated into a reverse-sorted state, 0 otherwise.
 */
int	check_for_reverse_sorted(t_data *data)
{
	data->i.i = 0;
	data->max_num = data->a[0][0];
	while (data->i.i < data->numcount - 1)
	{
		if (data->a[data->i.i][0] > data->a[data->i.i + 1][0])
			data->compare++;
		data->i.i++;
		if (data->compare != data->i.i)
		{
			data->sorted_flag++;
			if (data->sorted_flag == 2)
				return (0);
			if (data->a[data->i.i][0] > data->max_num)
			{
				data->max_num = data->a[data->i.i][0];
				data->moves = data->i.i;
				data->compare = data->i.i;
			}
			else
				return (0);
		}
	}
	if (data->moves > 0)
		rotate_reverse_sorted_stack(data);
	return (1);
}
