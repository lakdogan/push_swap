/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:43:10 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:04:59 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/inc/libft.h"

/* Macros */
# define FALSE 0
# define TRUE 1
# define VALUE 0
# define RANK 1
# define RANKED 2

/* Structures */
typedef struct s_v
{
	int		i;
	int		j;
	int		l;
	int		k;
	int		m;
}			t_v;

typedef struct s_data
{
	int		**a;
	int		**b;
	int		argc;
	int		numcount;
	char	**nums;
	int		top_a;
	int		top_b;
	int		bot_a;
	int		bot_b;
	int		sa_sb_flag;
	int		ra_rb_flag;
	int		rra_rrb_flag;
	int		operation_count;
	int		moves;
	int		compare;
	int		min_num;
	int		max_num;
	int		sorted_flag;
	int		min_num_index;
	int		max_num_index;
	int		rank;
	int		next_min_num;
	int		next_max_num;
	int		ranked;
	int		value;
	int		current_min_rank;
	int		current_max_rank;
	int		ranked_count;
	int		values_are_not_ranked;
	int		temp_value;
	int		temp_rank;
	int		data_current_numcount;
	int		*length;
	int		*sum;
	int		*previous;
	int		n;
	int		to_push;
	int		min_pos;
	int		half;
	int		steps;
	int		target;
	t_v		i;
}			t_data;

/* Main function */
int			main(int argc, char **argv);

/* Initialization functions */
void		initialization_structs(t_data *data, int argc);
void		init_itterators(t_data *data);
void		init_top_b(t_data *data);

/* Validation functions */
void		validate_input(int argc, char **argv, t_data *data);
void		validate_unique_numbers(t_data *data);

/* Error handling */
void		error(char *msg);
void		error_memory_allocation(t_data *data);

/* Utilities */
long long	ft_strtoll(const char *str, char **endptr, int base);
int			ft_isspace(unsigned char c);
int			ft_count_current_numcount(int **array, int initial_numcount);
double		ft_sqrt(double x, double epsilon);
void		check_flag_print_op(t_data *data, char *op);
int			stack_len(int **array, int base, int max);
void		print_status(t_data *data);
void		print(t_data *data, char *op);

/* Memory management */
void		ft_free_string(char **string);
void		ft_free_int_array(int **array, int size);
void		free_all(t_data *data);
void		free_int(t_data *data);
int			**ft_allocate_int_array(int size);
void		allocate_a_and_b(t_data *data);
int			ft_set_int_value(int **array, int index, int value, int rank);
void		ft_del_int_value(int **array, int index);

/* Parsing */
void		split_numbers_by_argc(t_data *data, char **argv, int argc);
void		split_numbers_by_one_argv(t_data *data, char **argv, int argc);

/* Sorting algorithms */
void		sort_two(t_data *data);
void		sort_three(t_data *data);
void		sort_under_seven(t_data *d);
void		sort_descending_sorted_nums(t_data *data);
void		sort_chunks(t_data *d);

/* Statistics */
void		rank_transformation(t_data *data);
void		find_min_value_and_prepare(t_data *data);

/* Checker functions */
int			check_for_reverse_sorted(t_data *data);
int			check_for_sorted(t_data *data);

/* Stack operations */
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		swap_both(t_data *data);

void		push_a(t_data *data);
void		push_b(t_data *data);

void		rotate_a(t_data *data);
void		rotate_b(t_data *data);
void		rotate_both(t_data *data);

void		reverse_rotate_a(t_data *data);
void		reverse_rotate_b(t_data *data);
void		reverse_rotate_both(t_data *data);

#endif