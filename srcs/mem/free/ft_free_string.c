/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:58:38 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 08:36:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees a dynamically allocated array of strings.
 *
 * Iterates through the array, freeing each individual
 * string and setting its pointer to NULL.
 * Finally, frees the array itself. If the provided pointer
 * is NULL, the function does nothing.
 *
 * @param string Pointer to the array of strings to free.
 */
void	ft_free_string(char **string)
{
	int	i;

	if (!string)
		return ;
	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	free(string);
}
