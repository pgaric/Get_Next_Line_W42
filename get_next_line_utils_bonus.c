/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:33:38 by pgaric            #+#    #+#             */
/*   Updated: 2022/06/03 17:47:53 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *string)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(string) + 1);
	if (dest == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*storing_line_content(char *nline, char *buffer, int read_value)
{
	char	*stored_line;
	int		i;
	int		k;
	int		lenght_stored_line;

	buffer[read_value] = '\0';
	if (nline == NULL)
		return (ft_strdup(buffer));
	lenght_stored_line = ft_strlen(buffer) + ft_strlen(nline);
	stored_line = malloc((lenght_stored_line + 1) * sizeof(char));
	i = 0;
	while (nline[i] != '\0')
	{
		stored_line[i] = nline[i];
		i++;
	}
	k = 0;
	while (buffer[k] != '\0')
	{
		stored_line[i + k] = buffer[k];
		k++;
	}
	stored_line[i + k] = '\0';
	free(nline);
	return (stored_line);
}

int	encounter_newline_sign(char *nline)
{
	int	i;

	i = 0;
	while (nline[i] != '\0')
	{
		if (nline[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*return_lineread_and_stored(char *nline, char **stored, int fd)
{
	int	len_nline;
	int	len_newline;

	len_newline = encounter_newline_sign(nline);
	len_nline = ft_strlen(nline);
	if (len_newline == len_nline - 1)
	{
		free(stored[fd]);
		stored[fd] = NULL;
		return (nline);
	}
	stored[fd] = ft_strdup(nline + len_newline + 1);
	nline[len_newline + 1] = '\0';
	return (nline);
}
