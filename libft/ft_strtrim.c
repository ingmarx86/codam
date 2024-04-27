/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:11:45 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:28:30 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check(const char *c, const char *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (*c == set[k])
			return (1);
		else
		k++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	t;

	i = 0;
	t = ft_strlen(s1);
	if (t == 0 || s1 == NULL || set == NULL)
		return (ft_strdup(""));
	while (check(&s1[i], set) == 1 && i < t)
		i++;
	while (check(&s1[t - 1], set) == 1 && i < t)
		t--;
	s1 = &s1[i];
	ptr = malloc(sizeof(char) * (t - i) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, ((t) - i));
	ptr[t - i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("ghfxh", "asaag"));
// }
