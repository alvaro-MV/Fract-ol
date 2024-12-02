/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:22:25 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:28:52 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	get_len(int nb)
{
	long	number;
	long	dec;

	number = (long) nb;
	dec = 1;
	if (number < 0)
		number *= -1;
	if (number == 0)
		dec *= 10;
	while (dec <= number)
		dec *= 10;
	return (dec / 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dlen;
	int		i;
	int		digit;
	long	lnb;
	char	printn;

	dlen = get_len(n);
	lnb = (long) n;
	i = 0;
	if (lnb < 0)
	{
		write(fd, "-", 1);
		lnb *= -1;
	}
	while (dlen > 0)
	{
		digit = lnb / dlen;
		printn = digit + '0';
		write(fd, &printn, 1);
		lnb -= digit * dlen;
		i = i + 1;
		dlen /= 10;
	}
}

// int	main()
// {
// 	int	n = 98298;
// 	int	fd;

// 	fd = open("pp.txt", O_WRONLY | O_TRUNC);
// 	ft_putnbr_fd(n, fd);
// }
