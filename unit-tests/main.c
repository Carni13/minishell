/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:01:04 by ngiroux           #+#    #+#             */
/*   Updated: 2022/02/08 15:09:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libunit.h"
#include "minishell.h"


int	main(int ac, char **av, char **envp)
{
	t_score	score;
	
	(void)ac;
	(void)av;
	(void)envp;
	
	score.ok = 0;
	score.total = 0;
	__start();
	ft00_launcher(&score);
	ft01_launcher(&score);
	//ft02_launcher(&score);
	__print_global_summary(score.ok, score.total);
	if (score.ok == score.total)
		return (0);
	else
		return (-1);
}
