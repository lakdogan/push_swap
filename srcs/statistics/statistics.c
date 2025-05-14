/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:37:12 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:22:31 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Finds the minimum value in the array that hasn't been ranked yet
 *        and marks it as ranked.
 * 
 * This function initializes iterators, then searches through the array 'a'
 * in the data structure to find the smallest unranked value. Once found,
 * it marks this value as ranked and updates the min_num_index to track
 * the position of the minimum value.
 * 
 * @param data Pointer to the t_data structure containing the array and
 *             tracking variables for the ranking process
 * 
 * @return void
 * 
 * @note The function assumes that the data structure is properly initialized
 *       with valid values for numcount and other required fields.
 */
void	find_min_value_and_prepare(t_data *data)
{
	init_itterators(data);
	data->min_num = INT_MAX;
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i][RANKED] == FALSE)
		{
			if (data->a[data->i.i][VALUE] <= data->min_num)
			{
				data->min_num = data->a[data->i.i][VALUE];
				data->a[data->min_num_index][data->ranked] = FALSE;
				data->min_num_index = data->i.i;
				data->a[data->i.i][data->ranked] = TRUE;
			}
		}
		data->i.i++;
	}
	data->a[data->min_num_index][RANKED] = TRUE;
}
