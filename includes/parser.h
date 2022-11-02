/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:26:16 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 16:08:45 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct data
{
	char	*map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		rgb_f[3];
	int		rgb_c[3];
}	t_data;

void	parser(t_data *data, char *file);
void	parse_map(t_data *data, int fd);
void	ft_warn(char *str);
int		parse_color(int *data, char **arr, int index, int fd);
void	check_initalize(t_data *data);
int		check_file(char *file);
void	initalize(t_data *data);
char	**get_array_elems(int fd);
int		check_empty_str(char *str);
int		rows_map(char **map);
int		ft_check_map(char **map);
void	clean_map(char **map, int fd, char *str);
int		check_space_map(char **map, char *str, int fd);
int		catch_null_gnl_map(char ***map, int fd);
void	init_map_space(char **rect_map, int len);
char	*matr_to_arr(char **map);
int		empty_str_map(char **map);
int		try_open(char *file);
void	end_map(char **map, int fd);

#endif