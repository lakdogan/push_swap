/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_unique_nums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:51:49 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:45:58 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Validates that all numbers in the dataset are unique.
 *
 * Iterates through the array of numbers stored in 
 * @p data and checks each number
 * against all others for duplicates. The function compares 
 * the first element of each number representation (stored in @p data->a) 
 * and increments a counter if a match is found.
 * If any number is found more than once (i.e., the counter reaches 2), 
 * the function frees all allocated resources and reports an error.
 *
 * @param data Pointer to the t_data structure containing the 
 * numbers array and related metadata.
 */
void	validate_unique_numbers(t_data *data)
{
	int	unique_flag;

	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		unique_flag = 0;
		data->i.j = 0;
		while (data->i.j < data->numcount)
		{
			if (data->a[data->i.i][0] == data->a[data->i.j][0])
				unique_flag++;
			if (unique_flag == 2)
			{
				free_all(data);
				error("ERROR: duplicate numbers.");
			}
			data->i.j++;
		}
		data->i.i++;
	}
}
