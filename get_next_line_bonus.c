/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:33:41 by pgaric            #+#    #+#             */
/*   Updated: 2022/06/03 12:31:26 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stored[1024];
	char		*nline;
	char		buffer[BUFFER_SIZE + 1];
	int			read_value;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	nline = NULL;
	if (stored[fd] != NULL)
	{
		nline = ft_strdup(stored[fd]);
		free(stored[fd]);
		stored[fd] = NULL;
		if (encounter_newline_sign(nline) != -1)
			return (return_lineread_and_stored(nline, stored, fd));
	}
	read_value = read(fd, buffer, BUFFER_SIZE);
	while (read_value > 0)
	{	
		nline = storing_line_content(nline, buffer, read_value);
		if (encounter_newline_sign(nline) != -1)
			return (return_lineread_and_stored(nline, stored, fd));
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	return (nline);
}
