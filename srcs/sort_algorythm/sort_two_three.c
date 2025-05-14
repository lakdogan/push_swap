/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:07:00 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:49:06 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Sorts two elements in stack A in ascending order
 *
 * If the top element has a greater value than the element below it,
 * performs a rotation to place them in ascending order.
 *
 * @param d Pointer to the data structure containing stacks and their information
 */
void	sort_two(t_data *d)
{
	if (d->a[d->top_a][VALUE] > d->a[d->top_a + 1][VALUE])
		rotate_a(d);
}

/**
 * @brief Sorts three elements in stack A in ascending order
 *
 * Uses a series of conditional checks 
 * to determine the optimal sequence of operations
 * (swap, rotate, reverse rotate) needed to
 *  sort three elements based on their rank.
 * Handles all possible permutations of 
 * three elements to arrange them in ascending order.
 *
 * @param d Pointer to the data structure containing stacks and their information
 */
void	sort_three(t_data *d)
{
	int	b;
	int	x;
	int	y;
	int	z;

	b = d->top_a;
	x = d->a[b][RANK];
	y = d->a[b + 1][RANK];
	z = d->a[b + 2][RANK];
	if (x > y && y < z && x < z)
		swap_a(d);
	else if (x > y && y > z)
	{
		swap_a(d);
		reverse_rotate_a(d);
	}
	else if (x > y && y < z && x > z)
		rotate_a(d);
	else if (x < y && y > z && x < z)
	{
		swap_a(d);
		rotate_a(d);
	}
	else if (x < y && y > z && x > z)
		reverse_rotate_a(d);
}
