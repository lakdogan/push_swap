/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:00:56 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:45:41 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/**
 * @brief Prints the current content of stacks A and B
 *
 * This function displays all elements in both stacks, showing their values
 * or 'X' for empty positions.
 *
 * @param data Pointer to the data structure 
 * containing stacks and state information
 */
void	print_status(t_data *data)
{
	data->i.i = 0;
	ft_printf("NUMBERS IN STACK A:\n");
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i] != NULL)
			ft_printf("%i | ", data->a[data->i.i][VALUE]);
		else
			ft_printf("X | ");
		data->i.i++;
	}
	data->i.i = 0;
	ft_printf("\nNUMBERS IN STACK B:\n");
	while (data->i.i < data->numcount)
	{
		if (data->b[data->i.i] != NULL)
			ft_printf("%i | ", data->b[data->i.i][VALUE]);
		else
			ft_printf("X | ");
		data->i.i++;
	}
	ft_printf("\n");
}

/**
 * @brief Prints the current operation and the status of both stacks
 *
 * Increments the operation counter, displays the operation name and count,
 * then calls print_status to show the current state of both stacks.
 *
 * @param data Pointer to the data structure 
 * containing stacks and state information
 * @param op String containing the name of the operation being performed
 */
void	print(t_data *data, char *op)
{
	data->operation_count++;
	ft_printf("\n OPERATION: %s | OPERATION COUNT: %i\n", op,
		data->operation_count);
	print_status(data);
}
