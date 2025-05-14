/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:01:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:21:50 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Sets the ranked flag to FALSE for all elements in the data array
 *
 * This function iterates through all elements in data->a and sets their 
 * ranked status to FALSE, preparing the array for ranking operations.
 *
 * @param data Pointer to the data structure containing the array and counters
 */
void	set_all_ranked_to_false(t_data *data)
{
	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		data->a[data->i.i][data->ranked] = FALSE;
		data->i.i++;
	}
}

/**
 * @brief Performs rank transformation on the data
 *
 * This function converts the original values in the array to their respective
 * ranks (1-based). It works by repeatedly finding the minimum unranked value,
 * assigning it the next rank, and marking it as ranked until all values
 * have been processed.
 *
 * @param data Pointer to the data structure containing the array and counters
 */
void	rank_transformation(t_data *data)
{
	int	i;

	set_all_ranked_to_false(data);
	data->current_min_rank = 1;
	data->ranked_count = 0;
	i = 0;
	while (i < data->numcount)
	{
		find_min_value_and_prepare(data);
		data->a[data->min_num_index][RANK] = data->current_min_rank;
		data->a[data->min_num_index][RANKED] = TRUE;
		data->current_min_rank++;
		data->ranked_count++;
		data->min_num = data->a[data->min_num_index][VALUE] + 1;
		++i;
	}
}
