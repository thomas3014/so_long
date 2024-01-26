/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:20 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/22 15:27:39 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_strcmpn(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			ss = (char *)(s + i);
		i++;
	}
	if (s[i] == (const char)c)
		ss = (char *)(s + i);
	return (ss);
}

int	ft_check_file(char *path)
{
	char	*ext;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strcmpn(".ber", ext) != 0)
	{
		printf("Le fichier n'est pas correct\n");
		return (0);
	}
	printf("le ficher est correct\n");
	return (1);
}
