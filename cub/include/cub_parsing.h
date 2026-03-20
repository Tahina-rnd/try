/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:26:10 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/14 11:08:31 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
# define CUB_PARSING_H

int		all_identifiers_found(t_map_data *data);
int		check_player(char **map);
char	**duplicate_map(char **original, int height);
int		find_player(t_map_data *data);
int		flood_fill(char **map, int start_x, int start_y, int width, int height);
void	free_map_copy(char **map_copy, int height);
void	free_map_data(t_map_data *data);
int		ft_error(char *msg);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_player(char c);
int		get_color(t_rgb *color, char *line);
int		get_texture_path(char **texture_dest, char *line);
int		map_format_checker(char *map);
void	normalize_map(t_map_data *data);
int		parse_file(char *filename, t_map_data *data);
int		parse_identifier(char *line, t_map_data *data);
void	strip_newline(char *s);
int		validate_map(t_map_data *data);
void	init_data(t_map_data *data);
int		init_map(t_map_data *data, char *line);
int		add_map_line(t_map_data *data, char *line);
int		handle_identifier(char *line, t_map_data *data, int *in_map);
int		handle_map_line(char *line, t_map_data *data);
int		is_valid_number(char *s);

#endif