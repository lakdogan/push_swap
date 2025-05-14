/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:52:05 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:45:57 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

/**
 * @brief Determines and applies the appropriate sorting algorithm
 *
 * This function selects the optimal sorting strategy based on the number of
 * elements in the stack. It has specialized implementations for small stacks
 * and a chunk-based approach for larger stacks.
 *
 * @param data Pointer to the data structure 
 * containing stacks and sorting information
 */
static void	handle_sorting(t_data *data)
{
	if (check_for_sorted(data))
		return ;
	else if (data->numcount == 2)
		sort_two(data);
	else if (data->numcount == 3)
		sort_three(data);
	else if (data->numcount <= 6)
		sort_under_seven(data);
	else if (check_for_reverse_sorted(data))
	{
		sort_descending_sorted_nums(data);
		return ;
	}
	else
		sort_chunks(data);
}

/**
 * @brief Main function of the push_swap program
 *
 * Initializes data structures, validates input arguments, processes numbers,
 * performs sorting operations, and cleans up allocated memory.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return 0 on successful execution
 */
int	main(int argc, char **argv)
{
	t_data	data;

	initialization_structs(&data, argc);
	validate_input(argc, argv, &data);
	split_numbers_by_one_argv(&data, argv, argc);
	init_top_b(&data);
	validate_unique_numbers(&data);
	rank_transformation(&data);
	handle_sorting(&data);
	free_all(&data);
	return (0);
}

// // check function for systemleaks
// void	systeminf(void)
// {
// 	system("leaks push_swap");
// }
// // print function to check the stacks
// void	print_less(t_data *data)
// {
// 	data->i.i = 0;
// 	printf("NUMBERS IN STACK A:\n");
// 	while (data->i.i < data->numcount)
// 	{
// 		if (data->a[data->i.i] != NULL)
// 			printf("%i | ", data->a[data->i.i][VALUE]);
// 		data->i.i++;
// 	}
// 	data->i.i = 0;
// 	printf("\nNUMBERS IN STACK B:\n");
// 	while (data->i.i < data->numcount)
// 	{
// 		if (data->b[data->i.i] != NULL)
// 			printf("%i | ", data->b[data->i.i][VALUE]);
// 		data->i.i++;
// 	}
// 	printf("\n");
// }