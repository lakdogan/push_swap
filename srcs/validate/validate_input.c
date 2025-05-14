/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:35:24 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:43:13 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Validates the number of command-line arguments.
 *
 * Checks if only the program name is provided (i.e., argc equals 1). 
 * If so, the program exits with EXIT_SUCCESS. 
 * Otherwise, the function returns 1,
 * indicating that there are additional arguments to process.
 *
 * @param argc The number of command-line arguments.
 * @return Always returns 1 when more than one argument is provided.
 */
static int	validate_argc(int argc)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	return (1);
}

/**
 * @brief Validates that each character in the 
 * input arguments is numeric.
 *
 * Iterates over each argument (starting from index 1), 
 * skipping any spaces.
 * It handles optional '+' or '-' signs and confirms 
 * that the remaining characters
 * are digits. If any non-numeric character is encountered, 
 * the function reports an error.
 *
 * @param argv Array of input argument strings.
 * @param data Pointer to the t_data structure containing iterators.
 */
static void	validate_isdigit(char **argv, t_data *data)
{
	data->i.i = 1;
	while (argv[data->i.i])
	{
		data->i.j = 0;
		while (argv[data->i.i][data->i.j])
		{
			while (argv[data->i.i][data->i.j] == ' ')
				data->i.j++;
			if (argv[data->i.i][data->i.j] == '-'
				|| argv[data->i.i][data->i.j] == '+')
				data->i.j++;
			if (!ft_isdigit(argv[data->i.i][data->i.j]))
				error("ERROR: non numeric argument.");
			while (ft_isdigit(argv[data->i.i][data->i.j]))
				data->i.j++;
			if (argv[data->i.i][data->i.j] != ' '
				&& argv[data->i.i][data->i.j] != '\0')
				error("ERROR: non numeric argument.");
			while (argv[data->i.i][data->i.j] == ' ')
				data->i.j++;
		}
		data->i.i++;
	}
}

/**
 * @brief Validates that each argument represents a 
 * number within the int range.
 *
 * Converts each argument (except the program name) 
 * to a long long integer using ft_strtoll
 * and checks if it falls within the limits of a standard int. 
 * If any number is out of range,
 * an error is reported.
 *
 * @param argv Array of input argument strings.
 * @param data Pointer to the t_data structure 
 * containing iterators and argc.
 */
static void	validate_in_range_of_int(char **argv, t_data *data)
{
	long long	num;
	char		*endptr;

	data->i.i = 1;
	while (data->i.i < data->argc)
	{
		num = ft_strtoll(argv[data->i.i], &endptr, 10);
		if (num > INT_MAX || num < INT_MIN)
			error("ERROR: int overflow!");
		data->i.i++;
	}
}

/**
 * @brief Validates that each number in a single string argument
 * is within the int range.
 *
 * When only one argument is provided (excluding the program name), 
 * this function splits
 * the argument into separate tokens (using spaces as delimiters) 
 * and validates that each token
 * converts to a number within the standard int limits. 
 * If any number exceeds these limits,
 * the function reports an error and frees allocated memory.
 *
 * @param argv Array of input argument strings.
 * @param data Pointer to the t_data structure that stores 
 * the split numbers.
 */
static void	validate_in_range_of_int_one_arg(char **argv, t_data *data)
{
	long long	num;
	char		*endptr;

	data->nums = ft_split(argv[1], ' ');
	if (!data->nums)
		exit(EXIT_FAILURE);
	data->i.i = 0;
	while (data->nums[data->i.i])
	{
		num = ft_strtoll(data->nums[data->i.i], &endptr, 10);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_free_string(data->nums);
			error("ERROR: int overflow!");
		}
		data->i.i++;
	}
	ft_free_string(data->nums);
}

/**
 * @brief Performs comprehensive validation of the command-line input.
 *
 * This function serves as the entry point for validating input. 
 * It performs several checks:
 *  - Validates the argument count and initializes iterators.
 *  - Ensures each input character is numeric.
 *  - Checks that each number is within the range of a standard int.
 * For a single argument that potentially contains multiple numbers, 
 * the function splits the
 * string before performing range validation.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of input argument strings.
 * @param data Pointer to the t_data structure containing program 
 * state and iterators.
 */
void	validate_input(int argc, char **argv, t_data *data)
{
	validate_argc(argc);
	validate_isdigit(argv, data);
	if (argc == 2)
		validate_in_range_of_int_one_arg(argv, data);
	else
		validate_in_range_of_int(argv, data);
}
