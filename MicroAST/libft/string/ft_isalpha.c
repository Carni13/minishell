/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   __isalpha.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: jremy <jremy@student.42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2021/11/23 15:55:09 by jremy #+##+# */
/*   Updated: 2022/01/10 15:04:51 by jremy###   ########.fr   */
/**/
/* ************************************************************************** */

#include "libft.h"

int	__isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}