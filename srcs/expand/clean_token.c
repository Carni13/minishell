/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:51:57 by jremy             #+#    #+#             */
/*   Updated: 2022/04/08 10:27:30 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__treat_first(t_lexing **last, t_lexing **iter, t_lexing **lexing)
{
	*last = *lexing;
	*lexing = (*lexing)->next;
	free((*last)->token);
	free(*last);
	*iter = *lexing;
	*last = NULL;
}

void	__treat_other(t_lexing *last, t_lexing **iter)
{
	last->next = last->next->next;
	free((*iter)->token);
	free(*iter);
	*iter = last->next;
}

int	__clean_token(t_lexing **lexing)
{
	t_lexing	*iter;
	t_lexing	*last;

	iter = *lexing;
	last = NULL;
	while (iter)
	{
		if (iter->type == REDIRECTION && iter->next
			&& (iter->next->token)[0] == '\0')
			return (-1);
		if (iter->type == WORD && (iter->token)[0] == '\0')
		{
			if (last == NULL)
				__treat_first(&last, &iter, lexing);
			else
				__treat_other(last, &iter);
		}
		else
		{
			last = iter;
			iter = iter->next;
		}
	}
	return (1);
}