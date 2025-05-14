/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:17:14 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 01:09:33 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Rotates the sorted stack 'a'
 * to align the minimum element at the top.
 *
 * This function checks the number of moves
 * needed to bring the minimum element
 * to the top of stack 'a'. If fewer forward
 * rotations are needed, it performs
 * them using `rotate_a()`. Otherwise, it
 * performs the necessary reverse rotations
 * using `reverse_rotate_a()`.
 *
 * @param data A pointer to the t_data structure
 * containing the stack 'a' and its metadata.
 */
void	rotate_sorted_stack(t_data *data)
{
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
 * @brief Validates the current state and
 * sets the number of moves if applicable.
 *
 * This function checks if the 'compare'
 * value matches the current index 'i.i'.
 * If not, it increments the 'sorted_flag'
 * and, if it reaches 2, returns 0 to indicate
 * an invalid state. Otherwise, it updates
 * the 'moves' and 'compare' values if the current
 * element is smaller than 'min_num'.
 * Returns 1 if validation is successful.
 *
 * @param data A pointer to the t_data structure
 * containing stack 'a' and metadata.
 * @return 1 if the validation passes, 0 if sorting is not possible.
 */
int	validate_and_set_moves(t_data *data)
{
	if (data->compare != data->i.i)
	{
		data->sorted_flag++;
		if (data->sorted_flag == 2)
			return (0);
		if (data->a[data->i.i][0] < data->min_num)
		{
			data->moves = data->i.i;
			data->compare = data->i.i;
		}
		else
			return (0);
	}
	return (1);
}

/**
 * @brief Checks if stack 'a' is sorted in
 * ascending order and performs necessary rotations.
 *
 * This function iterates through stack 'a'
 * to check if it is sorted in ascending order.
 * It tracks the minimum element and calculates
 * the moves needed to bring it to the top.
 * The function uses `validate_and_set_moves()`
 * for additional validation and returns 0
 * if the stack is not sorted. If the 'moves'
 * value is greater than 0, it rotates the stack
 * to achieve the correct order.
 *
 * @param data A pointer to the t_data structure
 * containing stack 'a' and its metadata.
 * @return 1 if the stack is sorted or successfully
 * rotated into a sorted state, 0 otherwise.
 */
int	check_for_sorted(t_data *data)
{
	data->i.i = 0;
	data->min_num = data->a[0][VALUE];
	while (data->i.i < data->numcount - 1)
	{
		if (data->a[data->i.i][VALUE] < data->a[data->i.i + 1][VALUE])
		{
			if (data->sorted_flag == 1)
				data->max_num = data->a[data->i.i + 1][VALUE];
			data->compare++;
		}
		data->i.i++;
		if (!(validate_and_set_moves(data)))
			return (0);
	}
	if (data->max_num > data->min_num)
		return (0);
	if (data->moves > 0)
		rotate_sorted_stack(data);
	return (1);
}
