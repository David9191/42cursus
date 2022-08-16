/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:01:47 by jislim            #+#    #+#             */
/*   Updated: 2022/08/12 22:04:22 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	struct timeval	starttime, endtime;

	printf("Hello world!\n");
	starttime.tv_sec = gettimeofday(&starttime, NULL);
	printf("%ld\n", starttime.tv_sec);
	endtime.tv_sec = gettimeofday(&endtime, NULL);
	printf("%ld\n", endtime.tv_sec);
}