/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:08 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:07:28 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	reverse_rotate_a(t_data *data)
{
	data->data_current_numcount = ft_count_current_numcount(data->a,
			data->numcount);
	if (data->data_current_numcount == 0)
		return ;
	data->temp_value = data->a[data->top_a + data->data_current_numcount
		- 1][VALUE];
	data->temp_rank = data->a[data->top_a + data->data_current_numcount
		- 1][RANK];
	data->i.i = 1;
	while (data->i.i < data->data_current_numcount)
	{
		data->a[data->top_a + data->data_current_numcount
			- data->i.i][VALUE] = data->a[data->top_a
			+ data->data_current_numcount - data->i.i - 1][VALUE];
		data->a[data->top_a + data->data_current_numcount
			- data->i.i][RANK] = data->a[data->top_a
			+ data->data_current_numcount - data->i.i - 1][RANK];
		data->i.i++;
	}
	data->a[data->top_a][VALUE] = data->temp_value;
	data->a[data->top_a][RANK] = data->temp_rank;
	print(data, "rra");
}
