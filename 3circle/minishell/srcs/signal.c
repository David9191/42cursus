/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:55:25 by seuhan            #+#    #+#             */
/*   Updated: 2022/07/19 16:35:23 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrl_c(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd(ft_strjoin(rl_prompt, rl_line_buffer), 2);
		ft_putstr_fd("  \b\b", 2);
		rl_redisplay();
		g_rvalue = 1;
		ft_putendl_fd("", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_do_nothing(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putstr_fd(ft_strjoin(rl_prompt, rl_line_buffer), 2);
		ft_putstr_fd("  \b\b", 2);
		rl_redisplay();
	}
}

void	ft_ctrl_c_h(int signal)
{
	if (signal == SIGINT)
	{
		g_rvalue = 131;
		ft_putstr_fd("\n", 2);
	}
}

void	ft_ctrl_c_fork(int signal)
{
	(void) signal;
	ft_putchar_fd('\n', 2);
	g_rvalue = 130;
}

void	sig_exit(int signal)
{
	(void) signal;
	if (signal == SIGINT)
		exit(1);
}
