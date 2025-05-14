/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_descending_sorted_nums.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 07:41:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:31:33 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Sorts a descending-sorted stack of
 * numbers using my custom approach.
 *
 * This function sorts a stack that is
 * initially sorted in descending order by:
 *
 * - Performing reverse rotations and pushing
 * elements to a temporary stack 'b'.
 *
 * - Swapping the top elements and
 * applying a final reverse rotation.
 *
 * - Pushing elements back to stack 'a'
 * to complete the sorting process.
 *
 * This method is my custom approach and
 * not a traditional Push Swap algorithm,
 * but it utilizes similar operations
 * effectively to achieve the desired sort.
 *
 * @param data A pointer to the t_data structure
 * containing the stack and metadata.
 */
void	sort_descending_sorted_nums(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->numcount - 3)
	{
		reverse_rotate_a(data);
		push_b(data);
		index++;
	}
	swap_a(data);
	reverse_rotate_a(data);
	if (index == 0)
		push_a(data);
	while (index--)
	{
		push_a(data);
	}
}
