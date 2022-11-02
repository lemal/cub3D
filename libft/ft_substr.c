/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by tapulask          #+#    #+#             */
/*   Updated: 2022/11/01 16:44:18 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_local_check_exist(char const *s, size_t start,
size_t len)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start > i)
		return (-1);
	else if ((start + len) <= (size_t)i)
		return ((int)len);
	return (i - (int)start);
}

static	char	*ft_local_fill(char const *s, char *ptr_to_first,
				size_t j, size_t len)
{
	size_t	i;

	i = 0;
	while (s[j] && (i < len))
	{
		ptr_to_first[i] = s[j];
		j++;
		i++;
	}
	ptr_to_first[i] = '\0';
	return (ptr_to_first);
}

char	*ft_substr(char const *s, unsigned int start,
			size_t len)
{
	int		i;
	char	*ptr_to_first;

	if (s == NULL)
		return (NULL);
	i = ft_local_check_exist(s, start, len);
	if (i == -1)
	{
		ptr_to_first = (char *)malloc(sizeof(char));
		if (ptr_to_first == NULL)
			return (NULL);
		*ptr_to_first = '\0';
		return (ptr_to_first);
	}
	ptr_to_first = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr_to_first == NULL)
		return (NULL);
	ptr_to_first = ft_local_fill(s, ptr_to_first, start, len);
	return (ptr_to_first);
}
