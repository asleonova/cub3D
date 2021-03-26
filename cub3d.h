/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:53:00 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/29 22:39:54 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define SPACES	" \t\n\v\f\r"
# define KW		13
# define KA		0
# define KS		1
# define KD		2
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define SCALE	64

typedef struct		s_map
{
	int				x;
	int				y;
	int				start_map;
	int				end_map;
	int				max_str;
	int				height_map;
	char			**map;
	float			dir;
	char			error;
	int				s_width;
	int				s_height;
	int				el;
	int				f_int;
	int				c_int;
	int				max_columns;
	int				max_rows;
	int				red_f;
	int				green_f;
	int				blue_f;
	int				red_c;
	int				green_c;
	int				blue_c;
	int				valid;
	int				tok;
	int				k;
}					t_map;

typedef struct		s_player
{
	float			x;
	float			y;
	float			dir;
	float			angle;
	float			fov_start;
	float			dist;
	float			*wall_size;
	float			*ceiling;
}					t_player;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			dir;
	float			delta;
	float			dist;
	float			size;
	int				img_height;
	float			h_of;
	float			v_of;
	float			height;
	float			width;
}					t_sprite;

typedef enum		e_hit_side
{
	north = 0,
	east = 1,
	south = 2,
	west = 3
}					t_hit_side;

typedef struct		s_cross
{
	float			hx;
	float			hy;
	float			vx;
	float			vy;
	float			h_dy;
	float			h_dx;
	float			v_dy;
	float			v_dx;
	float			h_distance;
	float			v_distance;
	float			closest_cross;
	float			right_dist;
	float			wall_x;
	float			wall_y;
	float			*offset;
	int				hit;
	t_hit_side		hit_side;
}					t_cross;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
	int				*addr_int;
}					t_data;

typedef struct		s_texture_data
{
	void			*img;
	char			*relative_path;
	int				img_width;
	int				img_height;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	char			*addr;
}					t_texture_data;

typedef struct		s_sprite_img
{
	void			*img;
	char			*relative_path;
	char			*spr;
	int				img_width;
	int				img_height;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	char			*addr;
}					t_sprite_img;

typedef struct		s_all
{
	int				check;
	t_data			data;
	t_player		pl;
	t_map			map;
	t_cross			cross;
	t_texture_data	texture[4];
	t_sprite_img	sprite_img;
	t_sprite		*sp;
	int				*sprite_order;
	int				max_s_width;
	int				max_s_height;
	double			*sprite_dist;
	int				sprite_count;
}					t_all;

void				feedback_invalid(char *str, t_all *all);
void				fc_valid(char *str, t_map *map, int i);
void				sprite_valid(char *str, t_all *all);
int					check_format(char *str, t_map *map, t_all *all);
int					rosol_converting(const char *str, t_map *map);
void				floor_check(char *str, t_map *map);
int					len_mod(char *str);
void				chipher_rfc_valid(char *str, t_map *map);
void				chipher_sides_valid(char *str, t_all *all);
void				texture_reader2(char *str, char *texture, int i, int j);
char				*texture_reader(char *str, t_all *all);
void				check_path(char *str, t_all *all);
int					floor_conv(t_map *map, char	**colours, int res);
int					ceiling_conv(t_map *map, char **colours, int res);
void				launch_pm2(char *fichier, t_map *map, t_all *all,
		char *line);
int					get_next_line(int fd, char **line);
void				ft_putstr(char *str);
void				feedback(char *str, char *feedback);
int					linelen(char **str);
int					check_colours_range_f(t_map *map);
int					check_colours_range_c(t_map *map);
char				**take_f_c_line(char *prep_line);
char				**get_colours_codes(char *colours_line);
int					convert_colours(int r, int g, int b);
int					f_converting(char *str, t_map *map);
int					c_converting(char *str, t_map *map);
int					ft_isnumber(char *str);
void				cnt_map(char *str, t_map *map);
void				ft_free(char **tab);

void				texture_valid(char *str, t_all *all);
void				floor_ceiling_work(char *str, t_map *map,
		char **colours, int res);
void				main_init(t_all *all);
int					parser_map(char *fichier, t_map *map, t_all *all);
int					check_cell(t_map *map, char c, int i, size_t j);
int					check_edge_end(t_map *map, int i, int up);
int					check_edge_origin(t_map *map, int i);
int					validator_map_wtf30(t_map *map, int i, size_t j);
int					validator_map_wtf25(t_map *map, int i, size_t j);
int					validator_map(t_map *map);
void				ft_pass_space(char *line, int *i);
int					ft_parser_map(t_map *map, char *line, int num_str);
int					ft_parser(t_map *map, char *line, int num_str);
int					parser_map2(char *fichier, t_map *map, char *line, int i);
void				initialization_of_structures(t_map *map);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				fix_angle(float *angle);
void				calculate_wall(t_all *all, int i);
void				horizontal_cross(t_all *all);
void				vertical_cross(t_all *all);
void				find_wall(t_all *all);
void				shortest_distance(t_all *all, int i);
void				horizontal_hit(t_all *all);
void				vertical_hit(t_all *all);
void				shortest_distance(t_all *all, int i);
void				draw_wall(t_all *all, int width);
void				draw_ceiling(t_all *all, int width);
void				draw_floor(t_all *all, int width);
void				get_player_position(t_all *all);
void				get_player_direction(t_all *all);
void				get_sprite_positions(t_all *all);
void				init_textures(t_all *all);
void				draw_all_sprites(t_all *all, int i);
t_sprite			*init_sprites(t_all *all);
t_sprite			**sort_sprites(t_all *all);
void				get_sprite_image_data(t_all *all);
float				compute_delta_angle(float fov_start, float sprite_dir);
void				cast_rays(t_all *all);
void				init_all(t_all *all);
int					render_next_frame(t_all *all);
int					control_player(int keycode, t_all *all);
float				*init_slice_height(t_all *all);
float				*init_ceiling(t_all *all);
float				*init_offset(t_all *all);
void				init_screen_params(t_all *all);
void				make_screenshot(t_all *all);
int					ft_check_extension(char *file_name, char *valid_ext);
int					ft_strcmp(char const *s1, char const *s2);
void				check_tex_extent(char *str, t_all *all);
void				double_resol(char *str, t_map *map, int k);

#endif
