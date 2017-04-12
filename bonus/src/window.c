/*
** window.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 14 18:23:37 2017 Joubert Miguel
** Last update Mon Mar 20 01:54:58 2017 Joubert Miguel
*/

#include "../include/my.h"

void		skip_all_pixels(t_my_framebuffer *framebuffer, sfTexture *texture)
{
  static int	i;
  sfVector2i	co;
  sfImage       *image;
  sfColor	color;

  if (i == 1)
    return;
  i++;
  image = sfTexture_copyToImage(texture);
  co.x = co.y = 0;
  while (co.x < SCREEN_WIDTH)
    {
      while (co.y < SCREEN_HEIGHT)
	{
	  color = sfImage_getPixel(image, co.x, co.y);
	  if (color.g != 0) {
	    my_put_pixel(framebuffer, co.x - 200, co.y, color);
	    my_put_pixel(framebuffer, co.x - 400, co.y, color);
	  }
	  co.y++;
	}
      co.y = 0;
      co.x++;
    }
}

void		clear_all_pixels(t_my_framebuffer *framebuffer)
{
  int		i;
  int		j;

  i = j = 0;
  while (i <= SCREEN_WIDTH)
    {
      while (j < SCREEN_HEIGHT)
	{
	  my_put_pixel(framebuffer, i, j, sfBlack);
	  j++;
	}
      j = 0;
      i++;
    }
}

int		open_window(sfRenderWindow *window, sfSprite *sprite,
			    t_my_framebuffer *framebuffer, int what)
{
  sfEvent       event;
  int		game;
  int		jump;
  int		loose;

  loose = jump = game = 0;
  sfRenderWindow_setFramerateLimit(window, 30);
  if (!window)
    return (84);
  clear_all_pixels(framebuffer);
  while (sfRenderWindow_isOpen(window))
    {
      jump = 0;
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && game != 1) {
	    clear_all_pixels(framebuffer);
	    game = 1;
	  }
	  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	    jump = 1;
	}
      if (loose == 1) {
	loose_menu(framebuffer);
	loose = 0;
	jump = 2;
      }
      if (what == 0 && game == 0)
	drawing_cylinder(window, sprite, framebuffer);
      else if (what == 1 && game == 0)
	drawing_cone(window, sprite, framebuffer);
      else if (game == 0)
	drawing_sphere(window, sprite, framebuffer);
      else
	loose = hardgame(window, sprite, framebuffer, jump);
    }
  return (0);
}
