/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:03:05 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/07/02 11:17:00 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printfp(unsigned long long n)
{
	if (n == 0)
		return (ft_printfs("nil"));
	return (ft_printfs("0x") + ft_printfx(n, HEXMIN));
}

int	ft_printfn(int n)
{
	if (n == INT_MIN)
		return (ft_printfs("-2147483648"));
	if (n < 0)
		return (ft_printfc('-') + ft_printfn(-n));
	if (n < 10)
		return (ft_printfc(n + 48));
	return (ft_printfn(n / 10) + ft_printfc(n % 10 + 48));
}

int	ft_printfs(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printfun(unsigned int n)
{
	if (n < 10)
		return (ft_printfc((char)(n % 10 + 48)));
	return (ft_printfun(n / 10) + ft_printfc((char)(n % 10 + 48)));
}

int	ft_printfx(unsigned long long n, char *base)
{
	if (n < 16)
		return (ft_printfc(base[n % 16]));
	return (ft_printfx(n / 16, base) + ft_printfc(base[n % 16]));
}
