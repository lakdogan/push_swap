/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:33:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 10:31:48 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Splits numbers provided as separate command-line arguments.
 *
 * This function calculates the number of numeric arguments 
 * by subtracting 1 from @p argc,
 * allocates memory for the arrays used to store the numbers, 
 * and then iterates over each
 * argument (starting at index 1) to convert it from a string to an integer. 
 * The conversion is performed by @p ft_atoi, and the resulting value 
 * is stored using @p ft_set_int_value.
 *
 * @param data Pointer to the t_data structure containing application state.
 * @param argv Array of input argument strings.
 * @param argc Total number of command-line arguments.
 */
void	split_numbers_by_argc(t_data *data, char **argv, int argc)
{
	data->numcount = argc - 1;
	allocate_a_and_b(data);
	while (data->i.i < data->numcount)
	{
		ft_set_int_value(data->a, data->i.k, ft_atoi(argv[data->i.i + 1]), 0);
		data->i.i++;
		data->i.k++;
	}
}

/**
 * @brief Splits numbers from a single argument string or multiple arguments.
 *
 * This function first initializes iterators and then determines 
 * whether the input consists of a single argument containing multiple 
 * numbers (separated by spaces) or multiple arguments. For a
 * single argument, it splits the string using spaces as delimiters,
 * counts the resulting tokens, allocates memory for the number arrays,
 * and converts each token to an integer using @p ft_atoi.
 * For multiple arguments, it delegates the processing 
 * to @p split_numbers_by_argc.
 *
 * @param data Pointer to the t_data structure containing application state.
 * @param argv Array of input argument strings.
 * @param argc Total number of command-line arguments.
 */
void	split_numbers_by_one_argv(t_data *data, char **argv, int argc)
{
	init_itterators(data);
	if (argc == 2)
	{
		data->nums = ft_split(argv[1], ' ');
		if (!data->nums)
			exit(EXIT_FAILURE);
		while (data->nums[data->numcount])
			data->numcount++;
		allocate_a_and_b(data);
		while (data->nums[data->i.j])
		{
			ft_set_int_value
				(data->a, data->i.j, ft_atoi(data->nums[data->i.j]), 0);
			data->i.j++;
		}
		ft_free_string(data->nums);
	}
	else
		split_numbers_by_argc(data, argv, argc);
}
