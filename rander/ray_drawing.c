#include "../cub.h"

// void get_horizontal(t_game *game, float horizontal)
// {
// 	game->map->Xh_horizontal = (horizontal - game->player_pixl_y) / tanf(game->map->angle) + game->player_pixl_x;
// 	game->map->Yh_horizontal = horizontal;

// }

// void get_vertical(t_game *game, float vertical)
// {
// 	game->map->Xh_vertical = vertical;
// 	game->map->Yh_vertical = (vertical - game->player_pixl_x) * tanf(game->map->angle) + game->player_pixl_y;
// }

// void check_ray(t_game *game)
// {
// 	int x;
// 	int y;
// 	float vertical = floorf(game->player_pixl_x / SIZE) * SIZE;
// 	float horizontal = floorf(game->player_pixl_y / SIZE) * SIZE;
// 	while (1)
// 	{
// 		get_vertical(game, vertical);
// 		get_horizontal(game, horizontal);
// 		x = (int)game->map->Xh_horizontal / SIZE;
// 		y = (int)game->map->Yh_horizontal / SIZE;
// 		printf("x = %f             y = %f\n",game->map->Xh_vertical,game->map->Yh_vertical);
// 		if (game->map->grid[y][x] == '1')
// 		{

// 			game->map->d_X = game->map->Xh_horizontal;
// 			game->map->d_Y = game->map->Yh_horizontal;
// 			break ;
// 		}
// 		printf("youddfr\n");
// 		vertical += SIZE;
// 		horizontal += SIZE;
// 	}
// }

// void coler_ray(t_game *game)
// {
// 	float new_x;
// 	float new_y;
// 	int i;
// 	i = 1;
// 	new_x = 0;
// 	new_y = 0;
// 	while (new_x != game->map->d_X && new_y != game->map->d_Y)
// 	{
// 		printf("**********i **********neaw_y = %d*************new_x = %d*map\n", new_y, new_x);
// 		new_x = game->player_pixl_x + (sinf(game->map->angle) * i);
// 		new_y = game->player_pixl_y + (cosf(game->map->angle) * i);
//         put_pixel(game, (int)new_x, (int)new_y, 0x00FFFF00);
// 		i++;
// 	}
// }


void setup_ray(t_game *game)
{
    int new_x;
	int new_y;
	float cpy_angle;
    int i;
    i = 1;
//    check_ray(game);
//    coler_ray(game);
	cpy_angle = game->map->angle - 0.39;
	while(cpy_angle <= game->map->angle + 0.39)
	{
		i = 1;
		new_x = game->player_pixl_x + (cosf(cpy_angle) * i);
		new_y = game->player_pixl_y + (sinf(cpy_angle) * i);
		while(game->map->grid[new_y / SIZE][new_x / SIZE] != '1')
		{
			new_x = game->player_pixl_x + (cosf(cpy_angle) * i);
			new_y = game->player_pixl_y + (sinf(cpy_angle) * i);
			put_pixel(game, new_x, new_y, 0x00FFFF00);
			i++;
		}
		cpy_angle += 0.001;
	}
}
