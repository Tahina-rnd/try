/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:39:29 by maminran          #+#    #+#             */
/*   Updated: 2025/06/14 10:08:46 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_str_chr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_str_join(char const *s1, char const *s2);
char	*ft_str_dup(const char *s);
int		ft_str_len(const char *s);

#endif