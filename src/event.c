/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:54:18 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 21:23:12 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int	relesse_key(int key, t_game *game)
{
	if (key == 88)//6
		game->paddle1->m_u = 0;
	if (key == 85)//3
		game->paddle1->m_d = 0;
	if (key == 13)//w
		game->paddle2->m_u = 0;
	if (key == 1)//s
		game->paddle2->m_d = 0;
	if (key == 126)
		game->m_u = 0;
	if (key == 125)
		game->m_d = 0;
	if (key == 124)
		game->m_r = 0;
	if (key == 123)
		game->m_l = 0;
	return (0);
}

int	presse_key(int key, t_game *game)
{
	if (key == 35 && game->pos == 0)
		game->pos = 1;
	else if (key == 35 && game->pos == 1)
		game->pos = 0;
	// if (key == 49)
	// 	game->lose = 0;
	if (key == 88)//6
		game->paddle1->m_u = 1;
	if (key == 85)//3
		game->paddle1->m_d = 1;
	if (key == 13)//w
		game->paddle2->m_u = 1;
	if (key == 1)//s
		game->paddle2->m_d = 1;
	if (key == 69 && game->speed < 40)
		game->speed +=  1;
	if (key == 78 && game->speed > 1)
		game->speed -=  1;
	if (key == 126)
		game->m_u = 1;
	if (key == 125)
		game->m_d = 1;
	if (key == 124)
		game->m_r = 1;
	if (key == 123)
		game->m_l = 1;
	if (key == 53)
		ft_exit();
	return (0);
}

int	mouse_event(int x, int y, t_game *game)
{
	if (x > 80 && x < 600 && y > 394 && y < 560){
		game->im_start = game->im_start2;
		game->restart1 = game->restart1;
		game->restart2 = game->restart2_2;
	}
	else{
		game->im_start = game->im_start1;
		game->restart1 = game->restart1_1;
		game->restart2 = game->restart2_1;
	}

	return (0);
}

int		mouse_presse(int key, int x, int y, t_game *game)
{
	if (!game->lose)
		return (0);
	if (key == 1 && x > 80 && x < 600 && y > 394 && y < 560){

		game->start = 1;
		game->restart = 1;
		game->lose = 0;
		game->pos = 0;
	}
	return (0);
}
