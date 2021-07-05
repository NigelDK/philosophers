/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:02:42 by nde-koni          #+#    #+#             */
/*   Updated: 2021/06/26 19:40:18 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	free_all(t_philo *s)
{
	int	i;

	i = 0;
	while (i < s->nr_of_philo)
		pthread_mutex_destroy(&s->forks[i++]);
	free(s->forks);
	free(s->th);
}
