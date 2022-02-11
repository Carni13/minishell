/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:25:57 by jremy             #+#    #+#             */
/*   Updated: 2022/02/11 12:04:53 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	__adjust_space(char *str, int i)
{
	i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	__create_new_token(char **str)
{
	*str = __strdup("");
	if (!*str)
		return (-1);
	return (1);
}