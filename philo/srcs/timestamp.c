/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:07:47 by nde-koni          #+#    #+#             */
/*   Updated: 2021/06/01 16:08:09 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int	timestamp(t_philo *s)
{
	int	ts;

	gettimeofday(&s->end, NULL);
	ts = (s->end.tv_sec * 1000 + s->end.tv_usec * 0.001)
		- (s->start.tv_sec * 1000 + s->start.tv_usec * 0.001);
	return (ts);
}
