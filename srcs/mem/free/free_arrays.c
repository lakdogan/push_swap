/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:40:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:36:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees the memory allocated for the numbers array.
 *
 * This function checks if the numbers array stored in
 * @p data->nums exists,
 * and if so, frees it using ft_free_string.
 *
 * @param data Pointer to the t_data structure containing
 * the numbers string array.
 */
void	free_nums(t_data *data)
{
	if (data->nums)
	{
		ft_free_string(data->nums);
		data->nums = NULL;
	}
}

/**
 * @brief Frees the memory allocated for both stacks.
 *
 * This function releases the memory allocated
 * for the integer arrays @p data->a and
 * @p data->b, which represent the stacks,
 * by calling ft_free_int_array on each with the
 * total number of elements given by @p data->numcount.
 *
 * @param data Pointer to the t_data structure
 * containing the stacks.
 */
void	free_stacks(t_data *data)
{
	if (data->a)
		ft_free_int_array(data->a, data->numcount);
	data->a = NULL;
	if (data->b)
		ft_free_int_array(data->b, data->numcount);
	data->b = NULL;
}

/**
 * @brief Frees the memory allocated for algorithm-related arrays.
 *
 * This function releases the memory allocated for the
 * @p data->length, @p data->sum, and @p data->previous arrays
 * used during algorithm execution, and sets their pointers to NULL.
 *
 * @param data Pointer to the t_data structure containing
 * the algorithm arrays.
 */
void	free_algorithm_arrays(t_data *data)
{
	if (data->length)
		free(data->length);
	if (data->sum)
		free(data->sum);
	if (data->previous)
		free(data->previous);
	data->length = NULL;
	data->sum = NULL;
	data->previous = NULL;
}

/**
 * @brief Frees all allocated resources.
 *
 * This function consolidates the freeing process by calling
 * @p free_algorithm_arrays to free algorithm-related arrays,
 * @p free_stacks to free stack arrays, and @p free_int
 * to free any remaining integer resources.
 *
 * @param data Pointer to the t_data structure containing
 * all allocated resources.
 */
void	free_all(t_data *data)
{
	free_algorithm_arrays(data);
	free_stacks(data);
	free_int(data);
}
