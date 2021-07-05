/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:40:15 by nde-koni          #+#    #+#             */
/*   Updated: 2021/06/26 20:13:01 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static void	init(t_thread *thrd)
{
	thrd->philo_nr = thrd->s->philo_nr;
	thrd->last_eat = timestamp(thrd->s);
	thrd->times_eaten = 0;
	thrd->max_meals = 0;
	thrd->dead = 0;
}

static void	philo_life(t_thread *thrd)
{
	while (!thrd->s->death)
	{
		if (!thrd->s->death)
			to_fork(thrd);
		if (!thrd->s->death)
			to_eat(thrd);
		if (thrd->s->eat_limit && thrd->times_eaten == thrd->s->times_to_eat)
		{
			thrd->s->all_meals++;
			thrd->max_meals = 1;
			break ;
		}
		if (!thrd->s->death)
			to_sleep(thrd);
		if (!thrd->s->death)
			to_think(thrd);
	}
}

static void	*philo_birth(void *s)
{
	t_thread	thrd;
	pthread_t	reaper;
	int			ts;

	thrd.s = (t_philo *)s;
	init(&thrd);
	if (thrd.s->nr_of_philo == 1)
	{
		usleep(thrd.s->time_to_die * 1000);
		ts = timestamp(thrd.s);
		put_msg(ts, thrd.philo_nr, " died\n");
		thrd.s->death = 1;
		return (NULL);
	}
	if (pthread_create(&reaper, NULL, &to_die, &thrd))
	{
		thrd.s->err = THRERR;
		return (NULL);
	}
	philo_life(&thrd);
	pthread_join(reaper, NULL);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	s;
	int		i;

	gettimeofday(&s.start, NULL);
	if (ac != 5 && ac != 6)
		return (ARGERR);
	s.err = init_struct(ac, av, &s);
	if (s.err)
		return (s.err);
	i = -1;
	while (++i < s.nr_of_philo)
	{
		if (pthread_create(&s.th[i], NULL, &philo_birth, &s))
		{
			free_all(&s);
			return (THRERR);
		}
		pthread_detach(s.th[i]);
		usleep(100);
		s.philo_nr++;
	}
	while (!s.death && s.all_meals != s.nr_of_philo)
		usleep(1000);
	free_all(&s);
	return (s.err);
}
