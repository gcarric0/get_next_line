/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:41:30 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/29 17:54:49 by gcarrico         ###   ########.fr       */
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

char *ft_find_line(char *buffer)
{
    int i;
    int j;
    char *line;
    
    i = 0;
    while(buffer[i] && buffer != '\n')
        i++;
    if(!buffer)
    {
        free(buffer);
        return(NULL);
    }
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
}
