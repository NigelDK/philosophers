/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:35:18 by nde-koni          #+#    #+#             */
/*   Updated: 2021/06/26 20:13:17 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static int	init_0(char **av, t_philo *s)
{
	long	tmp;

	tmp = ft_atol(av[1]);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (ARGERR);
	s->nr_of_philo = tmp;
	tmp = ft_atol(av[2]);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (ARGERR);
	s->time_to_die = tmp;
	tmp = ft_atol(av[3]);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (ARGERR);
	s->time_to_eat = tmp;
	tmp = ft_atol(av[4]);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (ARGERR);
	s->time_to_sleep = tmp;
	s->philo_nr = 1;
	s->death = 0;
	s->end.tv_sec = 0;
	s->end.tv_usec = 0;
	s->all_meals = 0;
	return (0);
}

static int	init_1(int ac, char **av, t_philo *s)
{
	long	tmp;

	if (ac == 6)
	{
		tmp = ft_atol(av[5]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (ARGERR);
		if (tmp == -1)
			tmp = -2;
		s->times_to_eat = tmp;
		s->eat_limit = 1;
	}
	else
	{
		s->times_to_eat = -1;
		s->eat_limit = 0;
	}
	return (0);
}

static int	init_2(t_philo *s)
{
	int	i;

	s->forks = malloc(sizeof(pthread_mutex_t) * s->nr_of_philo);
	if (!s->forks)
		return (MALERR);
	s->th = malloc(sizeof(pthread_t) * s->nr_of_philo);
	if (!s->th)
	{
		free(s->forks);
		return (MALERR);
	}
	i = 0;
	while (i < s->nr_of_philo)
		pthread_mutex_init(&s->forks[i++], NULL);
	pthread_mutex_init(&s->msg, NULL);
	return (0);
}

static int	invalid_nrs(t_philo s)
{
	if (s.nr_of_philo < 0 || s.time_to_die < 0 || s.time_to_eat < 0
		|| s.time_to_sleep < 0 || s.times_to_eat < -1)
		return (1);
	return (0);
}

int	init_struct(int ac, char **av, t_philo *s)
{
	if (init_0(av, s))
		return (ARGERR);
	if (init_1(ac, av, s))
		return (ARGERR);
	if (init_2(s))
		return (MALERR);
	if (invalid_nrs(*s))
		return (ARGERR);
	return (0);
}
