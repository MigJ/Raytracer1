/*
** my_put_pixel.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Jan  2 22:19:32 2017 Joubert Miguel
** Last update Wed Mar 15 01:25:47 2017 Joubert Miguel
*/

#include "../include/my.h"

t_my_framebuffer	*create_pixel_buffer()
{
  int	i;
  t_my_framebuffer	*framebuffer;

  if ((framebuffer = malloc(sizeof(*framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = SCREEN_WIDTH;
  framebuffer->height = SCREEN_HEIGHT;
  if ((framebuffer->pixels = malloc(framebuffer->width *
				    framebuffer->height * 4 *
				    sizeof(*framebuffer->pixels) * 2)) == NULL)
    return (NULL);
  if (framebuffer->pixels == NULL)
    exit(84);
  i = 0;
  while (i < framebuffer->width * framebuffer->height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer);
}

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4] = color.r;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = color.a;
}
