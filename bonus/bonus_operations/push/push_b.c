/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:37 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/04 12:17:20 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

void	push_b(t_data *data)
{
	if (data->top_a == data->numcount || data->top_b == -1)
		return ;
	ft_set_int_value(data->b, data->top_b, data->a[data->top_a][VALUE],
		data->a[data->top_a][RANK]);
	ft_del_int_value(data->a, data->top_a);
	data->top_a++;
	data->top_b--;
	print(data, "pb");
}
