/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:07:46 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	switch_both_numbers(t_data *data)
{
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->b[data->top_b + 1][VALUE] = data->b[data->top_b
		+ data->data_current_numcount][VALUE];
	data->b[data->top_b
		+ data->data_current_numcount][VALUE] = data->temp_value;
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->b[data->top_b + 1][RANK] = data->b[data->top_b
		+ data->data_current_numcount][RANK];
	data->b[data->top_b + data->data_current_numcount][RANK] = data->temp_rank;
	check_flag_print_op(data, "rb");
}

void	pass_value_and_rank(t_data *data)
{
	data->b[data->top_b + data->i.j][VALUE] = data->b[data->top_b + data->i.j
		+ 1][VALUE];
	data->b[data->top_b + data->i.j][RANK] = data->b[data->top_b + data->i.j
		+ 1][RANK];
}

void	rotate_b(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->b,
			data->numcount);
	if (data->data_current_numcount <= 1)
		return ;
	if (data->data_current_numcount == 2)
	{
		switch_both_numbers(data);
		return ;
	}
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->i.j = 1;
	while (data->i.j < data->data_current_numcount)
	{
		if (data->b[data->top_b + data->i.j + 1] != NULL)
		{
			pass_value_and_rank(data);
		}
		data->i.j++;
	}
	data->b[data->numcount - 1][VALUE] = data->temp_value;
	data->b[data->numcount - 1][RANK] = data->temp_rank;
	print(data, "rb");
}
