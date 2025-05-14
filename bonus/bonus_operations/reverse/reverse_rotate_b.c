/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:20 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:07:01 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	reverse_rotate_b(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->b,
			data->numcount);
	if (data->data_current_numcount == 0)
		return ;
	data->temp_value = data->b[data->top_b
		+ data->data_current_numcount][VALUE];
	data->temp_rank = data->b[data->top_b + data->data_current_numcount][RANK];
	data->i.i = 0;
	while (data->i.i < data->data_current_numcount - 1)
	{
		data->b[data->top_b + data->data_current_numcount
			- data->i.i][VALUE] = data->b[data->top_b
			+ data->data_current_numcount - data->i.i - 1][VALUE];
		data->b[data->top_b + data->data_current_numcount
			- data->i.i][RANK] = data->b[data->top_b
			+ data->data_current_numcount - data->i.i - 1][RANK];
		data->i.i++;
	}
	data->b[data->top_b + 1][VALUE] = data->temp_value;
	data->b[data->top_b + 1][RANK] = data->temp_rank;
	print(data, "rrb");
}
