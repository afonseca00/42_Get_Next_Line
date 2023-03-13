/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonseca <afonseca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:35:21 by afonseca          #+#    #+#             */
/*   Updated: 2023/03/07 15:21:43 by afonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
//recebe uma string como entrada e retorna o comprimento da string
//parando na primeira ocorrência de uma nova linha ('\n').

int	remove_newline(char *buff)
{
	int	i;
	int	j;
	int	found_newline;

	i = 0;
	j = 0;
	found_newline = 0;
	while (buff[i])
	{
		if (found_newline)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			found_newline = 1;
		buff[i++] = '\0';
	}
	return (found_newline);
}
//recebe uma string como entrada e remove a nova linha ('\n')
//se estiver presente na string.

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_concat;
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_concat = ft_strlen(s1) + ft_strlen(s2);
	concat = (char *)malloc(size_concat + 1 * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1 && s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		concat[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	concat[i] = 0;
	free(s1);
	return (concat);
}
//concatena duas strings e retorna uma nova string com a concatenação.
