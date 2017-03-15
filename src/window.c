/*
** window.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 14 18:23:37 2017 Joubert Miguel
** Last update Wed Mar 15 01:20:49 2017 Joubert Miguel
*/

#include "../include/my.h"

void		clear_all_pixels(t_my_framebuffer *framebuffer)
{
  int		i;
  int		j;

  i = j = 0;
  while (i <= SCREEN_WIDTH)
    {
      while (j < SCREEN_HEIGHT / 2)
	{
	  my_put_pixel(framebuffer, i, j, sfBlack);
	  j++;
	}
      while (j <= SCREEN_HEIGHT)
	{
	  my_put_pixel(framebuffer, i, j, sfWhite);
	  j++;
	}
      j = 0;
      i++;
    }
}

int		open_window(sfRenderWindow *window, sfSprite *sprite,
			    t_my_framebuffer *framebuffer)
{
  sfEvent       event;

  sfRenderWindow_setFramerateLimit(window, 30);
  if (!window)
    return (84);
  while (sfRenderWindow_isOpen(window))
    {
      clear_all_pixels(framebuffer);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(window);
	}
      drawing_cone(window, sprite, framebuffer);
    }
  return (0);
}
