/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:21:40 by tfedoren          #+#    #+#             */
/*   Updated: 2022/12/06 20:14:31 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>
#include <string.h>
#include <vector.h>
// #include <iostream.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// int main(int argc, char *argv[])
int render(t_cub3d *cub3d)
{
  
  // t_mlx *data;
	double posX = 22; // x and y start position
	double posY = 12;
	double dirX = -1; // initial direction position
	double dirY = 0;
	double planeX = 0; //the 2d raycaster version of camera plane
	double planeY = 0;

	double time = 0; // time of current frame
	double oldTime = 0; // time of previous frame

	// data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Our amazing 3D game");
  // screen(screenWidth, screenHeight, 0, "Raycaster");
  
  while(1)
  {
    for(int x = 0; x < screenWidth; x++)
    {
      double cameraX = 2 * x / ((double)(screenWidth) - 1);
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

      int mapX = (int)(posX);
      int mapY = (int)(posY);

      double sideDistX;
      double sideDistY;

      double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1/rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1/rayDirY);
      double perpWallDist;
      
      int stepX;
      int stepY;

      int hit = 0;
      int side;
      
      //calculate  step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 

      
      //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) 
        perpWallDist = (sideDistX - deltaDistX);
      else          
        perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(screenHeight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0)
        drawStart = 0;

      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawEnd >= screenHeight) 
        drawEnd = screenHeight - 1;

      //choose wall color
      // ColorRGB color;
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 0xe80c0c;  break;
        case 2:  color = 0x8A2BE2;  break;
        case 3:  color = 0xF08080;   break;
        case 4:  color = 0x800080;  break;
        default: color = 0xffffff; break;
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      // verLine(x, drawStart, drawEnd, color);
      draw_line(cub3d, x, color);
    }
    // here raycasting loop suppose to be done

    // timing for input and FPs counter

    oldTime = time;
    time = getTicks();
    double frameTime = (time = oldTime); //frame time is the time this frame has taken, in seconds
    print(frameTime);
    redraw();
    cls();
    
    //speed modifiers
    double moveSpeed = frameTime * 5.0;
    double rotSpeed = frameTime * 3.0;

    //key handling
    readKeys();
    
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[(int)(posX +dirX*moveSpeed)][(int)posY] == false)
        posX += dirX * moveSpeed;
      if(worldMap[(int)posX][(int)(posY + dirY + moveSpeed)] == false)
        posY +=dirY*moveSpeed;
    }
    //more backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[(int)(posX - dirX*moveSpeed)][(int)posY] == false)
        posX -=dirX * moveSpeed;
      if(worldMap[(int)posX][(int)(posY - dirY * moveSpeed) == false])
        posY -=dirY * moveSpeed;
    }
    
    //rotate to right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera directions and camera plane must be rorated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    
    //rotate to left
    if (keyDown(SDLK_LEFT))
    {
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }
}
