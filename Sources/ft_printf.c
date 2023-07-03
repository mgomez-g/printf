/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:07:50 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/06/08 17:08:20 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ret += ft_printfselect(*(++format), args);
		else
			ret += ft_printfc(*format);
		format++;
	}
	va_end(args);
	return (ret);
}

int	ft_printfselect(char c, va_list args)
{
	if (c == 'c')
		return (ft_printfc(va_arg(args, int)));
	else if (c == 's')
		return (ft_printfs(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printfn(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printfun(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printfx(va_arg(args, unsigned int), HEXMIN));
	else if (c == 'X')
		return (ft_printfx(va_arg(args, unsigned int), HEXMAX));
	else if (c == 'p')
		return (ft_printfp(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (ft_printfc('%'));
	return (0);
}

int	ft_printfc(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
