/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:05:47 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:31 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, int *pt_i)
{
	write(1, &c, 1);
	*pt_i += 1;
}
