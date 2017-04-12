/*
** game.c for  in /home/joubert/delivery/raytracer1/bonus
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Mar 19 17:56:25 2017 Joubert Miguel
** Last update Mon Mar 20 01:52:10 2017 Joubert Miguel
*/

#include "../include/my.h"

static int		collision(sfVector2f co_pipe, sfVector2f co_mario)
{
  if ((co_pipe.x <= 130 && co_pipe.x >= 50) && co_mario.y > 490)
    return (1);
  if ((co_pipe.x == -70 && co_pipe.x >= -150) && co_mario.y > 490)
    return (1);
  if ((co_pipe.x == -270 && co_pipe.x >= -350) && co_mario.y > 490)
    return (1);
  return (0);
}

static t_attributs	get_co_game(t_attributs att)
{
  att.color.g = 100;
  att.color.a = 255;
  att.color.r = 0;
  att.color.g = 0;
  att.eye_pos.x = -1000;
  att.eye_pos.y = 0;
  att.eye_pos.z = 200;
  att.dist_to_plane = 200;
  att.screen_size.x = 850;
  att.screen_size.y = 650;
  att.screen_pos.x = 0;
  att.screen_pos.y = 0;
  att.light_vector.x = 1000;
  att.light_vector.y = 200;
  att.light_vector.z = 0;
  att.semiangle = 100;
  att.limit_top = -250;
  att.limit_bottom = -450;
  return (att);
}

t_cond			ret_conds(int jump, t_attributs *att,
				  t_my_framebuffer *framebuffer, sfRenderWindow *window)
{
  static t_cond         cond;

  if (jump == 2)
    cond.i = cond.draw = cond.reset = 0;
  cond.sprite_pos.y = 0;
  cond.mario_pos.x = 70;
  if (cond.i == 0) {
    cond.mario_pos.y = SCREEN_HEIGHT - 90;
    cond.i++;
  }
  if (jump == 1 && cond.mario_pos.y > 410)
    cond.mario_pos.y -= 150;
  else if (cond.mario_pos.y != SCREEN_HEIGHT - 90)
    cond.mario_pos.y += 10;
  if (cond.reset == 0) {
    cond.reset = 1;
    cond.sprite_pos.x = 800;
  }
  else if (cond.sprite_pos.x > -500 && cond.reset == 1)
    cond.sprite_pos.x -= 10;
  else if (cond.sprite_pos.x <= -500 && cond.reset == 1)
    cond.reset = 0;
  if (cond.draw == 0) {
    *att = get_co_game(*att);
    sfRenderWindow_clear(window, sfBlack);
    radius_loop_cylinder(*att, framebuffer);
    cond.draw++;
  }
  return (cond);
}

int			hardgame(sfRenderWindow *window, sfSprite *pipe1,
				 t_my_framebuffer *framebuffer, int jump)
{
  t_cond		cond;
  sfSprite              *spr_mario;
  sfTexture             *tx_pipe1;
  sfTexture             *mario;
  t_attributs           att;

  cond = ret_conds(jump, &att, framebuffer, window);
  mario = sfTexture_createFromFile("rsrcs/mario.jpg", NULL);
  tx_pipe1 = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  spr_mario = sfSprite_create();
  sfSprite_setTexture(pipe1, tx_pipe1, sfTrue);
  sfSprite_setTexture(spr_mario, mario, sfTrue);
  sfTexture_updateFromPixels(tx_pipe1, framebuffer->pixels,
  			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfTexture_updateFromPixels(mario, framebuffer->pixels,
			     0, 0, 50, 50);
  skip_all_pixels(framebuffer, tx_pipe1);
  if (collision(cond.sprite_pos, cond.mario_pos) == 1)
    return (1);
  sfSprite_setPosition(spr_mario, cond.mario_pos);
  sfSprite_setPosition(pipe1, cond.sprite_pos);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, pipe1, NULL);
  sfRenderWindow_drawSprite(window, spr_mario, NULL);
  sfRenderWindow_display(window);
  return (0);
}
