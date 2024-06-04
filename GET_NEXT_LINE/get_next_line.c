/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:41:30 by gcarrico          #+#    #+#             */
/*   Updated: 2024/06/04 18:43:24 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char *ft_next_line(char *buffer)
{
    int i;
    int j;
    char *next_line;
    
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    if(!buffer)
    {
        free(buffer);
        return(NULL);
    }
    next_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
    i++;
    j = 0;
    while(buffer[i])
        next_line[j++] = buffer[i++];
    free(buffer);
    return(next_line);
}

char *ft_line(char *buffer)
{
    char *line;
    int i;

    i = 0;
    if(!buffer[i])
        return(NULL);
    while(buffer[i] && buffer[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while(buffer[i])
    {
        line[i] = buffer[i];
        i++;
    }
    if(buffer[i] && buffer[i] == '\n')
        line[i++] = '\n';
    return(line);
}

char *read_content(int fd, char *content)
{
    char *buffer;
    int bytes;

    if(!content)
        content = ft_calloc(1,1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    bytes = 1;
    while(bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if(bytes == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes] = 0;
        content = ft_free(content, buffer);
        if(ft_strchr('\n', buffer))
            break ;
    }  
    free(buffer);
    return(content); 
}
