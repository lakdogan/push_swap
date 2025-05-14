/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:38:07 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 13:38:21 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Initializes iterator values within the t_data structure.
 *
 * This function sets all iterator members (i, j, k, l, m) of the
 * nested iterator structure within t_data to zero.
 *
 * @param data Pointer to the t_data structure.
 */
void	init_itterators(t_data *data)
{
	data->i.i = 0;
	data->i.j = 0;
	data->i.k = 0;
	data->i.l = 0;
	data->i.m = 0;
}

/**
 * @brief Initializes primary fields of the t_data structure.
 *
 * This function initializes the main data structure by setting
 * stack pointers 'a' and 'b' to NULL,
 * storing the argument count, and initializing
 * other related fields to their default values.
 *
 * @param data Pointer to the t_data structure.
 * @param argc The number of command-line arguments.
 */
void	init_data(t_data *data, int argc)
{
	data->a = NULL;
	data->b = NULL;
	data->argc = argc;
	data->numcount = 0;
	data->top_a = 0;
	data->sa_sb_flag = 0;
	data->ra_rb_flag = 0;
	data->rra_rrb_flag = 0;
	data->operation_count = 0;
	data->moves = 0;
	data->compare = 0;
	data->min_num = INT_MAX;
	data->max_num = INT_MIN;
	data->sorted_flag = 0;
	data->min_num_index = 0;
	data->max_num_index = 0;
	data->rank = 1;
	data->length = NULL;
	data->sum = NULL;
	data->previous = NULL;
}

/**
 * @brief Initializes secondary fields of the t_data structure.
 *
 * This function sets up additional fields in the data structure
 * primarily related to ranking, sorting, and tracking minimum
 * and maximum values. It complements the init_data function by
 * initializing fields that weren't covered there.
 *
 * @param data Pointer to the t_data structure.
 */
void	init_data1(t_data *data)
{
	data->next_min_num = 0;
	data->next_max_num = 0;
	data->ranked = 3;
	data->value = 0;
	data->current_min_rank = 0;
	data->ranked_count = 0;
	data->values_are_not_ranked = 1;
	data->sorted_flag = 0;
	data->compare = 0;
	data->moves = 0;
	data->min_num = INT_MAX;
	data->max_num = INT_MIN;
}

/**
 * @brief Initializes the top index for stack 'b'.
 *
 * Sets the 'top_b' field of the t_data structure to
 * one less than the total number count,
 * representing the index of the top element in stack 'b'.
 *
 * @param data Pointer to the t_data structure.
 */
void	init_top_b(t_data *data)
{
	data->top_b = data->numcount - 1;
}

/**
 * @brief Performs complete initialization of t_data structures.
 *
 * This function consolidates the initialization process by
 * calling functions to initialize both the
 * iterators and the primary data fields.
 *
 * @param data Pointer to the t_data structure.
 * @param argc The number of command-line arguments.
 */
void	initialization_structs(t_data *data, int argc)
{
	init_itterators(data);
	init_data(data, argc);
	init_data1(data);
}
