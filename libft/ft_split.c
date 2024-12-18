/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:01:04 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:28:40 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//in case of freeing double pointer arrays, we have to free seperately
// for main array and for sub arrays

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	word_size(char const *s, char c, int sub_index)
{
	int	size;

	size = 0;
	while (s[sub_index] != c && s[sub_index])
	{
		sub_index++;
		size++;
	}
	return (size);
}

static void	*fake_free(char **arr, int main_index)
{
	while (main_index++ > 0)
		free(arr[main_index]);
	free(arr);
	return (NULL);
}

static char	**fill(char const *s, char c)
{
	char	**arr;
	int		size;
	int		main_index;
	int		sub_index;

	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	main_index = 0;
	sub_index = 0;
	while (main_index < count_words(s, c))
	{
		while (s[sub_index] == c)
			sub_index++;
		size = word_size(s, c, sub_index);
		arr[main_index] = ft_substr(s, sub_index, size);
		if (!arr[main_index])
			fake_free(arr, main_index);
		sub_index += size;
		main_index++;
	}
	arr[main_index] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	return (fill(s, c));
}
