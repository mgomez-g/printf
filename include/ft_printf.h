/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:06:28 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/06/09 11:43:39 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXMIN "0123456789abcdef"
# define HEXMAX "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_printfc(char c);
int		ft_printfselect(char c, va_list args);
int		ft_printfs(char *str);
int		ft_strlen(const char *str);
int		ft_printfn(int n);
int		ft_printfun(unsigned int n);
int		ft_printfx(unsigned long long n, char *base);
int		ft_printfp(unsigned long long n);

#endif
