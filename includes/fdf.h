#ifndef FDF_H
# define FDF_H

/*
 ** =========[ Defines ]===========
 */

/*
 ** Window
 */

# define WIDTH			800
# define HEIGHT			500
# define FRAMERATE		100

/*
 ** Colors
 */

# define W 				0xFFFFFF
# define R 				0xFF0000
# define G 				0x00FF00
# define B 				0x0000FF
# define C 				0x00FFFF
# define M 				0xFF00FF
# define Y 				0xFFFF00
# define K 				0x000000

/*
 ** Angles in radian
 */

# define ANG_1			0.017453
# define ANG_30			0.523599
# define ANG_45			0.785398

/*
 ** Map limits
 */

# define BOT_LIMIT  	-2147483648
# define TOP_LIMIT  	2147483647

/*
 ** Errors
 */

# define WRONG_ARG		"Wrong argument. Usage: \"fdf file.fdf\""
# define FILENAME_ERR	"Only fdf filetype is allowed. (ie. \"map.fdf\")"
# define MALLOC_ERR		"Failed to allocate memory."
# define MLX_ERR		"Failed to initialize minilibx."
# define NO_FILE		"File not found."
# define READ_ERR		"Failed to read the file."
# define CLOSE_ERR		"Failed to close the file."

/*
 ** =========[ Includes ]==========
 */

/*
 ** Mandatory
 */

# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
 ** =========[ Structures ]========
 */

typedef struct s_bresenham
{
	int			xdelta;
	int			ydelta;
	int			xsign;
	int			ysign;
	int			err;
	int			errcpy;
}				t_bresenham;

typedef struct s_pixel
{
	int			x;
	int			y;
	long		z;
	int			color;
}				t_pixel;

/*
 ** map / mlx / img / default view / view / motion / hooks
 ** TODO put each category into a sub-structure
 */

typedef struct s_data
{
	int			fd[3];

	char		*file;
	int			**values;
	int			width;
	int			height;

	void		*mlx_ptr;
	void		*win_ptr;

	void		*mlx_img;
	char		*address;
	int			bpp;
	int			linelen;
	int			endian;

	int			default_scale;
	int			default_level;
	int			default_x_offset;
	int			default_y_offset;
	double		default_alpha;
	double		default_beta;
	double		default_gamma;
	int			scale;
	int			level;
	int			x_offset;
	int			y_offset;
	double		alpha;
	double		beta;
	double		gamma;

	int			clock;
	int			clocksign;
	int			coswave;
	int			wave_level;
	int			wave_speed;

	int			mode;
	int			view;
	int			step;
	int			hud;
	int			offset_sign;
	int			rotate_motion;
	int			rotate_speed;
	int			level_motion;
}				t_data;

/*
 ** =========[ Prototypes ]========
 **
 ** Commented function means static function.
 */

/*
 ** [ SECURITY.C ]
 */

void	ft_exit(char *error);
void	ft_free(void *ptr);
void	ft_backfree(int **tab, int i);
void	ft_close_fd(t_data *data);
void	ft_check_input(char *file);

/*
 ** [ MOTION.C ]
 */

/* 		int		ft_coswave(int clock, int speed, int level); */
void	ft_motion(t_data *data, int *target);

/*
 ** [ COLOR.C ]
 */

void	ft_color(t_data *data, t_pixel *p);

/*
 ** [ PROJECTION.C ]
 */

/* 		void	ft_rotate_alpha(int *y, long *z, double alpha); */
/* 		void	ft_rotate_beta(int *x, long *z, double beta); */
/* 		void	ft_rotate_gamma(int *x, int *y, double gamma); */
/* 		void	ft_isometric(int *x, int *y, long z); */
void	ft_translate(t_data *data, t_pixel *p);

/*
 ** [ RENDER.C ]
 */

/* 		void	ft_put_pixel(t_data *data, int x, int y, int color); */
/* 		void	ft_init_bresenham(t_bresenham *b, t_pixel *beg, t_pixel *end);*/
/* 		void	ft_set_line(t_data *data, t_pixel *beg, t_pixel *end); */
/* 		t_pixel	ft_set_pixel(t_data *data, int x, int y); */
void	ft_render(t_data *data);

/*
 ** [ HOOK_EVENTS_MODES.C ]
 */

void	ft_offset(int key, t_data *data);
void	ft_scale(int key, t_data *data);
void	ft_rotate(int key, t_data *data);
void	ft_level(int key, t_data *data);
void	ft_step(int key, t_data *data);

/*
 ** [ HOOK_EVENTS_GLOBAL.C ]
 */

void	ft_quit(t_data *data);
void	ft_reset_all(t_data *data);
void	ft_cycle_views(t_data *data);
void	ft_hud_help(t_data *data);
void	ft_hud_info(t_data *data);

/*
 ** [ HOOK.C ]
 */

int		ft_display(t_data *data);
int		ft_keyboard(int key, t_data *data);

/*
 ** [ READ.C ]
 */

void	ft_open(t_data *data);
void	ft_width(t_data *data);
void	ft_height(t_data *data);
/* 		void	ft_fill(t_data *data int i, char *line); */
void	ft_values(t_data *data);

/*
 ** [ INIT.C ]
 */

void	ft_init_map(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_init_view(t_data *data);
void	ft_init_motion(t_data *data);
void	ft_init_hooks(t_data *data);

/*
 ** [ MAIN.C ]
 */

/* 		void	ft_start_loop(t_data *data); */
int		main(int argc, char **argv);

#endif
