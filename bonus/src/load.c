/*
** load.c for  in /home/joubert/delivery/raytracer1/bonus
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar 17 23:03:43 2017 Joubert Miguel
** Last update Mon Mar 20 00:14:58 2017 Joubert Miguel
*/

#include "../include/my.h"

int		choose_text(char *str, sfVector2f positions, sfText **object, sfFont **font)
{
  *font = sfFont_createFromFile("rsrcs/stocky.ttf");
  *object = sfText_create();
  sfText_setString(*object, str);
  sfText_setFont(*object, *font);
  sfText_setCharacterSize(*object, 50);
  sfText_setPosition(*object, positions);
  return (0);
}

int			load()
{
  sfVideoMode		mode = {1200, 700, 32};
  sfRenderWindow        *window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfVector2f		pos_cylinder;
  sfText		*underline;
  sfText		*cylinder;
  sfVector2f		pos_cone;
  sfText                *cone;
  sfVector2f            pos_sphere;
  sfText                *sphere;
  sfFont                *font;
  sfEvent		event;
  int			what;

  what = 0;
  pos_cylinder.x = 130;
  pos_cylinder.y = 350;
  pos_cone.x = 550;
  pos_cone.y = 250;
  pos_sphere.x= 860;
  pos_sphere.y= 350;
  window = sfRenderWindow_create(mode, "Raytracer 1", sfResize | sfClose, NULL);
  texture = sfTexture_createFromFile("rsrcs/load.jpg", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  choose_text("CYLINDER", pos_cylinder, &cylinder, &font);
  choose_text("CONE", pos_cone, &cone, &font);
  choose_text("SPHERE", pos_sphere, &sphere, &font);
  underline = cylinder;
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
	    what = (what != 0) ? what - 1 : 0;
	  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
	    what = (what != 2) ? what + 1 : 2;
          if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue)
	    sfRenderWindow_close(window);
	}
      if (what == 0)
	underline = cylinder;
      else if (what == 1)
	underline = cone;
      else
	underline = sphere;
      sfText_setColor(cylinder, sfWhite);
      sfText_setColor(cone, sfWhite);
      sfText_setColor(sphere, sfWhite);
      sfText_setColor(underline, sfRed);
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_drawText(window, cylinder, NULL);
      sfRenderWindow_drawText(window, cone, NULL);
      sfRenderWindow_drawText(window, sphere, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_close(window);
  sfFont_destroy(font);
  sfText_destroy(cylinder);
  sfText_destroy(cone);
  sfText_destroy(sphere);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (what);
}
