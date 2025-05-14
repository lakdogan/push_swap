/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_current_numcount.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 01:59:01 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:26:45 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Counts the number of non-NULL elements in an array
 * 
 * This function iterates through the given array and counts how many 
 * elements are not NULL, up to the initial number count.
 * 
 * @param array The array to check
 * @param initial_numcount The maximum number of elements to check
 * @return The count of non-NULL elements in the array
 */
int	ft_count_current_numcount(int **array, int initial_numcount)
{
	int	current_numcount;
	int	index;

	current_numcount = 0;
	index = 0;
	while (index < initial_numcount)
	{
		if (array[index] != NULL)
			current_numcount++;
		index++;
	}
	return (current_numcount);
}

/**
 * @brief Measures the length of a continuous sequence in an array
 * 
 * This function counts the number of consecutive non-NULL elements in the array
 * starting from the base index and not exceeding the max index.
 * 
 * @param array The array to measure
 * @param base The starting index
 * @param max The maximum index (exclusive)
 * @return The number of consecutive non-NULL elements
 */
int	stack_len(int **array, int base, int max)
{
	int	n;

	n = 0;
	while (base + n < max && array[base + n] != NULL)
		++n;
	return (n);
}
