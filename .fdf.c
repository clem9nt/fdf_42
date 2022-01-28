#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	/* mlx_pixel_put(mlx_ptr, win_ptr, ..récupérer les params); */
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	/* server */
	mlx_ptr = mlx_init();
	/* window */
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");

	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);

	mlx_key_hook(win_ptr, deal_key, (void *)0);

	/* events loop */
	mlx_loop(mlx_ptr);
}
