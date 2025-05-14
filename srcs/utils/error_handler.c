/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:22:35 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/01 08:21:07 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Prints an error message,
 * and terminates the program.
 *
 * This function outputs the provided error message to the
 * standard output using ft_putendl_fd,
 * and then exits the program with a
 * failure status (EXIT_FAILURE).
 *
 * @param msg The error message to be displayed.
 */
void	error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}
