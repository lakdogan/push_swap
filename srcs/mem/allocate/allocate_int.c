/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:57:12 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:34:37 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Allocates memory for integer arrays within the t_data structure
 *
 * @param data Pointer to the t_data structure to allocate memory for
 * @details Allocates memory for three integer arrays (length, sum, and previous)
 *         within the provided data structure. Each array is allocated with 
 *         size equal to data->numcount elements.
 * @note Exits the program with EXIT_FAILURE if any memory allocation fails
 */
void	allocate_int(t_data *data)
{
	data->length = malloc(sizeof(int) * data->numcount);
	data->sum = malloc(sizeof(int) * data->numcount);
	data->previous = malloc(sizeof(int) * data->numcount);
	if (!data->length || !data->previous || !data->sum)
		exit(EXIT_FAILURE);
}
