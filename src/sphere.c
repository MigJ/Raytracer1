/*
** sphere.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 15:44:19 2017 Joubert Miguel
** Last update Wed Mar 15 11:52:36 2017 Joubert Miguel
*/

#include "../include/my.h"

t_attributs		get_sphere(t_attributs att)
{
  att.color.r = 255;
  att.color.a = 255;
  att.color.r = 0;
  att.color.g = 0;
  att.eye_pos.x = -1000;
  att.eye_pos.y = 0;
  att.eye_pos.z = 0;
  att.dist_to_plane = 400;
  att.screen_size.x = 550;
  att.screen_size.y = 450;
  att.screen_pos.x = 0;
  att.screen_pos.y = 0;
  att.light_vector.x = 20;
  att.light_vector.y = 15;
  att.light_vector.z = 20;
  return (att);
}

float			intersect_sphere(sfVector3f eye_pos,
					 sfVector3f dir_vector, float radius)
{
  t_delta			dis;

  dis.a = pow(dir_vector.x, 2.0) +
    pow(dir_vector.y, 2.0) + pow(dir_vector.z, 2.0);
  dis.b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y *
	       dir_vector.y + eye_pos.z * dir_vector.z);
  dis.c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) +
    pow(eye_pos.z, 2.0) - pow(radius, 2.0);
  dis.delta = pow(dis.b, 2.0) - 4.0 * dis.a * dis.c;
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

sfVector3f		get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f		norm;

  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = intersection_point.z;
  return (norm);
}

void			radius_loop(t_attributs att, t_my_framebuffer *framebuffer)
{
  while (att.screen_pos.y != att.screen_size.y)
    {
      while (att.screen_pos.x != att.screen_size.x)
	{
	  att.dir_eye_vector =
	    calc_dir_vector(att.dist_to_plane, att.screen_size, att.screen_pos);
	  if ((att.dist_to_light =
	       intersect_sphere(att.eye_pos, att.dir_eye_vector, 200)) > 0)
	    {
	      att.intersection_point =
		calc_dir_vector(att.dist_to_light, att.screen_size, att.screen_pos);
	      att.normal = get_normal_sphere(att.intersection_point);
	      att.color.r *= get_light_coef(att.light_vector, att.normal);
	      my_put_pixel(framebuffer, att.screen_pos.x, att.screen_pos.y, att.color);
	    }
	  att.color.r = 255;
	  att.screen_pos.x++;
	}
      att.screen_pos.x = 0;
      att.screen_pos.y++;
    }
}

void			drawing_sphere(sfRenderWindow *window, sfSprite *sprite,
				       t_my_framebuffer *framebuffer)
{
  sfTexture		*texture;
  t_attributs		att;

  att = get_sphere(att);
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  radius_loop(att, framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}
