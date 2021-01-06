/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:29:18 by abaudot           #+#    #+#             */
/*   Updated: 2021/01/06 11:40:58 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**clean_all(char ***ans, int n)
{
	while (n--)
		free(*ans[n]);
	free(*ans);
	return (NULL);
}

static int		c_splts(t_addr_tab *arr, char const *s, char c)
{
	char			*a_c;
	int				nth_split;

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
	arr->size = nth_split;
	if (nth_split > MEMSIZ)
		arr->size = MEMSIZ;
	return (nth_split);
}

static int		maman(char **ans_t, t_addr_tab *arr, char const *s, char c)
{
	const int	max = arr->size;
	int			i;
	int			len;

	i = -1;
	while (++i < max)
	{
		len = (int)(arr->tab[i] - s);
		ans_t[i] = (char *)malloc(len + 1);
		if (!ans_t[i])
			return (i + 1);
		ans_t[i][len] = 0;
		ft_memcpy(ans_t[i], s, len);
		s += len;
		while (*s == c)
			s++;
	}
	return (0);
}

static int		papa(char **ans_t, const char *s, char c)
{
	char	*a_c;
	int		len;
	int		i;

	i = MEMSIZ;
	while (*s && (a_c = ft_strchr(s, c)))
	{
		len = (int)(a_c - s);
		if (!(ans_t[i] = (char *)malloc(len + 1)))
			return (i + 1);
		ft_memcpy(ans_t[i], s, len);
		ans_t[i++][len] = 0;
		while (*a_c == c)
			++a_c;
		s = a_c;
	}
	if (*s)
	{
		len = ft_strlen(s);
		if (!(ans_t[i] = (char *)malloc(len + 1)))
			return (i + 1);
		ft_memcpy(ans_t[i], s, len);
		ans_t[i][len] = 0;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	t_addr_tab	save_arr;
	char		**ans;
	int			n_splt;
	int			clean;

	if (!s)
		return (0);
	while (*s == c)
		++s;
	n_splt = c_splts(&save_arr, s, c);
	if (!(ans = (char **)malloc(sizeof(char *) * (n_splt + 1))))
		return (0);
	ans[n_splt] = 0;
	if ((clean = maman(ans, &save_arr, s, c)))
		return (clean_all(&ans, clean - 1));
	if (n_splt > MEMSIZ)
	{
		s = save_arr.tab[MEMSIZ - 1];
		while (*s == c)
			s++;
		if ((clean = papa(ans, s, c)))
			return (clean_all(&ans, clean - 1));
	}
	return (ans);
}
