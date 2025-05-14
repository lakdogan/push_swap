/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:59:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:36:51 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees memory allocated for integer arrays in the data structure
 *
 * This function deallocates memory for the length, previous, and sum arrays
 * that are part of the t_data structure.
 *
 * @param data Pointer to the t_data structure containing the arrays to be freed
 */
void	free_int(t_data *data)
{
	free(data->length);
	free(data->previous);
	free(data->sum);
}
