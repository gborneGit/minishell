/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:50:47 by gborne            #+#    #+#             */
/*   Updated: 2022/04/15 18:49:10 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	s_len(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

size_t	s_lcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = -1;
	if (dstsize - i - 1)
	{
		while (src[++i] && (dstsize - i - 1))
			dst[i] = src[i];
		dst[i] = 0;
	}
	return (s_len(src));
}

char	*s_chr(const char *s, int c, int next)
{
	unsigned int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
		{
			if (next)
				return ((char *)&s[++i]);
			else
				return ((char *)&s[i]);
		}
	}
	return (NULL);
}

char	*s_ljoin(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	unsigned long	i;
	unsigned long	j;
	char			*dst;

	i = -1;
	j = -1;
	dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	if (s1_len)
		while (s1[++i])
			dst[i] = s1[i];
	if (s2_len)
		while (s2[++j])
			dst[s1_len + j] = s2[j];
	dst[s1_len + s2_len] = '\0';
	free(s1);
	return (dst);
}
