#include "../cub.h"

void Calculate_width_height(t_game *game)
{
	int width;
	int height;

	height = 0;
	width = 0;
	game->player_pixl_x = game->player_x * SIZE - (SIZE / 2);
	game->player_pixl_y = game->player_y * SIZE - (SIZE / 2);
	while (game->map->grid[height])
	{
		while (game->map->grid[height][width])
			width++;
		height++;
	}
	game->map->width = width * SIZE;
	game->map->height = height * SIZE;
}

void    put_pixel(t_game *game, int x, int y, int color)
{
    char    *dst;

    dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_ft(t_game *game)
{
	game->addr = mlx_get_data_addr(game->player, &game->bits_per_pixel, &game->line_length, &game->endian);
	int y = 0;
    while (y < 32)
    {
        int x = 0;
        while (x < y)
        {
            put_pixel(game, 32 / 2 - y / 2 + x, y, 0x00FF0000);
            x++;
        }
        y++;
    }
}


int create_xpm_file_image(t_game *game)
{
	int x;
	int y;

	game->player = mlx_new_image(game->mlx_ptr, 32, 32);
	if (!game->player)
		return (1);
	ft_ft(game);
	game->empty = mlx_xpm_file_to_image
		(game->mlx_ptr, "texter/empty.xpm", &x, &y);
	if (!game->empty)
		return (1);
	game->wall = mlx_xpm_file_to_image
		(game->mlx_ptr, "texter/wall.xpm", &x, &y);
	if (!game->wall)
		return (1);
	return (0);
}

void ft_image(t_game *game, int width, int height)
{
	if (game->map->grid[height][width] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width * SIZE, height * SIZE);
	if (game->map->grid[height][width] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->empty, width * SIZE, height * SIZE);
	if (game->map->grid[height][width] == 'N')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player, width * SIZE, height * SIZE);
}


void create_put_image_to_window(t_game *game)
{
	int width;
	int height;

	height = 0;
	width = 0;
	while (game->map->grid[height])
	{
        width = 0;
		while (game->map->grid[height][width])
		{
            ft_image(game, width, height);
			width++;
		}
		height++;
	}
}

void Move_game(t_game *game, int y, int x)
{
	if (game->map->grid[y][x] == '0')
	{
		game->map->grid[game->player_y][game->player_x] = '0';
		game->player_y = y;
		game->player_x = x;
		game->map->grid[game->player_y][game->player_x] = 'N';
	}
}


int	moving(int key, t_game *game)
{

	if (key == 53 || key == 1 || key == 13 || key == 2 || key == 0)
	{
		printf("===%d\n", game->player_y);
		if (key == 53)
		{
			// ft_free_strct(game);
			exit(0);
		}
		else if (key == 1)//s
			Move_game(game, game->player_y + 1, game->player_x);
		else if (key == 13)//w
			Move_game(game, game->player_y - 1, game->player_x);
		else if (key == 0)//a
			Move_game(game, game->player_y, game->player_x - 1);
		else if (key == 2)//d
		{
			
		}
			// Move_game(game, game->player_y, game->player_x + 1);
	}
	create_put_image_to_window(game);
	return (0);
}
