/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:42:56 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:52:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Executes the specified stack operation
 *
 * @param data Pointer to the data structure containing stacks
 * @param op String containing the operation to execute
 * @return int 1 if operation was executed successfully,
 *  0 if operation is invalid
 */
static int	execute_operation(t_data *data, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap_a(data);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap_b(data);
	else if (!ft_strncmp(op, "ss\n", 3))
		swap_both(data);
	else if (!ft_strncmp(op, "pa\n", 3))
		push_a(data);
	else if (!ft_strncmp(op, "pb\n", 3))
		push_b(data);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate_a(data);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate_b(data);
	else if (!ft_strncmp(op, "rr\n", 3))
		rotate_both(data);
	else if (!ft_strncmp(op, "rra\n", 4))
		reverse_rotate_a(data);
	else if (!ft_strncmp(op, "rrb\n", 4))
		reverse_rotate_b(data);
	else if (!ft_strncmp(op, "rrr\n", 4))
		reverse_rotate_both(data);
	else
		return (0);
	return (1);
}

/**
 * @brief Initialize and set up the stacks with input data
 *
 * @param data Pointer to the data structure containing stacks
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 */
static void	setup_stacks(t_data *data, int argc, char **argv)
{
	initialization_structs(data, argc);
	validate_input(argc, argv, data);
	split_numbers_by_one_argv(data, argv, argc);
	init_top_b(data);
	validate_unique_numbers(data);
	rank_transformation(data);
}

/**
 * @brief Read and process operations from standard input
 *
 * @param data Pointer to the data structure containing stacks
 */
static void	process_operations(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(data, line))
		{
			free(line);
			write(2, "Error\n", 6);
			free_all(data);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

/**
 * @brief Main function the checker that sets up stacks, 
 * processes operations, and verifies sorting
 * 
 * usage of the checker: 
 * ARG="51 21 33 5 1 56"; ./push_swap $ARG | ./checker $ARG
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return int 0 on successful execution
 */
int	main(int argc, char **argv)
{
	t_data	data;

	setup_stacks(&data, argc, argv);
	ft_printf("\nINITIAL STACKS:\n");
	ft_printf("\nX == empty slot\n\n");
	print_status(&data);
	process_operations(&data);
	if (check_for_sorted(&data))
		write(1, "\nOK\n", 3);
	else
		write(1, "\nKO\n", 3);
	free_all(&data);
	return (0);
}
