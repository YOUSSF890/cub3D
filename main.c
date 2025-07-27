/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:11:48 by hkhairi           #+#    #+#             */
/*   Updated: 2025/07/26 17:03:00 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./cub.h"

int main(int argc, char *argv[])
{
    t_game *game;
    void *mlx_ptr;
    void *win_ptr;

    game = malloc(sizeof(t_game));
    if (!game)
        return (1);
    if (!init_struct(game))
        return (0);
    if (!start_parcing(argc, argv, game))
        return (0);
    if (!start_randering(game))
        return (0);
    // free_game(game);
    return (0);
}


// typedef struct s_data {
//     void    *img;
//     char    *addr;
//     int     bits_per_pixel;
//     int     line_length;
//     int     endian;
// }               t_data;

// void    put_pixel(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     // printf("y = %d  \\  data->line_length = %d  \\\\\  x= %d \\\\ data->bits_per_pixel = %d\n",y + data->line_length , x , data->bits_per_pixel);
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// int main(void)
// {
//     void    *mlx;
//     void    *win;
//     t_data  img;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "MLX Image Example");
    
//     // Create image
//     img.img = mlx_new_image(mlx, 400, 300);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
//                                 &img.line_length, &img.endian);
    
//     // Draw to image - simple gradient
//     int y = 0;
//     while (y < 32)
//     {
//         int x = 0;
//         while (x < y)
//         {
//             printf("====%d\n",32 / 2 - y / 2 + x);
//             put_pixel(&img, 32 / 2 - y / 2 + x, y, 0x00FF0000);
//             x++;
//         }
//         y++;
//     }
    
//     // Display image in window
//     mlx_put_image_to_window(mlx, win, img.img, 200, 150);
//     mlx_loop(mlx);
//     return (0);
// }
