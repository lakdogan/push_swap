/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:17:29 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:14:08 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Find the element with the highest rank value in stack B
 *
 * @param d Pointer to the data structure containing stacks
 * @return The maximum rank value found in stack B
 */
static int	get_biggest_priority(t_data *d)
{
	int	max;
	int	r;
	int	i;

	max = d->b[d->top_b + 1][RANK];
	i = d->top_b + 2;
	while (i < d->numcount)
	{
		r = d->b[i][RANK];
		if (r > max)
			max = r;
		i++;
	}
	return (max);
}

/**
 * @brief Find the index of an element with a specific rank in stack B
 *
 * @param d Pointer to the data structure containing stacks
 * @param target The rank value to search for
 * @return The index of the element with the target rank, or -1 if not found
 */
static int	locate_priority_index(t_data *d, int target)
{
	int	i;

	i = d->top_b + 1;
	while (i < d->numcount)
	{
		if (d->b[i][RANK] == target)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Push elements from stack A to stack B based on rank ranges
 *
 * This function implements a chunking strategy where elements are moved
 * to stack B based on their rank relative to the target value and range.
 *
 * @param d Pointer to the data structure containing stacks
 * @param range The range of ranks to consider in each chunk
 * @param target The starting target rank value
 */
static void	push_chunks_to_b(t_data *d, int range, int target)
{
	int	rank;

	while (d->top_a < d->numcount)
	{
		rank = d->a[d->top_a][RANK];
		if (rank <= target)
		{
			push_b(d);
			rotate_b(d);
			target++;
		}
		else if (rank <= target + range)
		{
			push_b(d);
			target++;
		}
		else
			rotate_a(d);
	}
}

/**
 * @brief Sort elements in stack B and push them back to stack A
 *
 * This function finds the element with the highest rank in stack B,
 * moves it to the top using the most efficient rotation direction,
 * and pushes it to stack A until stack B is empty.
 *
 * @param d Pointer to the data structure containing stacks
 */
static void	sort_and_push_back(t_data *d)
{
	int	max_rank;
	int	idx;

	while (d->top_b != d->numcount - 1)
	{
		max_rank = get_biggest_priority(d);
		idx = locate_priority_index(d, max_rank);
		if (idx <= (d->top_b + 1 + d->numcount - 1) / 2)
		{
			while (d->b[d->top_b + 1][RANK] != max_rank)
				rotate_b(d);
		}
		else
		{
			while (d->b[d->top_b + 1][RANK] != max_rank)
				reverse_rotate_b(d);
		}
		push_a(d);
	}
}

/**
 * @brief Main sorting function implementing the chunk sort algorithm
 *
 * This function uses a chunk-based sorting approach where elements are first
 * divided into chunks and pushed to stack B, then sorted and pushed back
 * to stack A in the correct order.
 *
 * @param d Pointer to the data structure containing stacks
 */
void	sort_chunks(t_data *d)
{
	int	range;
	int	target;

	range = ((int)ft_sqrt(d->numcount, 0.001) * 14) / 10;
	target = 0;
	push_chunks_to_b(d, range, target);
	sort_and_push_back(d);
}
