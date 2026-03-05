/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:24:10 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/03 08:58:02 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_directions(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}

static int	check_position(char **map, t_point curr, int width, int height)
{
	if (curr.x < 0 || curr.y < 0 || curr.x >= width || curr.y >= height)
		return (-1);
	if (map[curr.y][curr.x] == '1' || map[curr.y][curr.x] == 'V')
		return (1);
	if (map[curr.y][curr.x] == ' ')
		return (-1);
	return (0);
}

static void	push_neighbors(t_point *stack, int *top, int stack_size,
		t_point curr, int *dx, int *dy)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (*top < stack_size)
		{
			stack[*top].x = curr.x + dx[i];
			stack[*top].y = curr.y + dy[i];
			(*top)++;
		}
		i++;
	}
}

static int	process_point(char **map, t_point *stack, int *top,
		int stack_size, int *dx, int *dy, int width, int height)
{
	t_point	curr;
	int		check;

	curr = stack[*top];
	(*top)--;
	check = check_position(map, curr, width, height);
	if (check == -1)
		return (-1);
	if (check == 1)
		return (0);
	map[curr.y][curr.x] = 'V';
	push_neighbors(stack, top, stack_size, curr, dx, dy);
	return (0);
}

int	flood_fill(char **map, int start_x, int start_y, int width, int height)
{
	t_point	*stack;
	int		top;
	int		stack_size;
	int		dx[4];
	int		dy[4];

	init_directions(dx, dy);
	stack_size = width * height + 1;
	stack = malloc(sizeof(t_point) * stack_size);
	if (!stack)
		return (0);
	top = 0;
	stack[top].x = start_x;
	stack[top].y = start_y;
	top++;
	while (top > 0)
	{
		if (process_point(map, stack, &top, stack_size,
				dx, dy, width, height) == -1)
			return (free(stack), 0);
	}
	free(stack);
	return (1);
}
