/*
** main.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 14 18:14:54 2017 Joubert Miguel
** Last update Sat Mar 18 02:03:18 2017 Joubert Miguel
*/

#include "../include/my.h"

int		main()
{
  sfVideoMode   mode = {850, 650, 32};
  sfRenderWindow        *window;
  t_my_framebuffer      *framebuffer;
  sfTexture     *texture;
  sfSprite      *sprite;
  int		what;

  if ((framebuffer = malloc(sizeof(*framebuffer))) == NULL)
    return (84);
  what = load();
  window = sfRenderWindow_create(mode, "Raytracer 1", sfResize | sfClose, NULL);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  framebuffer = create_pixel_buffer();
  sfSprite_setTexture(sprite, texture, sfTrue);
  open_window(window, sprite, framebuffer, what);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (0);
}
