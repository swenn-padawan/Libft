/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:11:29 by stetrel           #+#    #+#             */
/*   Updated: 2025/07/13 17:50:23 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define HEX "123456789abcdef"

static	bool ft_ishex(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

static	long ft_strtohex(char *ptr, char **end)
{
	long	result;

	result = 0;
	if (ptr[0] != '0' || !ptr[1] || (ptr[1] | 32) != 'x')
		return (0);
	ptr += 2;
	while (*ptr && ft_ishex(*ptr))
	{
		if (*ptr >= '0' && *ptr <= '9')
			result = (result << 4) + (*ptr - '0');
		else if (*ptr >= 'a' && *ptr <= 'f')
			result = (result << 4) + (*ptr - 'a' + 10);
		else if (*ptr >= 'A' && *ptr <= 'F')
			result = (result << 4) + (*ptr - 'A' + 10);
		ptr++;
	}
	if (end)
		*end = ptr;
	return (result);	
}

long	ft_strtol(char *ptr, char **end, int base){
	long	result;

	result = 0;
	if (base == 16)
		return (ft_strtohex(ptr, end));
	while (*ptr && ft_isdigit(*ptr)){
		result = result * 10 + *ptr - '0';
		ptr++;
	}
	if (end)
		*end = ptr;
	return (result);
}
