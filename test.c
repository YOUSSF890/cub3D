a_y = y/ SIZE;
	b_x = (x - 4) / SIZE;
	c_y = y/ SIZE;
	d_x = (x - 4) / SIZE;
	t_y = y/ SIZE;
	r_x = (x + 4) / SIZE;
	m_y = y/ SIZE;
	n_x = (x + 4) / SIZE;

	else if (game->map->grid[(int)y/ SIZE][(int)(x - 4) / SIZE] != '1' && game->map->grid[(int)y/ SIZE][(int)(x - 4) / SIZE] != '1'
		&& game->map->grid[(int)y/ SIZE][(int)(x + 4) / SIZE] != '1' && game->map->grid[(int)y/ SIZE][(int)(x + 4) / SIZE] != '1' && (key == KEY_W || key == KEY_S))
	{
		game->player_pixl_x = x;
	}
	a_y = (y - 4) / SIZE;
	b_x = x / SIZE;
	c_y = (y + 4) / SIZE;
	d_x = x / SIZE;
	t_y = (y - 4) / SIZE;
	r_x = x / SIZE;
	m_y = (y + 4) / SIZE;
	n_x = x / SIZE;
	else if (game->map->grid[(int)(y - 4) / SIZE][(int) x / SIZE] != '1' && game->map->grid[(int)(y + 4) / SIZE][(int)x / SIZE] != '1'
		&& game->map->grid[(int)(y - 4) / SIZE][(int)x / SIZE] != '1' && game->map->grid[(int)(y + 4) / SIZE][(int)x / SIZE] != '1' && (key == KEY_W || key == KEY_S))
	{
		game->player_pixl_y = y;
	}