/*
** cone.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 17:19:54 2017 Joubert Miguel
** Last update Sat Mar 18 13:02:53 2017 Joubert Miguel
*/

#include "../include/my.h"

t_attributs		get_cone(t_attributs att)
{
  att.color.b = 255;
  att.color.a = 255;
  att.color.r =0;
  att.color.g =0;
  att.eye_pos.x = -1000;
  att.eye_pos.y = 0;
  att.eye_pos.z = 0;
  att.dist_to_plane = 100;
  att.screen_size.x = 850;
  att.screen_size.y = 650;
  att.screen_pos.x = 0;
  att.screen_pos.y = 0;
  att.light_vector.x = 100;
  att.light_vector.y = 10;
  att.light_vector.z = 0;
  att.semiangle = 20;
  att.limit_top = 150;
  att.limit_bottom = -150;
  return (att);
}

float			intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
				       float semiangle)
{
  t_delta			dis;

  if (semiangle == 90.0f) return (-1);
  semiangle = (semiangle * M_PI) / 180.0f;
  dis.a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0)
    - pow(dir_vector.z, 2.0) * pow(tan(semiangle), 2.0);
  dis.b = 2 * (eye_pos.x * dir_vector.x) + 2 *
    (eye_pos.y * dir_vector.y) - 2 *
    (eye_pos.z * dir_vector.z * pow(tan(semiangle), 2.0));
  dis.c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) - pow(eye_pos.z, 2.0) *
    pow(tan(semiangle), 2.0);
  dis.delta = pow(dis.b, 2.0) - 4 * dis.a * dis.c;
  if (dis.delta < 0 || (dir_vector.x == 0 && dir_vector.y == 0)) return (-1);
  else if (dis.delta == 0) return (-dis.b / (2.0 * dis.a));
  else
    {
      dis.x1 = (-dis.b + sqrt(dis.delta)) / (2.0 * dis.a);
      dis.x2 = (-dis.b - sqrt(dis.delta)) / (2.0 * dis.a);
    }
  if (dis.x1 < dis.x2 && dis.x1 > 0) return (dis.x1);
  else if (dis.x1 < 0 && dis.x2 > 0) return (dis.x2);
  else if (dis.x2 < dis.x1 && dis.x2 > 0) return (dis.x2);
  else if (dis.x2 < 0 && dis.x1 > 0) return (dis.x1);
  else if (dis.x2 < 0 && dis.x1 < 0) return (-1);
  return (0);
}

sfVector3f		get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  semiangle = (semiangle * M_PI) / 180.0f;
  intersection_point.z = -intersection_point.z * tan(semiangle);
  return (intersection_point);
}

void			radius_loop_cone(t_attributs att, t_my_framebuffer *framebuffer)
{
  while (att.screen_pos.y != att.screen_size.y)
    {
      while (att.screen_pos.x != att.screen_size.x)
	{
	  att.dir_eye_vector =
	    calc_dir_vector(att.dist_to_plane, att.screen_size, att.screen_pos);
	  if ((att.dist_to_light =
	       intersect_cone(att.eye_pos, att.dir_eye_vector, att.semiangle)) > 0)
	    {
	      att.intersection_point =
		calc_dir_vector(att.dist_to_light, att.screen_size, att.screen_pos);
	      att.normal = get_normal_cone(att.intersection_point, att.semiangle);
	      att.color.b *= get_light_coef(att.light_vector, att.normal);
	      if (att.intersection_point.z <= att.limit_top
		  && att.intersection_point.z >= att.limit_bottom)
		my_put_pixel(framebuffer, att.screen_pos.x, att.screen_pos.y, att.color);
	    }
	  att.color.b = 255;
	  att.screen_pos.x++;
	}
      att.screen_pos.x = 0;
      att.screen_pos.y++;
    }
}

void			drawing_cone(sfRenderWindow *window, sfSprite *sprite,
				     t_my_framebuffer *framebuffer)
{
  sfTexture		*texture;
  t_attributs		att;

  att = get_cone(att);
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  radius_loop_cone (att, framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}
