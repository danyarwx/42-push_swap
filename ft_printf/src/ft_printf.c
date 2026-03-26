/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:16:33 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/26 23:12:47 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(char c, va_list *p_args)
{
	long	n;

	if (c == 'c')
		return (ft_putchar_arg(p_args));
	else if (c == 's')
		return (ft_putstr_arg(p_args));
	else if (c == 'p')
		return (ft_putptr(p_args));
	else if (c == 'd' || c == 'i')
	{
		n = va_arg(*p_args, int);
		return (ft_putnbr_arg(n), ft_intlen(n));
	}
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		n = va_arg(*p_args, unsigned int);
		if (c == 'x' || c == 'X')
			return (ft_puthex(n, c), ft_hexlen(n));
		else
			return (ft_put_unbr(n), ft_uintlen(n));
	}
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		total;
	va_list	args;

	va_start(args, s);
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			total++;
		}
		else
		{
			total += ft_switch(s[++i], &args);
		}
		i++;
	}
	return (va_end(args), total);
}
