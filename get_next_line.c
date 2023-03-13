/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonseca <afonseca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:35:33 by afonseca          #+#    #+#             */
/*   Updated: 2023/03/07 17:09:41 by afonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}	
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (remove_newline(buffer))
			break ;
	}
	return (line);
}

/*int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDWR);
    printf("%d\n", fd);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    
    close(fd);
    return (0);
}*/

/*int main()
{
	int fd;
	char *line;
	
	fd = open("test.txt", O_RDWR);
	printf("%d\n", fd);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}*/
