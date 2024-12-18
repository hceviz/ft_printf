/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:09:14 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 12:58:57 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*it starts to check the array if set contains the character
and removes matched characterts till it encounters unmatched one
and it goes to end of the array and set and start to check from
end to beginning and again removes matched characters till encounter
unmatched character
i did not return null for allocation failure because i used strdup for 
res array and it returns null in case of failure*/
#include "libft.h"

static int	is_contain(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (is_contain(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (is_contain(s1[end - 1], set))
		end--;
	res = ft_substr(s1, start, end - start);
	return (res);
}
