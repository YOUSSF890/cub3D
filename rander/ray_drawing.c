#include "../cub.h"

// void get_horizontal(t_game *game, int horizontal)
// {
// 	// printf("horizontal = %f\n", horizontal / 32 );
// 	// printf("game->player_pixl_y = %d\n", game->player_pixl_y / 32);
// 	// printf("tanf(game->map->angle) = %f\n", tan(game->map->angle) / 32);
// 	// printf("game->player_pixl_x = %d\n", game->player_pixl_x / 32);
// 	game->map->Xh_horizontal = (horizontal - game->player_pixl_y) / tanf(game->map->angle) + game->player_pixl_x;
// 	// printf("8888888888888***********************=%f\n", (horizontal - game->player_pixl_y) / tanf(game->map->angle) + game->player_pixl_x);
// 	game->map->Yh_horizontal = horizontal;

// }

// void get_vertical(t_game *game, int vertical)
// {
// 	// printf("********************************vertical = %f\n", vertical / 32);
// 	// printf("********************************game->player_pixl_y = %d\n", game->player_pixl_y/32);
// 	// printf("********************************tanf(game->map->angle) = %f\n", tan(game->map->angle)/32);
// 	// printf("********************************game->player_pixl_x = %d\n", game->player_pixl_x / 32);
// 	game->map->Xh_vertical = vertical;
// 	game->map->Yh_vertical = (vertical - game->player_pixl_x) * tanf(game->map->angle) + game->player_pixl_y;
// 	printf("game->map->Yh_vertical = %d\n",game->map->Yh_vertical / 32);
// }

// void check_ray(t_game *game)
// {
// 	int vertical = (int)floorf((float)game->player_pixl_x / SIZE) * SIZE;
// 	int horizontal = (int)floorf((float)game->player_pixl_y / SIZE) * SIZE;
// 	while (1)
// 	{
// 		get_vertical(game, vertical);
// 		get_horizontal(game, horizontal);
// 		printf("game->map->Xh_horizontal = %d\n",game->map->Xh_horizontal/32);
// 		printf("game->map->Yh_horizontal = %d\n",game->map->Yh_horizontal/32);
// 		printf("game->map->Xh_vertical = %d\n",game->map->Xh_vertical / 32);
// 		// printf("game->map->Yh_vertical = %d\n",game->map->Yh_vertical / 32);
// 		if (game->map->grid[game->map->Yh_vertical][game->map->Xh_vertical] == '1')
// 		{

// 			game->map->d_X = game->map->Xh_vertical;
// 			game->map->d_Y = game->map->Yh_vertical;
// 			printf(".....................................X....%d\n",game->map->d_X);
// 			printf("....................................Y.....%d\n",game->map->d_Y);
// 			break ;
// 		}
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
// 	while (new_x != game->map->d_X || new_y != game->map->d_Y)
// 	{
// 		// printf("game->map->d_X = %f\n",game->map->d_X);
// 		// printf("game->map->d_Y = %f\n",game->map->d_Y);
// 		// printf("new_x = %f\n",new_x);
// 		// printf("new_Y = %f\n",new_y);
// 		new_x = game->player_pixl_x + (sinf(game->map->angle) * i);
// 		new_y = game->player_pixl_y + (cosf(game->map->angle) * i);
// 		// printf("====new_x = %f    new_y = %f\n",new_x ,new_y);
// 		// printf("====game->map->d_X = %f    game->map->d_Y = %f\n",game->map->d_X ,game->map->d_Y);
//         put_pixel(game, new_x, new_y, 0x00FFFF00);
// 		i++;
// 	}
// }

// void setup_ray(t_game *game)
// {
// 	if (game->map->palyer == 'N')
// 	{
// 		check_ray(game);
// 		coler_ray(game);
// 	}
// 	else if (game->map->palyer == 'S')
// 	{
// 		check_ray(game);
// 	}
// 	else if (game->map->palyer == 'W')
// 	{
// 		check_ray(game);
// 	}
// 	else if (game->map->palyer == 'E')
// 	{
// 		check_ray(game);
// 	}
// }


void setup_ray(t_game *game)
{
    int new_x;
	int new_y;
    int i;
    i = 1;
    if (game->map->palyer == 'S')
	{
		while (1)
		{
			new_x = game->player_pixl_x + (sinf(game->map->angle) * -i);
			new_y = game->player_pixl_y + (cosf(game->map->angle) * i);
			put_pixel(game, new_x, new_y, 0x00FFFF00);
    		if (game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1'
			    && game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1')
				break ;
			i++;
		}
	}
	else if (game->map->palyer == 'N')
	{
		while (1)
		{
			new_x = game->player_pixl_x + (sinf(game->map->angle) * i);
			new_y = game->player_pixl_y + (cosf(game->map->angle) * -i);
			put_pixel(game, new_x, new_y, 0x00FFFF00);
    		if (game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1'
			    && game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1')
				break ;
			i++;
		}
	}
	else if (game->map->palyer == 'W')
	{
		while (1)
		{
			new_x = game->player_pixl_x + (cosf(game->map->angle) * -i);
			new_y = game->player_pixl_y + (sinf(game->map->angle) * -i);
			put_pixel(game, new_x, new_y, 0x00FFFF00);
    		if (game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1'
			    && game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1')
				break ;
			i++;
		}
	}
	else if (game->map->palyer == 'E')
	{
		while(1)
		{
			new_x = game->player_pixl_x + (cosf(game->map->angle) * i);
			new_y = game->player_pixl_y + (sinf(game->map->angle) * i);
			put_pixel(game, new_x, new_y, 0x00FFFF00);
    		if (game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1'
			    && game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1')
				break ;
			i++;
		}
	}
}


// void setup_ray(t_game *game)
// {
//     int new_x;
// 	int new_y;
//     int i;
//     i = 1;
//     while (1)
//     {
//         if (game->map->palyer == 'S')
// 	    {
// 	    	new_x = game->player_pixl_x + (sinf(game->map->angle) * -i);
// 	    	new_y = game->player_pixl_y + (cosf(game->map->angle) * i);
// 	    }
// 	    else if (game->map->palyer == 'N')
// 	    {
// 	    	new_x = game->player_pixl_x + (sinf(game->map->angle) * i);
// 	    	new_y = game->player_pixl_y + (cosf(game->map->angle) * -i);
// 	    }
// 	    else if (game->map->palyer == 'W')
// 	    {
// 	    	new_x = game->player_pixl_x + (cosf(game->map->angle) * -i);
// 	    	new_y = game->player_pixl_y + (sinf(game->map->angle) * -i);
// 	    }
// 	    else if (game->map->palyer == 'E')
// 	    {
// 	    	new_x = game->player_pixl_x + (cosf(game->map->angle) * i);
// 	    	new_y = game->player_pixl_y + (sinf(game->map->angle) * i);
// 	    }
//         put_pixel(game, new_x, new_y, 0x00FFFF00);
//         if (game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1'
// 		    && game->map->grid[new_y / SIZE][new_x / SIZE] == '1' || game->map->grid[new_y / SIZE][new_x / SIZE] == '1')
// 	    	break ;
//         i++;
//     }
// }
