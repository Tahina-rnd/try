/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:31:59 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/03 08:54:32 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	extract_token(char *token, char *line, int *i)
{
	int	start;
	int	tlen;

	start = *i;
	while (line[*i] && line[*i] != ',' && line[*i] != '\n'
		&& line[*i] != ' ' && line[*i] != '\t')
		(*i)++;
	tlen = *i - start;
	if (tlen <= 0 || tlen >= 16)
		return (0);
	ft_memcpy(token, line + start, tlen);
	token[tlen] = '\0';
	return (1);
}

static int	check_rgb_values(t_rgb *color, int *numbers, char *line, int nb_count)
{
	int	i;

	i = 0;
	if (nb_count != 3)
		return (ft_error("RGB must have exactly 3 numbers"));
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (ft_error("Extra characters after RGB values"));
		i++;
	}
	if (numbers[0] < 0 || numbers[0] > 255
		|| numbers[1] < 0 || numbers[1] > 255
		|| numbers[2] < 0 || numbers[2] > 255)
		return (ft_error("RGB values must be between 0 and 255"));
	color->r = numbers[0];
	color->g = numbers[1];
	color->b = numbers[2];
	return (0);
}

int	get_color(t_rgb *color, char *line)
{
	int		i;
	int		numbers[3];
	int		nb_count;
	char	token[16];

	i = 0;
	nb_count = 0;
	while (line[i] && nb_count < 3)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!line[i] || line[i] == '\n')
			break ;
		if (!extract_token(token, line, &i))
			return (ft_error("Invalid RGB token"));
		if (!is_valid_number(token))
			return (ft_error("RGB value is not a valid number"));
		numbers[nb_count] = ft_atoi(token);
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		nb_count++;
		if (line[i] == ',')
			i++;
	}
	return (check_rgb_values(color, numbers, line, nb_count));
}
