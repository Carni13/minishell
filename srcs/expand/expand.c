/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:53:22 by jremy             #+#    #+#             */
/*   Updated: 2022/03/14 17:03:52 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exe.h"


int	__treate_dollar(char c, t_state quote_status)
{
	if (c == '$' && (quote_status == UNQUOTE || quote_status == D_QUOTE))
		return (1);
	return (0);
}

int __expand_word(char **token_word, t_msh  *msh)
{
	t_state slash_status;
	t_state quote_status;
	char *tmp;
	int     i;
	char    *expanded_token_word;
	
	(void)msh;
	expanded_token_word = __strdup("");
	tmp = *token_word;
	quote_status = UNQUOTE;
	slash_status = 0;
	i = 0;
	while(tmp[i])
	{
		if (tmp[i] == '\\' && tmp[i + 1] && __need_to_escape(i, quote_status, tmp)
			&& !slash_status)
		{
			slash_status = BACKSLASH;
			i++;
			continue ;
		}
		if (quote_status != __return_state(tmp[i], quote_status, slash_status))
		{
			fprintf(stderr, "Sur un %c\n", tmp[i]);
			quote_status = __return_state(tmp[i], quote_status, slash_status);
			i++;
			continue ;
		}
		if((!slash_status && __treat_dollar(tmp[i], quote_status))
			if(!__parameter_expand(tmp + i, msh, &expanded_token_word, &i))
				return (0);	
		__add_char_to_token(tmp[i], &expanded_token_word);
		i++;
		slash_status = 0;
	}
	free(*token_word);
	*token_word = expanded_token_word;
	return (1);
}

int __parameter_expand_token(t_lexing *lexing, t_msh *msh)
{
	while(lexing)
	{
		if(lexing->type == WORD)
			if(!__expand_word(&lexing->token, msh))
				return (__putendl_fd("Malloc error", 2), 0);
		fprintf(stderr, "new_token : [%s]\n", lexing->token);
		lexing = lexing->next;
	}
	return (1);
}
