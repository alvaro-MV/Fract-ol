/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:29:29 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/06 14:58:15 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	len_cal(char const *s, char c)
{
	int	token;
	int	i;

	i = 0;
	token = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			token += 1;
		i++;
	}
	return (token);
}

static void	get_sep(unsigned int *start, unsigned int *next,
char const *s, char c)
{
	*next = 0;
	while (s[*start] && s[*start] == c)
	{
		*start = *start + 1;
	}
	while (s[*start] && s[*start] != c)
	{
		*next = *next + 1;
		*start = *start + 1;
	}
}

static char	**release(char **marr, int i)
{
	while (i--)
		free(marr[i]);
	free(marr);
	return (NULL);
}

void	intialize_indexes(int *i, unsigned int *start, unsigned int *next)
{
	*i = 0;
	*start = 0;
	*next = 0;
}

char	**ft_split(char const *s, char c)
{
	int					i;
	unsigned int		start;
	unsigned int		next;
	char				**marr;

	intialize_indexes(&i, &start, &next);
	if (s == NULL)
		return (NULL);
	marr = (char **) malloc((len_cal(s, c) + 1) * sizeof(char *));
	if (marr == NULL)
		return (NULL);
	while (i < len_cal(s, c))
	{
		get_sep(&start, &next, s, c);
		if (next > 0)
			marr[i] = ft_substr(s, start - next, next);
		else
			marr[i] = ft_substr(s, start - next, 1);
		if (marr[i] == NULL)
			return (release(marr, i));
		i++;
	}
	marr[i] = NULL;
	return (marr);
}

// int	main(void)
// {
// 	char	**marr = ft_split("", '^');
// 	int		i = 0;

// 	if (len_cal("", '^') > 0)
// 	{
// 		while (marr[i] != NULL)
// 		{
// 			printf("%s\n", marr[i]);
// 			i++;
// 		}
// 		while (i > 0)
// 		{
// 			free(marr[i - 1]);
// 			i--;
// 		}
// 	}
// 	else
// 		printf("marr 0: %s", marr[0]);
// 	return (0);
// }
