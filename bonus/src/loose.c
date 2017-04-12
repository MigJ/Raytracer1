/*
** loose.c for  in /home/joubert/delivery/raytracer1/bonus
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Mar 19 23:58:53 2017 Joubert Miguel
** Last update Mon Mar 20 01:55:59 2017 Joubert Miguel
*/

#include "../include/my.h"

int		loose_menu(t_my_framebuffer *framebuffer)
{
  sfVideoMode           mode = {850, 650, 32};
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  sfFont                *font;
  sfEvent               event;
  sfText                *message;
  sfVector2f		pos;
  char			*str;

  if ((str = malloc(sizeof(char) * 40)) == NULL)
    return (84);
  str =
    "Vous avez perdu !\nPour rejouer, pressez la touche ESPACE.\nPour quitter, pressez la touche ECHAP..\n";
  pos.x = 100;
  pos.y = 100;
  window = sfRenderWindow_create(mode, "Raytracer 1", sfResize | sfClose, NULL);
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  font = sfFont_createFromFile("rsrcs/stocky.ttf");
  message = sfText_create();
  sfText_setString(message, str);
  sfText_setFont(message, font);
  sfText_setCharacterSize(message, 20);
  sfText_setPosition(message, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_drawText(window, message, NULL);
  sfRenderWindow_display(window);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
	    sfSprite_destroy(sprite);
	    sfTexture_destroy(texture);
	    sfFont_destroy(font);
	    sfText_destroy(message);
	    sfRenderWindow_close(window);
	    sfRenderWindow_destroy(window);
	    return (1);
	  }
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
	    sfSprite_destroy(sprite);
	    sfTexture_destroy(texture);
	    sfFont_destroy(font);
	    sfText_destroy(message);
	    sfRenderWindow_close(window);
	    sfRenderWindow_destroy(window);
	    return (2);
		    
	  }
	}
    }
  return (free(str), 0);
}
