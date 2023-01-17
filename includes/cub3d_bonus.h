/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:39:19 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 16:39:22 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

# define SNOW_1 "./texture/snow_1.xpm"
# define SNOW_2 "./texture/snow_2.xpm"
# define SNOW_3 "./texture/snow_3.xpm"

int		minimap(t_info *info);
int		extra_key(int key, t_info *info);
int		rain(t_info *info);
void	set_mlx_texture(t_info *info);
int		cal_render_bonus(void *ptr);
void	render_bonus(t_img_data *img, t_info *info);

#endif