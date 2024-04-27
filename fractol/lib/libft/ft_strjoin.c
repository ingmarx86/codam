/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:11:45 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:00:38 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		ptr[i] = s2[x];
		i++;
		x++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("aaaa", "bbbbtyfity"));
// }
