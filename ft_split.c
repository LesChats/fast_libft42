/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:29:18 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/05 18:46:18 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MEMSIZ 1000

static char		**clean_all(char ***ans, size_t n)
{
	while (n--)
		free(*ans[n]);
	free(*ans);
	return (NULL);
}

static size_t	c_splts(t_addr_tab *arr, char const *s, char c)
{
	char			*a_c;
	size_t			nth_split;
	
	nth_split = 0;
	while (*s && (a_c = ft_strchr(s, c)))
	{
		if (nth_split < MEMSIZ)
			arr->tab[nth_split] = a_c;
		while (*a_c == c)
			a_c++;
		s = a_c;
		nth_split++;
	}
	if (*s)
	{
		if (nth_split < MEMSIZ)
			arr->tab[nth_split++] = (char *)(s + ft_strlen(s));
		else
			++nth_split;
	}
	arr->size = MIN(nth_split, MEMSIZ);
	return (nth_split);
}

static size_t	maman(char **ans_t, char **tab, char const *s, char c)
{
	size_t		i;
	size_t		len;
	
	i = 0;
	/////////pfffff/////
	while (tab[i] i < MEMSIZ)
	{
		len = (size_t)(tab[i] - s);
		ans_t[i] = (char *)malloc(len + 1);
		if (!ans_t[i])
			return (i + 1);
		ft_memcpy(ans_t[i], s, len);
		ans_t[i][len] = 0;
		s = tab[i++];
		while (*s == c)
			s++;
	}
	return (0);
}

static size_t	papa(char **ans_t, const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*a_c;

	i = MEMSIZ;
	while (*s == c)
		s++;
	while (*s && (a_c = ft_strchr(s, c)))
	{
		len = a_c - s;
		if (!(ans_t[i] = (char *)malloc(len + 1)))
			return (i + 1);
		ft_memcpy(ans_t[i], s, len);
		ans_t[i++][len] = 0;
		while (*a_c == c)
			a_c++;
		s = a_c;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	t_addr_tab	save_arr;
	size_t		n_splt;
	char		**ans;
	size_t		clean;

	if (!s)
		return (0);
	while (*s == c)
		++s;
	n_splt = c_splts(save_arr, s, c);
	if (!(ans = (char **)malloc(sizeof(char *) * (n_splt + 1))))
		return (0);
	ans[n_splt] = 0;
	if((clean = maman(ans, save_arr, s, c )))
		return (clean_all(&ans, clean - 1));
	if (n_splt > MEMSIZ)
		if ((clean = papa(ans, s + (t_op)save_arr.tab[MEMSIZ - 1], c)))
			return (clean_all(&ans, clean - 1));
	return (ans);
}
