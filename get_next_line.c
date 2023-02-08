/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/08 19:53:01 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		k;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	nx = ft_calloc(sizeof(char), len + 1);
	if (!nx)
		return (0);
	len = 0;
	i = len;
	while (s1[i])
		nx[len++] = s1[i++];
	while (s2[k])
		nx[len++] = s2[k++];
	nx[len] = 0;
	free(s1);
	return (nx);
}

char	*reader(char *buffer, int fd)
{
	char	*str;
	int		rfl;

	if (!buffer)
		ft_calloc(1, 1);
	rfl = 1;
	while (rfl)
	{
		rfl = read(fd, str, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, str);
	}
	if (!str)
	{
		free(str);
		free(buffer);
	}
	else
		free(str);
	return (buffer);
}

char	*ft_cl(char *str)
{
	char	*nx;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	nx = ft_calloc(sizeof(char), i + 2);
	if (!nx)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		nx[i] = str[i];
	if (str[i] && str[i] == '\n')
		nx[i++] = '\n';
	nx[i] = 0;
	return (nx);
}

char	*ft_nl(char *str)
{
	char	*nx;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	nx = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	if (!nx)
		return (0);
	nx = ft_strjoin(nx, str + i);
	free(str);
	return (nx);
}

void	ft_calloc(int n, int s)
{
	int	i;
	void	*p;

	if (!n || !s)
		return (ft_calloc(1, 1));
	i = 0;
	p = malloc(n * s);
	if (p)
		while (i < n * s)
			p[i++] = 0;
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (0);
	buffer = reader(buffer, fd);
	line = ft_cl(buffer);
	buffer = ft_nl(buffer);
	return (buffer);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);

	return (0);
}
