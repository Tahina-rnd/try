/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:31:43 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/03 08:50:31 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strip_newline(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

int	get_texture_path(char **texture_dest, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i] || line[i] == '\n')
		return (ft_error("Empty texture path"));
	*texture_dest = ft_strdup(line + i);
	if (!*texture_dest)
		return (ft_error("Malloc failed in texture path"));
	strip_newline(*texture_dest);
	j = ft_strlen(*texture_dest);
	while (j > 0 && (*texture_dest)[j - 1] == ' ')
		(*texture_dest)[--j] = '\0';
	return (0);
}
