/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:38:01 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 16:11:48 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	word_count(char const *str, char c)
{
	int	i;
	int	counter;
	int	in_word;

	i = 0;
	counter = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

static char	*add_word(char const *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **arr, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**spliting(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			arr[j] = add_word(s, start, i);
			if (!(arr[j]))
				return (ft_free(arr, j));
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

int	ft_check_duplicate(t_list **stack_a, int nb, char **arr, int index)
{
	t_list	*check;

	check = *stack_a;
	while (check)
	{
		if (check->data == nb)
		{
			write(2, "Error\n", 6);
			while (arr[index])
			{
				free(arr[index]);
				arr[index] = NULL;
				index++;
			}
			return (0);
		}
		check = check->next;
	}
	return (1);
}

t_list	**ft_split(char const *s, char c, t_list **stack_a)
{
	char	**arr;
	int		i;
	int		nb;

	i = 0;
	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	spliting(arr, s, c);
	while (arr[i])
	{
		nb = ft_atoi(arr[i]);
		if (ft_check_duplicate(stack_a, nb, arr, i) == 0)
			return (free(arr), arr = NULL, NULL);
		ft_lstadd_front(stack_a, ft_lstnew(nb));
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (stack_a);
}
