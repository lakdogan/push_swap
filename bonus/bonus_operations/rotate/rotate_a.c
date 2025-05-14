/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:33 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:07:36 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	rotate_a(t_data *data)
{
	if (data->a[data->top_a] != NULL)
	{
		data->temp_value = data->a[data->top_a][VALUE];
		data->temp_rank = data->a[data->top_a][RANK];
	}
	else
		return ;
	data->i.i = 0;
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i] != NULL && data->i.i < data->numcount - 1
			&& data->a[data->i.i + 1] != NULL)
		{
			ft_del_int_value(data->a, data->i.i);
			ft_set_int_value(data->a, data->i.i, data->a[data->i.i + 1][VALUE],
				data->a[data->i.i + 1][RANK]);
		}
		data->i.i++;
	}
	if (data->a[data->numcount - 1] != NULL)
	{
		data->a[data->numcount - 1][VALUE] = data->temp_value;
		data->a[data->numcount - 1][RANK] = data->temp_rank;
	}
	print(data, "ra");
}
