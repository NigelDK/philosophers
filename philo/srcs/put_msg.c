/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:03:23 by nde-koni          #+#    #+#             */
/*   Updated: 2021/06/26 19:58:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0 || *s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_nr_len(int n)
{
	int			len;
	long int	nr;

	nr = n;
	len = 0;
	if (nr == 0)
		return (1);
	if (nr < 0)
	{
		nr = nr * -1;
		len++;
	}
	while (nr > 0)
	{
		nr /= 10;
		len++;
	}
	return (len);
}

int	nr_is_zero(long int nr, char **str)
{
	if (nr == 0)
	{
		str[0][0] = 48;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nr;

	nr = n;
	i = ft_nr_len(nr);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nr_is_zero(nr, &str))
		return (str);
	if (nr < 0)
	{
		str[0] = '-';
		nr *= -1;
	}
	while (nr > 0)
	{
		str[i--] = 48 + (nr % 10);
		nr /= 10;
	}
	return (str);
}

void	put_msg(int i0, int i1, char *s)
{
	char	*s0;
	char	*s1;

	s0 = ft_itoa(i0);
	s1 = ft_itoa(i1);
	write(1, s0, ft_strlen(s0));
	write(1, " ", 1);
	write(1, s1, ft_strlen(s1));
	write(1, s, ft_strlen(s));
}
